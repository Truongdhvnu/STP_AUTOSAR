#include "Rte.h"
#include "Rte_appComTxRx.h"

typedef enum  
{
    EMERGENCY_BRAKING_SERVICE_OFF,
    EMERGENCY_BRAKING_SERVICE_ON
} Emergency_Braking_Service_Status;

static Emergency_Braking_Service_Status AEB_status = EMERGENCY_BRAKING_SERVICE_ON;

static bool ParameterInitSuccessful = 0; 

static AEB_UserConfig AEB_UserConfig;

FUNC(void, DetermineBrakingAction_CODE) InitParameter(VAR(void, AUTOMATIC) ) 
{
    Rte_Call_NvM_Service_ReadBlock(AEB_UserConfig_ID, (void*) AEB_UserConfig);

}

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
        Call RTE Port API to get distance data
        Then Determine braking action required, eg. by an algorithm
    */
	if (AEB_status == EMERGENCY_BRAKING_SERVICE_ON) {
        VAR(AUTOSAR_uint16, AUTOMATIC) velocity;  
        VAR(AUTOSAR_uint16, AUTOMATIC) distance;

        VAR(AUTOSAR_float32, AUTOMATIC) reaction_time;
        VAR(AUTOSAR_float32, AUTOMATIC) adjustment_factor;
        VAR(AUTOSAR_float32, AUTOMATIC) d_min;
        VAR(AUTOSAR_float32, AUTOMATIC) d_safe;
        VAR(AUTOSAR_float32, AUTOMATIC) force_brake;

        // Read Distance (cm) via R-Port
        Rte_Read_RP_AEB_Distance_Distance(&distance);
        // Read Distance (cm/s) via R-Port
        Rte_Call_R_IoHwAb_GetSpeed(&velocity);

        reaction_time = 1.0;
        // High factor for high speed, low factor for low speed
        adjustment_factor = pow(2, velocity/1000);
        d_min = velocity * reaction_time;
        d_safe = adjustment_factor * d_min;

        if (distance > d_safe) {
            force_brake = 0;
        } else if (distance > d_min) {
            force_brake = 100 * (1 - (distance / d_safe));
        } else {
            force_brake = 100;
        }

        // Limit force_brake in range of 0 - 100
        force_brake = (force_brake < 0) ? 0 : ((force_brake > 100) ? 100 : force_brake);

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
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;
    
    if (ParameterInitSuccessful) 
    {
        AEB_status = EMERGENCY_BRAKING_SERVICE_ON;
    } else 
    {
        ret_val = E_NOT_OK
    }

    return ret_val;
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

    AEB_status = EMERGENCY_BRAKING_SERVICE_OFF;

    return ret_val;
}
