VAR(AUTOSAR_uint8, AUTOMATIC) Rte_AEB_Setting_value;

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Read_PP_AEB_Setting_Setting                               */
/* Trigger     :                                                               */
/* Param       : data - The setting data to be read                            */
/* Return      : Std_ReturnType - E_OK if successful                           */
/* Contents    : This function stores the provided AEB setting value into      */
/*               the Rte_AEB_Setting_value variable.                           */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : The setting value is stored in a global variable for later    */
/*               retrieval by other functions.                                 */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PP_AEB_Setting_Setting( VAR(AUTOSAR_uint8, AUTOMATIC) data) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    Rte_AEB_Setting_value = data;

    return ret_val;
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Read_RP_AEB_Setting_Setting                               */
/* Trigger     :                                                               */
/* Param       : data - Pointer to where the setting data will be stored       */
/* Return      : Std_ReturnType - E_OK if successful                           */
/* Contents    : This function retrieves the stored AEB setting value from     */
/*               the Rte_AEB_Setting_value variable and stores it in the       */
/*               location pointed to by the data parameter.                    */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : The retrieved value is copied to the memory location provided */
/*               by the caller.                                                */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Setting_Setting( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    *data = Rte_AEB_Setting_value;

    return ret_val;
}