

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetDistance(VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_DistanceValueType, AUTOMATIC, RTE_APPL_DATA) distanceValue) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_AdcGetDistance(id, distanceValue);
    return return_value;
}