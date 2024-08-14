
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetSpeed( VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_SpeedValueType, AUTOMATIC) speedValue) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_AdcGetSpeed(id, speedValue);
    return return_value;
}