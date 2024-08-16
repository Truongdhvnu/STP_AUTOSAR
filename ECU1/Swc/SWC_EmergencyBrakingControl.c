#include "Rte.h"
#include "Rte_appComTxRx.h"

typedef enum  
{
    EMERGENCY_BRAKING_SERVICE_OFF,
    EMERGENCY_BRAKING_SERVICE_ON
} Emergency_Braking_Service_Status;

typedef enum
{
    EMERGENCY_BRAKING_INACTIVE,
    EMERGENCY_BRAKING_ACTIVE
} Emergency_Braking_Status;

VAR(Emergency_Braking_Service_Status, AUTOMATIC) AEB_status = EMERGENCY_BRAKING_SERVICE_ON;
VAR(Emergency_Braking_Status, AUTOMATIC) AEB_active = EMERGENCY_BRAKING_INACTIVE;

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : DetermineBrakingAction                                        */
/* Trigger     :                                                               */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : void                                                          */
/* Contents    : Determines the braking action based on distance data and      */
/*               vehicle speed.                                                */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function retrieves distance data, calculates the braking */
/*               force needed based on distance and speed, and updates the     */
/*               braking force accordingly.                                    */
/*******************************************************************************/
FUNC(void, DetermineBrakingAction_CODE) DetermineBrakingAction(VAR(void, AUTOMATIC) ) 
{   
    Rte_Call_WdgMCheckpointReached(SE2_ID, CP_ID_5);
    Rte_Call_WdgMCheckpointReached(SE2_ID, CP_ID_1);

    /*
        if the service is acite:
        Call RTE Port API to get distance/velocity data
        Then Determine braking action required, eg. by an algorithm
    */
	if (AEB_status == EMERGENCY_BRAKING_SERVICE_ON) 
    {
        VAR(AUTOSAR_uint16, AUTOMATIC) velocity;
        VAR(AUTOSAR_uint16, AUTOMATIC) distance;

        VAR(AUTOSAR_float32, AUTOMATIC) reaction_time;
        VAR(AUTOSAR_float32, AUTOMATIC) adjustment_factor;
        VAR(AUTOSAR_float32, AUTOMATIC) d_min;
        VAR(AUTOSAR_float32, AUTOMATIC) d_safe;
        VAR(AUTOSAR_float32, AUTOMATIC) force_brake;

        // Read Distance (cm) via R-Port
        Rte_Read_RP_AEB_Distance_Distance(&distance);
        // Read Velocity (cm/s) via R-Port
        Rte_Call_R_IoHwAb_GetSpeed(&velocity);

        reaction_time = 1.0;
        // High factor for high speed, low factor for low speed
        adjustment_factor = pow(2, velocity/1000);
        d_min = velocity * reaction_time;
        d_safe = adjustment_factor * d_min;

        if (distance > d_safe) 
        {
            force_brake = 0;
            AEB_active = EMERGENCY_BRAKING_INACTIVE;
        } 
        else 
        {
            if (distance > d_min) 
            {
                force_brake = 100 * (1 - (distance / d_safe));
            } 
            else 
            {
                force_brake = 100;
            }
            AEB_active = EMERGENCY_BRAKING_ACTIVE;
        } 

        // Limit force_brake in valid range
        if (force_brake < 0) 
        {
            force_brake = 0;
        }
        else
        {
            force_brake = 100;
        }

        Rte_Write_RP_AEB_Apply_Apply(&force_brake);
    }

    Rte_Call_WdgMCheckpointReached(SE2_ID, CP_ID_2); 	
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : ActivateEmergencyBraking                                      */
/* Trigger     :                                                               */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : void                                                          */
/* Contents    : Activates the emergency braking system by setting the AEB     */
/*               status to EMERGENCY_BRAKING_SERVICE_ON.                       */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function updates the AEB status to indicate that the     */
/*               emergency braking service is active.                          */
/*******************************************************************************/
FUNC(Std_ReturnType, ActivateEmergencyBraking_CODE) ActivateEmergencyBraking(VAR(void, AUTOMATIC) ) 
{   
    AEB_status = EMERGENCY_BRAKING_SERVICE_ON;
    
    return E_OK;
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : DeActivateEmergencyBraking                                    */
/* Trigger     :                                                               */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : void                                                          */
/* Contents    : Deactivates the emergency braking system by setting the AEB   */
/*               status to EMERGENCY_BRAKING_SERVICE_OFF.                      */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function updates the AEB status to indicate that the     */
/*               emergency braking service is inactive.                        */
/*******************************************************************************/
FUNC(Std_ReturnType, DeActivateEmergencyBraking_CODE) DeActivateEmergencyBraking(VAR(void, AUTOMATIC) ) 
{   
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    if (AEB_active == EMERGENCY_BRAKING_ACTIVE) 
    {
        ret_val = E_NOT_OK;
    }
    else
    {
        AEB_status = EMERGENCY_BRAKING_SERVICE_OFF;
    }

    return ret_val;
}
