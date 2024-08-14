VAR(AUTOSAR_uint8, AUTOMATIC) Rte_AEB_Apply_value;

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PP_AEB_Apply_Apply( VAR(AUTOSAR_uint8, AUTOMATIC) data) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    Rte_AEB_Apply_value = data;

    setEvent(Task_BrakingExecute_ID, Rte_Ev_Run_Runable_OnDataReception_BrakeControl_Received)
    return ret_val;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Apply_Apply( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data ) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    *data = Rte_AEB_Apply_value;

    return ret_val;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_AEB_Apply_Apply( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data ) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    *data = Rte_AEB_Apply_value;

    return ret_val;
}

FUNC(void, RTE_CODE) Rte_DetermineBrakingAction( VAR(void, AUTOMATIC) ) 
{
    DetermineBrakingAction();
}

FUNC(void, RTE_CODE) Rte_ExecuteBraking( VAR(void, AUTOMATIC) ) 
{
    ExecuteBraking();
}
