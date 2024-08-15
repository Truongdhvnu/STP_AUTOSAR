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