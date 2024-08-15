/*******************************************************************************/
/* ModuleID    :                                                               */
/* ServiceID   :                                                               */
/* Name        : ReadDistance_5ms                                              */
/* Trigger     :                                                               */
/* Param       :                                                               */
/* Return      :                                                               */
/* Contents    : Function to read and modify raw distance data at 5ms intervals*/
/* Author      : HN24_FR_Autosar_G01A                                          */
/* Note        : This function is called every 5ms to obtain and process       */
/*               distance data from the sensor. It also checks the supervision */
/*               point with the WdgM module for alive monitoring.              */
/*******************************************************************************/
FUNC(void, ReadDistance_CODE) ReadDistance_5ms(VAR(void, AUTOMATIC) ) 
{
    /*
        Call RTE Port API to get raw distance data and modify it 
    */

    // CP_ID_0 : Checkpoint ID of the Alive Supervision CheckPoint corresponding to this SE
    // SE1_ID : Identifier of this Supervised Entity
	Rte_Call_WdgMCheckpointReached(SE1_ID, CP_ID_0); 
}