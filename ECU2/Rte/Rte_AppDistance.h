#ifndef RTE_APPDISTANCE_H
#define RTE_APPDISTANCE_H


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_AppDistance_Type.h"
#include "Rte_DataHandleType.h"
#include "App_Types.h"
#include "IoHwAb.h"
#include "Rte_MemMap.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetDistance(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_DistanceValueType, AUTOMATIC, RTE_APPL_DATA) distanceValue);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_Service_ReadBlock_Sensor_Calib(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) data);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif 
