VAR(AUTOSAR_uint16, AUTOMATIC) Rte_AEB_Distance_value;
VAR(Std_ReturnType, AUTOMATIC) Rte_AEB_Distance_status;

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Distance_Distance( P2VAR(AUTOSAR_uint16, AUTOMATIC, RTE_APPL_DATA) data ) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    *data = Rte_AEB_Distance_value;
    ret_val = Rte_AEB_Distance_status;

    return ret_val;
}
