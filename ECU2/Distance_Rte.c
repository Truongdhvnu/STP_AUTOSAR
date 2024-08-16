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
#include "Rte_Type.h"

#include "Os.h"
#include "Rte_Internal.h"

extern FUNC(void, RTE_CODE) Rte_ReadDistance_5ms( VAR(void, AUTOMATIC) ) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Task_DistanceSensor                                           */
/* Trigger     :                                                               */
/* Param       :                                                               */
/* Return      :                                                               */
/* Contents    : Task responsible for handling distance sensor data reception  */
/*               and processing at 5ms intervals. It waits for the event       */
/*               Rte_Ev_ReadDistance_5ms to trigger the read operation.        */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : The task reads the distance data when the event is triggered  */
/*               and processes it to be used by other system components.       */
/*******************************************************************************/
TASK (Task_DistanceSensor) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( Rte_Ev_ReadDistance_5ms );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( Task_DistanceSensor, &Event );
        (VAR(void, AUTOMATIC))ClearEvent( Event & (Rte_Ev_ReadDistance_5ms));

        if( (Event & Rte_Ev_ReadDistance_5ms) > 0U ) 
        {
            Rte_ReadDistance_5ms();
        }

    }
}