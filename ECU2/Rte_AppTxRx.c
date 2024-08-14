/******************************************************************************/
/* Copyright   : Group1A Autosar                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_App.c                                                    */
/* Version     : v1.0.0                                                       */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_App.h"

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PP_AEB_Distance_Distance( VAR(AUTOSAR_uint8, AUTOMATIC) data) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(AUTOSAR_uint16, AUTOMATIC) tmp_data = data;

    ret = Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_Distance_Sig, &tmp_data );
    switch( ret ) {
    case COM_SERVICE_NOT_AVAILABLE:
        ret_val = RTE_E_COM_STOPPED;
        break;
    case COM_BUSY:
        ret_val = RTE_E_COM_BUSY;
        break;
    default:
        /* nothing */
        break;
    }

    return ret_val;
}

extern FUNC(void, ReadDistance_CODE) ReadDistance_5ms(VAR(void, AUTOMATIC) ) ;

FUNC(void, RTE_CODE) Rte_ReadDistance_5ms( VAR(void, AUTOMATIC) ) 
{

    ReadDistance_5ms();

}