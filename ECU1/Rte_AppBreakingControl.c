#include "OS.h"
#include "Rte_AppBreakingControl.h"

VAR(AUTOSAR_uint8, AUTOMATIC) Rte_AEB_Apply_value;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Write_PP_AEB_Apply_Apply                                  */
/* Trigger     :                                                               */
/* Param       : VAR(AUTOSAR_uint8, AUTOMATIC) data                            */
/* Return      : Std_ReturnType                                                */
/* Contents    : Writes the braking application data to the RTE port and       */
/*               triggers the Task_BrakingExecute task.                        */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function sets the value for the AEB Apply RTE port and   */
/*               triggers the associated task for processing the data.         */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PP_AEB_Apply_Apply( VAR(AUTOSAR_uint8, AUTOMATIC) data) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    Rte_AEB_Apply_value = data;

    setEvent(Task_BrakingExecute_ID, Rte_Ev_Run_Runable_OnDataReception_BrakeControl_Received)
    
    return ret_val;
}

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Read_RP_AEB_Apply_Apply                                   */
/* Trigger     :                                                               */
/* Param       : P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data           */
/* Return      : Std_ReturnType                                                */
/* Contents    : Reads the braking application data from the RTE port.         */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function retrieves the value from the AEB Apply RTE port */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_RP_AEB_Apply_Apply( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data ) 
{
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    *data = Rte_AEB_Apply_value;

    return ret_val;
}

extern FUNC(void, DetermineBrakingAction_CODE) DetermineBrakingAction(VAR(void, AUTOMATIC) ) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_DetermineBrakingAction                                    */
/* Trigger     : Rte_Ev_Run_Runable_OnDataReception_Distance_Received          */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : void                                                          */
/* Contents    : Calls the DetermineBrakingAction function to compute the      */
/*               required braking action.                                      */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function delegates the computation of braking action to  */
/*               the DetermineBrakingAction function.                          */
/*******************************************************************************/
FUNC(void, RTE_CODE) Rte_DetermineBrakingAction( VAR(void, AUTOMATIC) ) 
{
    DetermineBrakingAction();
}

extern FUNC(void, ExecuteBraking_CODE) ExecuteBraking(VAR(void, AUTOMATIC) ) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_ExecuteBraking                                            */
/* Trigger     : Rte_Ev_Run_Runable_OnDataReception_BrakeControl_Received      */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : void                                                          */
/* Contents    : Calls the ExecuteBraking function to apply braking actions.   */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function delegates the execution of braking actions to   */
/*               the ExecuteBraking function.                                  */
/*******************************************************************************/
FUNC(void, RTE_CODE) Rte_ExecuteBraking( VAR(void, AUTOMATIC) ) 
{
    ExecuteBraking();
}

extern FUNC(void, UserReadInput_30ms_CODE) UserReadInput_30ms(VAR(void, AUTOMATIC) ) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_UserReadInput_30ms                                        */
/* Trigger     : Rte_Ev_ReadUserInput_30ms                                     */
/* Param       : None                                                          */
/* Return      : None                                                          */
/* Contents    : Calls the UserReadInput_30ms function to read user input      */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function is called by the RTE to execute the logic for   */
/*               reading user input                                            */
/*******************************************************************************/
FUNC(void, RTE_CODE) Rte_UserReadInput_30ms( VAR(void, AUTOMATIC) ) 
{
    UserReadInput_30ms();
}

extern FUNC(void, ActivateEmergencyBraking_CODE) ActivateEmergencyBraking(VAR(void, AUTOMATIC) ) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Call_RP_AEBSetting_Enable                                 */
/* Trigger     :                                                               */
/* Param       : None                                                          */
/* Return      : None                                                          */
/* Contents    : Calls the ActivateEmergencyBraking function to enable AEB     */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function is called by the RTE to execute the logic for   */
/*               enabling the AEB setting                                      */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_AEBSetting_Enable( VAR(void, AUTOMATIC) ) 
{   
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    /* Sybchronnous server call point */
    ret_val = ActivateEmergencyBraking();

    return ret_val;
}

extern FUNC(void, DeActivateEmergencyBraking_CODE) DeActivateEmergencyBraking(VAR(void, AUTOMATIC) ) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Call_RP_AEBSetting_Disable                                */
/* Trigger     :                                                               */
/* Param       : None                                                          */
/* Return      : None                                                          */
/* Contents    : Calls the DeActivateEmergencyBraking function to disable AEB  */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function is called by the RTE to execute the logic for   */
/*               disabling the AEB setting                                     */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_RP_AEBSetting_Disable( VAR(void, AUTOMATIC) ) 
{   
    VAR(Std_ReturnType, AUTOMATIC) ret_val = E_OK;

    /* Sybchronnous server call point */
    ret_val = DeActivateEmergencyBraking();

    return ret_val;
}

