
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_SetBrake(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_BrakeValueType, AUTOMATIC) brakeValue) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_BrakeControl(id, brakeValue);
    return return_value;
}