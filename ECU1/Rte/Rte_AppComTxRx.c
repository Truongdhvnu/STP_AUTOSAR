#include "OS.h"
#include "COM.h"
#include "Rte_AppComTxRx.h"
#include "App_Types.h"

VAR(AppIo_IoHwAb_DistanceValueType, AUTOMATIC) Rte_AEB_Distance_value;
VAR(Std_ReturnType, AUTOMATIC) Rte_AEB_Distance_status = RTE_E_NEVER_RECEIVED;

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_COMCbk_DistanceSensorData_Rx                              */
/* Trigger     : CAN message reception                                         */
/* Param       : void                                                          */
/* Return      : void                                                          */
/* Contents    : Callback function triggered upon receiving data from the      */
/*               Distance Sensor via CAN. It reads the raw data and sets the   */
/*               event for further processing in Task_BrakingControl.          */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function is used to handle incoming distance sensor data */
/*               and trigger the braking control task for further processing.  */
/*******************************************************************************/
FUNC (void, RTE_CODE) Rte_COMCbk_DistanceSensorData_Rx (void)
{
    (void) Com_ReceiveSignal(ComSignal_DistanceSensorData_RawData_Rx_ID, &Rte_AEB_Distance_value);

    (void) SetEvent (Task_BrakingControl_ID, Rte_Ev_Run_Runable_OnDataReception_Distance_Received);
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Read_RP_AEB_Distance_Distance                             */
/* Trigger     :                                                               */
/* Param       : AppIo_IoHwAb_DistanceValueType data                           */
/* Return      : Std_ReturnType                                                */
/* Contents    : Reads the current distance data from the Distance Sensor      */
/*               through the RTE port.                                         */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function retrieves the distance value stored in the RTE  */
/*               and returns the status of the reading operation.              */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Distance_Distance( P2VAR(AppIo_IoHwAb_DistanceValueType, AUTOMATIC, RTE_APPL_DATA) data ) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    *data = Rte_AEB_Distance_value;
    ret_val = Rte_AEB_Distance_status;

    return ret_val;
}
