#include "App_Types.h"

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_R_IoHwAb_GetUserInput( VAR(AppIo_IoHwAb_IdType, AUTOMATIC) id, P2VAR(UserButtonType, AUTOMATIC, RTE_APPL_DATA) userInput) ;

/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : UserReadInput_30ms                                            */
/* Trigger     :                                                               */
/* Param       : None                                                          */
/* Return      : None                                                          */
/* Contents    : This function reads user input data through the RTE port,     */
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function is  called at a 30ms interval to ensure timely  */
/*               updates of user input                                         */
/*******************************************************************************/
FUNC(void, UserReadInput_30ms_CODE) UserReadInput_30ms(VAR(void, AUTOMATIC) ) 
{
    UserButtonType status;
    VAR(Std_ReturnType, AUTOMATIC) ret_val;
    static UserButtonType previous_status;

    Rte_Call_R_IoHwAb_GetUserInput(USER_BUTTON_HW_ID, &status);
    if(status != previous_status)
    {
        if(status == USER_BUTTON_HIGH)
        {
            ret_val = Rte_Call_RP_AEBSetting_Enable();
        }
        else if(status == USER_BUTTON_LOW)
        {
            Rte_Call_RP_AEBSetting_Disable();
        }
    }
    previous_status = status;
}