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
