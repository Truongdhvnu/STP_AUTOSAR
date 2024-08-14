VAR(AUTOSAR_uint8, AUTOMATIC) Rte_AEB_Setting_value;

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PP_AEB_Setting_Setting( VAR(AUTOSAR_uint8, AUTOMATIC) data) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    Rte_AEB_Setting_value = data;

    return ret_val;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Setting_Setting( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    *data = Rte_AEB_Setting_value;

    return ret_val;
}