extern FUNC(void, IoHwAb_CODE) IoHwAb_BrakeControl(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_BrakeValueType, AUTOMATIC) brakeValue) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Call_R_IoHwAb_SetBrake                                    */
/* Trigger     :                                                               */
/* Param       : id - Identifier for the brake control hardware                */
/*               brakeValue - Desired brake value to set                       */
/* Return      : Std_ReturnType                                                */
/* Contents    : This function calls the IoHwAb module to set the brake value  */
/*               based on the provided hardware identifier and brake value.    */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : The function interfaces with the lower-level hardware         */
/*               abstraction layer to apply the braking force.                 */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_SetBrake(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_BrakeValueType, AUTOMATIC) brakeValue) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_BrakeControl(id, brakeValue);
    return return_value;
}

extern FUNC(void, IoHwAb_CODE) IoHwAb_GetSpeed(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_SpeedValueType, AUTOMATIC) speedValue) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Call_R_IoHwAb_GetSpeed                                    */
/* Trigger     :                                                               */
/* Param       : id - Identifier for the speed sensor hardware                 */
/*               speedValue - Pointer to store the retrieved speed value       */
/* Return      : Std_ReturnType                                                */
/* Contents    : This function calls the IoHwAb module to get the current      */
/*               speed value from the specified speed sensor hardware.         */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : The function interfaces with the hardware abstraction layer   */
/*               to read the vehicle's speed from the sensor.                  */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetSpeed( VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_SpeedValueType, AUTOMATIC) speedValue) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_GetSpeed(id, speedValue);
    return return_value;
}

extern FUNC(void, IoHwAb_CODE) IoHwAb_GetUserInput(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_SpeedValueType, AUTOMATIC) speedValue) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Call_R_IoHwAb_GetUserInput                                */
/* Trigger     :                                                               */
/* Param       : id - Identifier for the user button hardware                  */
/*               userInput - Variable to store the retrieved user input data   */
/* Return      : Std_ReturnType - E_OK if successful, or an error code         */
/* Contents    : This function calls the IoHwAb (Input/Output Hardware         */
/*               Abstraction) layer to retrieve user input data from a         */
/*               specified hardware ID. The data is stored in the              */
/*               userInput parameter.                                          */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function acts as a bridge between the RTE and the        */
/*               underlying hardware abstraction layer, ensuring the correct   */
/*               user input data is retrieved based on the specified ID.       */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetUserInput( VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, P2VAR(UserButtonType, AUTOMATIC, RTE_APPL_DATA) userInput) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = E_OK;

    return_value = IoHwAb_GetUserInput(id, userInput);
    return return_value;
}

extern FUNC(void, IoHwAb_CODE) IoHwAb_BrakeControl(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_BrakeValueType, AUTOMATIC) brakeValue) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Call_R_IoHwAb_SetBrake                                    */
/* Trigger     :                                                               */
/* Param       : id - Identifier for the brake control hardware                */
/*               brakeValue - Desired brake value to set                       */
/* Return      : Std_ReturnType                                                */
/* Contents    : This function calls the IoHwAb module to set the brake value  */
/*               based on the provided hardware identifier and brake value.    */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : The function interfaces with the lower-level hardware         */
/*               abstraction layer to apply the braking force.                 */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_SetBrake(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_BrakeValueType, AUTOMATIC) brakeValue) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_BrakeControl(id, brakeValue);
    return return_value;
}

extern FUNC(void, IoHwAb_CODE) IoHwAb_GetSpeed(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_SpeedValueType, AUTOMATIC) speedValue) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Call_R_IoHwAb_GetSpeed                                    */
/* Trigger     :                                                               */
/* Param       : id - Identifier for the speed sensor hardware                 */
/*               speedValue - Pointer to store the retrieved speed value       */
/* Return      : Std_ReturnType                                                */
/* Contents    : This function calls the IoHwAb module to get the current      */
/*               speed value from the specified speed sensor hardware.         */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : The function interfaces with the hardware abstraction layer   */
/*               to read the vehicle's speed from the sensor.                  */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetSpeed( VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_SpeedValueType, AUTOMATIC) speedValue) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_GetSpeed(id, speedValue);
    return return_value;
}

extern FUNC(void, IoHwAb_CODE) IoHwAb_GetUserInput(VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_SpeedValueType, AUTOMATIC) speedValue) ;
/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : Rte_Call_R_IoHwAb_GetUserInput                                */
/* Trigger     :                                                               */
/* Param       : id - Identifier for the user button hardware                  */
/*               userInput - Variable to store the retrieved user input data   */
/* Return      : Std_ReturnType - E_OK if successful, or an error code         */
/* Contents    : This function calls the IoHwAb (Input/Output Hardware         */
/*               Abstraction) layer to retrieve user input data from a         */
/*               specified hardware ID. The data is stored in the              */
/*               userInput parameter.                                          */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function acts as a bridge between the RTE and the        */
/*               underlying hardware abstraction layer, ensuring the correct   */
/*               user input data is retrieved based on the specified ID.       */
/*******************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetUserInput( VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, P2VAR(UserButtonType, AUTOMATIC, RTE_APPL_DATA) userInput) 
{
    VAR(Std_ReturnType, AUTOMATIC) return_value = E_OK;

    return_value = IoHwAb_GetUserInput(id, userInput);
    return return_value;
}