VAR(AUTOSAR_uint16, AUTOMATIC) Rte_AEB_Distance_value;
VAR(Std_ReturnType, AUTOMATIC) Rte_AEB_Distance_status;

#include "Rte_MemMap.h"

/******************************************************************************/
/* ModuleID    : Rte_COMCbk_DistanceSensorData_Rx                            */
/* ServiceID   :                                                              */
/* Name        : Rte_COMCbk_DistanceSensorData_Rx                            */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Handles reception of distance sensor data from CAN.          */
/*               - Checks initialization state.                                */
/*               - Acquires spinlock for exclusive access to data.            */
/*               - Receives signal group and individual signal.               */
/*               - Sets event to update BrakingControl task with new data.    */
/* Author      : HN24_FR_Autosar02_G01A                                       */
/* Note        : Ensure proper initialization and handling of CAN data.       */
/******************************************************************************/
FUNC (void, RTE_CODE) Rte_COMCbk_DistanceSensorData_Rx (void)
{
    if (Rte_InitState == RTE_STATE_INIT)
    {
        (void) GetSpinlock (Rte_Spinlock_DistanceSensorData_Rx);
        (void) Com_ReceiveSignalGroup (ComSignalGroup_DistanceSensorData_Rx_ID);
        (void) Com_ReceiveSignal(ComSignal_DistanceSensorData_RawData_Rx_ID, &Rte_AEB_Distance_value);

        (void) SetEvent (Task_BrakingControl_ID, Rte_Ev_Run_NetASIL_Runnable_OnDataReception_ADataRawSafe);
    }
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Distance_Distance( P2VAR(AUTOSAR_uint16, AUTOMATIC, RTE_APPL_DATA) data ) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    *data = Rte_AEB_Distance_value;
    ret_val = Rte_AEB_Distance_status;

    return ret_val;
}
