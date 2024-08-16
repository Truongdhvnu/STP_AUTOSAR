#include "Wdg.h"
#include "NvM.h"
#include "Rte_MemMap.h"
#include "Nvm_Sensor.h"

VAR(FDSensor_Calib_parameters, AUTOMATIC) fd_sensor_calib;
VAR(AUTOSAR_uint8, AUTOMATIC) ParameterInitSuccessful = 0; 

FUNC(void, DetermineBrakingAction_CODE) Parameter_Init (VAR(void, AUTOMATIC) ) 
{
    // Asynchronous call with pooling
    Rte_Call_NvM_Service_ReadBlock_Sensor_Calib((void*)fd_sensor_calib);

    while (Rte_Call_NvM_Service_GetErrorStatus() != NVM_REQ_PENDING)
    {
        // nothing
    }

    if (Rte_Call_NvM_Service_GetErrorStatus() == NVM_REQ_OK) 
    {
        ParameterInitSuccessful = 1;
    }
}

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
    VAR(AppIo_IoHwAb_DistanceValueType, AUTOMATIC) distance;

    // Call RTE Port API to get raw distance data and process it by calib parameter
    if (ParameterInitSuccessful > 0) 
    {
        Rte_Call_R_IoHwAb_GetDistance(Distance_Front_Sensor_ID, distance);
        distance = (distance * fd_sensor_calib.Gradient) + fd_sensor_calib.Offset;
        Rte_Write_PP_AEB_Distance_Distance(distance);
    }

    // CP_ID_0 : Checkpoint ID of the Alive Supervision CheckPoint corresponding to this SE
    // SE1_ID : Identifier of this Supervised Entity
	Rte_Call_WdgMCheckpointReached(SE1_ID, CP_ID_0); 
}