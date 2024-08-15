#include "Rte_Type.h"

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

    return_value = IoHwAb_AdcGetSpeed(id, speedValue);
    return return_value;
}

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

    return_value = IoHwAb_AdcGetUserInput(id, userInput);
    return return_value;
}