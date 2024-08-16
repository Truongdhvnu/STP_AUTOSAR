#include "Rte_AppDistance.h"
#include "NvM.h"

extern FUNC(void, IoHwAb_CODE) IoHwAb_GetDistance(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_DistanceValueType, AUTOMATIC, RTE_APPL_DATA) distanceValue) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Call_R_IoHwAb_GetDistance                                 */
/* Trigger     :                                                               */
/* Param       : id - Identifier for the distance sensor hardware              */
/*               distanceValue - Pointer to store the retrieved distance value */
/* Return      : Std_ReturnType - E_OK if successful, E_NOT_OK otherwise       */
/* Contents    : This function calls the IoHwAb layer to retrieve the distance */
/*               from the specified distance sensor hardware.                  */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : The retrieved distance value is stored in the variable        */
/*               pointed to by distanceValue.                                  */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetDistance(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_DistanceValueType, AUTOMATIC, RTE_APPL_DATA) distanceValue) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_GetDistance(id, distanceValue);
    
    return return_value;
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Call_NvM_Service_ReadBlock_Sensor_Calib                   */
/* Trigger     :                                                               */
/* Contents    : This function read sensor calib data from NVM memory          */
/* Author      : HN24_FR_Autosar_G01A                                          */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_Service_ReadBlock_Sensor_Calib(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) data) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = NvM_ReadBlock(NVM_BLOCK_ID_SENSOR_CALIB, data);

    return return_value;
}