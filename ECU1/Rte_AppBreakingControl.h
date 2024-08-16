
#ifndef RTE_APPBREAKINGCOTROL_H
#define RTE_APPBREAKINGCOTROL_H


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_AppBreakingControl_Type.h"
#include "Rte_DataHandleType.h"
#include "IoHwAb.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PP_AEB_Apply_Apply( VAR(AUTOSAR_uint8, AUTOMATIC) data) ; 
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Apply_Apply( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data ) ;
extern FUNC(void, RTE_CODE) Rte_Call_RP_AEBSetting_Enable( VAR(void, AUTOMATIC) ) ;
extern FUNC(void, RTE_CODE) Rte_Call_RP_AEBSetting_Disable( VAR(void, AUTOMATIC) ) ;
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_SetBrake(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_BrakeValueType, AUTOMATIC) brakeValue) ;
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetSpeed( VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_SpeedValueType, AUTOMATIC) speedValue) ;
extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetUserInput( VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, P2VAR(UserButtonType, AUTOMATIC, RTE_APPL_DATA) userInput) ;

extern FUNC(void, RTE_CODE) Rte_DetermineBrakingAction( VAR(void, AUTOMATIC) ) ;
extern FUNC(void, RTE_CODE) Rte_ExecuteBraking( VAR(void, AUTOMATIC) ) ;
extern FUNC(void, RTE_CODE) Rte_UserReadInput_30ms( VAR(void, AUTOMATIC) ) ;

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif 

