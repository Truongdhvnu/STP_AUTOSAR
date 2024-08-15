VAR(AUTOSAR_uint16, AUTOMATIC) Rte_AEB_Distance_value;
VAR(Std_ReturnType, AUTOMATIC) Rte_AEB_Distance_status;

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_COMCbk_DistanceSensorData_Rx                              */
/* Trigger     : CAN message reception                                         */
/* Param       : void                                                          */
/* Return      : void                                                          */
/* Contents    : Callback function triggered upon receiving data from the      */
/*               Distance Sensor via CAN. It reads the raw data and sets the   */
/*               event for further processing in Task_BrakingControl.          */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function is used to handle incoming distance sensor data */
/*               and trigger the braking control task for further processing.  */
/*******************************************************************************/
FUNC (void, RTE_CODE) Rte_COMCbk_DistanceSensorData_Rx (void)
{
    if (Rte_InitState == RTE_STATE_INIT)
    {
        (void) GetSpinlock (Rte_Spinlock_DistanceSensorData_Rx);
        (void) Com_ReceiveSignal(ComSignal_DistanceSensorData_RawData_Rx_ID, &Rte_AEB_Distance_value);

        (void) SetEvent (Task_BrakingControl_ID, Rte_Ev_Run_NetASIL_Runnable_OnDataReception_ADataRawSafe);
    }
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Read_RP_AEB_Distance_Distance                             */
/* Trigger     :                                                               */
/* Param       : P2VAR(AUTOSAR_uint16, AUTOMATIC, RTE_APPL_DATA) data          */
/* Return      : Std_ReturnType                                                */
/* Contents    : Reads the current distance data from the Distance Sensor      */
/*               through the RTE port.                                         */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function retrieves the distance value stored in the RTE  */
/*               and returns the status of the reading operation.              */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Distance_Distance( P2VAR(AUTOSAR_uint16, AUTOMATIC, RTE_APPL_DATA) data ) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    *data = Rte_AEB_Distance_value;
    ret_val = Rte_AEB_Distance_status;

    return ret_val;
}
