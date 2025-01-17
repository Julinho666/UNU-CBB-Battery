#include <Wire.h>

typedef struct
{
    float nrSense;
    uint8_t soc;
    uint8_t vfsoc;
    double current_uA;
    bool charging;
    float cell_voltage;
} cbbState_t;




uint16_t getReg(uint16_t regAddr, void(*errorCallback)(void));

float getNRSense(cbbState_t *cbbState, void (*errorCallback)(void));

uint8_t getSoc(cbbState_t *cbbState, void (*errorCallback)(void));

uint8_t getVFSoc(cbbState_t *cbbState, void (*errorCallback)(void));

double getCurrent_uA(cbbState_t *cbbState, void (*errorCallback)(void));

float getCellVoltage(cbbState_t *cbbState, void (*errorCallback)(void));

void getAllCBBInfo(cbbState_t *cbbState, void (*errorCallback)(void));