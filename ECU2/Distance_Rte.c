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

TASK (Task_DistanceSensor) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( Rte_Ev_ReadDistance_5ms );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( Rte_Ev_ReadDistance_5ms, &Event );
        (VAR(void, AUTOMATIC))ClearEvent( Event & (Rte_Ev_ReadDistance_5ms));

        if( (Event & OsEvent_ASW_20ms) > 0U ) 
        {
            Rte_ReadDistance_5ms();
        }

    }
}