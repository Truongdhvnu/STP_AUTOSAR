#ifndef RTE_APPCOMTXRX_H
#define RTE_APPCOMTXRX_H


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_AppComTxRx_Type.h"
#include "Rte_DataHandleType.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC (void, RTE_CODE) Rte_COMCbk_DistanceSensorData_Rx (void);
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Distance_Distance( P2VAR(AUTOSAR_uint16, AUTOMATIC, RTE_APPL_DATA) data );

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif 
