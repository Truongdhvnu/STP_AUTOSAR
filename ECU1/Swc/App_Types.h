#ifndef APP_TYPES_H
#define APP_TYPES_H

#define AppIo_IoHwAb_IdType             uint8
#define AppIo_IoHwAb_BrakeValueType     uint16
#define AppIo_IoHwAb_SpeedValueType     uint16
#define UserButtonType                  uint8
#define AppIo_IoHwAb_DistanceValueType  uint16

typedef enum  
{
    EMERGENCY_BRAKING_SERVICE_OFF,
    EMERGENCY_BRAKING_SERVICE_ON
} Emergency_Braking_Service_Status;

typedef enum  
{
    USER_BUTTON_LOW,
    USER_BUTTON_HIGH,
} UserButtonType;

#endif 

