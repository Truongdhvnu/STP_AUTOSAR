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
#include "Com.h"
#include "Rte_Internal.h"

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Task_BrakingControl                                           */
/* Trigger     :                                                               */
/* Param       :                                                               */
/* Return      :                                                               */
/* Contents    : Task for controlling braking based on received distance data  */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This task waits for events related to distance data reception */
/*               determines the necessary braking action, and processes it.    */
/*******************************************************************************/
TASK (Task_BrakingControl) 
{
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( Rte_Ev_Run_Runable_OnDataReception_Distance_Received );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( Rte_Ev_Run_Runable_OnDataReception_Distance_Received, &Event );
        (VAR(void, AUTOMATIC))ClearEvent( Event & (Rte_Ev_Run_Runable_OnDataReception_Distance_Received));

        if( (Event & Rte_Ev_Run_Runable_OnDataReception_Distance_Received) > 0U ) 
        {
            Rte_DetermineBrakingAction();
        }

    }
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Task_BrakingExecute                                           */
/* Trigger     :                                                               */
/* Param       :                                                               */
/* Return      :                                                               */
/* Contents    : Task for executing braking actions based on received brake    */
/*               control data.                                                 */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This task waits for events related to brake control data      */
/*               reception, executes the braking action, and processes it.     */
/*******************************************************************************/
TASK (Task_BrakingExecute) 
{
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( Rte_Ev_Run_Runable_OnDataReception_BrakeControl_Received );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( Rte_Ev_Run_Runable_OnDataReception_BrakeControl_Received, &Event );
        (VAR(void, AUTOMATIC))ClearEvent( Event & (Rte_Ev_Run_Runable_OnDataReception_BrakeControl_Received));

        if( (Event & Rte_Ev_Run_Runable_OnDataReception_BrakeControl_Received) > 0U ) 
        {
            Rte_ExecuteBraking();
        }

    }
}
