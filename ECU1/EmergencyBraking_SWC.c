#include "Rte.h"
#include "Rte_appComTxRx.h"

typedef enum  
{
    EMERGENCY_BRAKING_SERVICE_OFF,
    EMERGENCY_BRAKING_SERVICE_ON
} Emergency_Braking_Service_Status;

static Emergency_Braking_Service_Status AEB_status = EMERGENCY_BRAKING_SERVICE_ON;


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
        Rte_Read_RP_AEB_Distance_Distance(&distance);
        float reaction_time = 1.0;
        float adjustment_factor = (velocity > 80) ? 2.0 : 1.5;  // Hệ số điều chỉnh, 2 cho tốc độ cao, 1.5 cho tốc độ thấp
        float d_min = velocity * reaction_time;
        float d_safe = adjustment_factor * d_min;
        float force_brake;

        if (distance > d_safe) {
            force_brake = 0;
        } else if (distance > d_min) {
            force_brake = 100 * (1 - (distance / d_safe));
        } else {
            force_brake = 100;
        }

        // Giới hạn force_brake trong khoảng 0 - 100
        force_brake = (force_brake < 0) ? 0 : ((force_brake > 100) ? 100 : force_brake);
    }

    Rte_Call_WdgMCheckpointReached(SE2_ID, CP_ID_2); 	
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : ExecuteBraking                                                */
/* Trigger     :                                                               */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : void                                                          */
/* Contents    : Executes the braking action by applying the required braking  */
/*               force based on the logic defined. Updates watchdog checkpoints*/
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function calls RTE ports to apply the braking force      */
/*               and updates the watchdog checkpoints accordingly.             */
/*******************************************************************************/
FUNC(void, ExecuteBraking_CODE) ExecuteBraking(VAR(void, AUTOMATIC) ) 
{
	Rte_Call_WdgMCheckpointReached(SE3_ID, CP_ID_3);

    /*
        Call RTE Port to braking action required
        Then Execute logic and apply braking force accordingly
    */

    Rte_Call_WdgMCheckpointReached(SE3_ID, CP_ID_4);
    Rte_Call_WdgMCheckpointReached(SE3_ID, CP_ID_6);
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
FUNC(void, ActivateEmergencyBraking_CODE) ActivateEmergencyBraking(VAR(void, AUTOMATIC) ) 
{
    AEB_status = EMERGENCY_BRAKING_SERVICE_ON;
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : DeActivateEmergencyBraking                                     */
/* Trigger     :                                                               */
/* Param       : VAR(void, AUTOMATIC)                                           */
/* Return      : void                                                           */
/* Contents    : Deactivates the emergency braking system by setting the AEB    */
/*               status to EMERGENCY_BRAKING_SERVICE_OFF.                        */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function updates the AEB status to indicate that the       */
/*               emergency braking service is inactive.                         */
/*******************************************************************************/
FUNC(void, DeActivateEmergencyBraking_CODE) DeActivateEmergencyBraking(VAR(void, AUTOMATIC) ) 
{
    AEB_status = EMERGENCY_BRAKING_SERVICE_OFF;
}
