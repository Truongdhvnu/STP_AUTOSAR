VAR(AUTOSAR_uint16, AUTOMATIC) Rte_AEB_Distance_value;
VAR(Std_ReturnType, AUTOMATIC) Rte_AEB_Distance_status;


FUNC (void, RTE_CODE) Rte_COMCbk_DistanceSensorData_Rx (void)
{
    if (Rte_InitState == RTE_STATE_INIT)
    {
        (void) GetSpinlock (Rte_Spinlock_DistanceSensorData_Rx);
        (void) Com_ReceiveSignal(ComSignal_DistanceSensorData_RawData_Rx_ID, &Rte_AEB_Distance_value);

        (void) SetEvent (Task_BrakingControl_ID, Rte_Ev_Run_NetASIL_Runnable_OnDataReception_ADataRawSafe);
    }
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Distance_Distance( P2VAR(AUTOSAR_uint16, AUTOMATIC, RTE_APPL_DATA) data ) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    *data = Rte_AEB_Distance_value;
    ret_val = Rte_AEB_Distance_status;

    return ret_val;
}
