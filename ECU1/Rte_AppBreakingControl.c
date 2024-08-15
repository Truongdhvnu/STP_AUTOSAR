VAR(AUTOSAR_uint8, AUTOMATIC) Rte_AEB_Apply_value;

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Write_PP_AEB_Apply_Apply                                  */
/* Trigger     :                                                               */
/* Param       : VAR(AUTOSAR_uint8, AUTOMATIC) data                            */
/* Return      : Std_ReturnType                                                */
/* Contents    : Writes the braking application data to the RTE port and       */
/*               triggers the Task_BrakingExecute task.                        */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function sets the value for the AEB Apply RTE port and   */
/*               triggers the associated task for processing the data.         */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PP_AEB_Apply_Apply( VAR(AUTOSAR_uint8, AUTOMATIC) data) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    Rte_AEB_Apply_value = data;

    setEvent(Task_BrakingExecute_ID, Rte_Ev_Run_Runable_OnDataReception_BrakeControl_Received)
    return ret_val;
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Read_RP_AEB_Apply_Apply                                   */
/* Trigger     :                                                               */
/* Param       : P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data           */
/* Return      : Std_ReturnType                                                */
/* Contents    : Reads the braking application data from the RTE port.         */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function retrieves the value from the AEB Apply RTE port */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Apply_Apply( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data ) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    *data = Rte_AEB_Apply_value;

    return ret_val;
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_DetermineBrakingAction                                    */
/* Trigger     : Rte_Ev_Run_Runable_OnDataReception_Distance_Received          */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : void                                                          */
/* Contents    : Calls the DetermineBrakingAction function to compute the      */
/*               required braking action.                                      */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function delegates the computation of braking action to  */
/*               the DetermineBrakingAction function.                          */
/*******************************************************************************/
FUNC(void, RTE_CODE) Rte_DetermineBrakingAction( VAR(void, AUTOMATIC) ) 
{
    DetermineBrakingAction();
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_ExecuteBraking                                            */
/* Trigger     : Rte_Ev_Run_Runable_OnDataReception_BrakeControl_Received      */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : void                                                          */
/* Contents    : Calls the ExecuteBraking function to apply braking actions.   */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function delegates the execution of braking actions to   */
/*               the ExecuteBraking function.                                  */
/*******************************************************************************/
FUNC(void, RTE_CODE) Rte_ExecuteBraking( VAR(void, AUTOMATIC) ) 
{
    ExecuteBraking();
}
