#ifndef RTE_APPCOMTXRX_H
#define RTE_APPCOMTXRX_H


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_AppComTxRx_Type.h"
#include "Rte_DataHandleType.h"
#include "Rte_MemMap.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PP_AEB_Distance_Distance( VAR(AppIo_IoHwAb_DistanceValueType, AUTOMATIC) data) ;
extern FUNC(void, RTE_CODE) Rte_ReadDistance_5ms( VAR(void, AUTOMATIC) ) ;


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif 
