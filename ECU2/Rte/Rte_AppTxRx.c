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
#include "COM.h"
#include "Rte_AppTxRx.h"
#include "App_Types.h"
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Write_PP_AEB_Distance_Distance                            */
/* Trigger     :                                                               */
/* Param       : data - The distance data to be written                        */
/* Return      : Std_ReturnType - E_OK if successful, error codes otherwise    */
/* Contents    : This function sends the distance data over the CAN bus        */
/*               using the Com_SendSignal API. It handles possible errors      */
/*               such as COM_BUSY and COM_SERVICE_NOT_AVAILABLE.               */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : The data is sent using the signal configured for the CAN bus. */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PP_AEB_Distance_Distance( VAR(AppIo_IoHwAb_DistanceValueType, AUTOMATIC) data) 
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

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_ReadDistance_5ms                                          */
/* Trigger     : Rte_Ev_ReadDistance_5ms                                       */
/* Param       :                                                               */
/* Return      : void                                                          */
/* Contents    : This function calls the ReadDistance_5ms function to handle   */
/*               the distance reading process every 5 ms.                      */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : The distance data is processed as per the implementation in   */
/*               the ReadDistance_5ms function.                                */
/*******************************************************************************/
FUNC(void, RTE_CODE) Rte_ReadDistance_5ms( VAR(void, AUTOMATIC) ) 
{

    ReadDistance_5ms();

}