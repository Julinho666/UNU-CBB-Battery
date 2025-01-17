#define MAX1730X_I2C_ADDRESS_0 (0x6C >> 1)
#define MAX1730X_I2C_ADDRESS_1 (0x16 >> 1)

#define REG_NRSENSE 0x1CF
#define REG_STATUS 0x00
#define REG_REP_SOC 0x06
#define REG_CURRENT 0x1C
#define REG_VCELL 0x1a
#define REG_VFSOC 0xFF

#define MAX1730X_CURRENT_RESOLUTION \
    1.5625                                     // in (uV) divide by sense resistor [-51.2mV to 51.1984mV] (Signed 2's \
        // complement)
#define MAX1730X_MINIMUM_CHARGING_CURRENT 5000 // uA

#include "cbBattery.h"
#include <Arduino.h>  

uint16_t getReg(uint16_t regAddr, void (*errorCallback)(void))
{
    uint8_t devAddr = MAX1730X_I2C_ADDRESS_0;
    if ((regAddr >> 8) >= 1)
        devAddr = MAX1730X_I2C_ADDRESS_1;

    Wire.beginTransmission(devAddr);
    Wire.write((uint8_t)regAddr);
    uint8_t err = Wire.endTransmission(false);

    if (err)
    {
        errorCallback();
        return 0;
    }

    Wire.requestFrom(devAddr, 2);
    if (Wire.available() < 2)
    {
        errorCallback();
        return 0;
    }
    uint16_t response = Wire.read();
    response |= (Wire.read() << 8);

    return response;
}

float getNRSense(cbbState_t *cbbState, void (*errorCallback)(void))
{
    cbbState->nrSense = (float)getReg(REG_NRSENSE, errorCallback) * 10e-6;
    return cbbState->nrSense;
}

uint8_t getSoc(cbbState_t *cbbState, void (*errorCallback)(void))
{
    cbbState->soc = (getReg(REG_REP_SOC, errorCallback) >> 8);
    return cbbState->soc;
}

uint8_t getVFSoc(cbbState_t *cbbState, void (*errorCallback)(void))
{
    cbbState->vfsoc = (getReg(REG_VFSOC, errorCallback) >> 8);
    return cbbState->vfsoc;
}

double getCurrent_uA(cbbState_t *cbbState, void (*errorCallback)(void))
{
    cbbState->current_uA = (double)((int16_t)getReg(REG_CURRENT, errorCallback)) * MAX1730X_CURRENT_RESOLUTION / (cbbState->nrSense);
    cbbState->charging = cbbState->current_uA > MAX1730X_MINIMUM_CHARGING_CURRENT;
    return cbbState->current_uA;
}

float getCellVoltage(cbbState_t *cbbState, void (*errorCallback)(void))
{
    cbbState->cell_voltage = (float)getReg(REG_VCELL, errorCallback) * 78.125e-6;
    return cbbState->cell_voltage;
}


void getAllCBBInfo(cbbState_t *cbbState, void (*errorCallback)(void))
{
    getNRSense(cbbState, errorCallback);
    getSoc(cbbState, errorCallback);
    getVFSoc(cbbState, errorCallback);
    getCurrent_uA(cbbState, errorCallback);
    getCellVoltage(cbbState, errorCallback);
}
