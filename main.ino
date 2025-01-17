#include <Arduino.h>
#include "cbBattery.h"
#include <avr/wdt.h>

cbbState_t cbbState;

volatile bool i2cErrorOccurred = false;
void i2cError(void)
{
  i2cErrorOccurred = true;
  Serial.println("I2C Error");
}

void watchdogOn(uint8_t interval_reg)
{
  MCUSR = MCUSR & B11110111;
  WDTCSR = WDTCSR | B00011000;
  WDTCSR = interval_reg;
  WDTCSR = WDTCSR | B01000000;
  MCUSR = MCUSR & B11110111;
}

void setup()
{
   Serial.begin(115200);

  Wire.begin();

  watchdogOn(WDTO_1S);

  Serial.println("Starting...");

}

void loop()
{
  
  wdt_reset();

    i2cErrorOccurred = false; 
    
    getAllCBBInfo(&cbbState, i2cError);
    
    Serial.print("SOC: ");
    Serial.print(cbbState.soc);
    Serial.print("% VFSOC: ");
    Serial.print(cbbState.vfsoc);
    Serial.print("%, Current: ");
    Serial.print(cbbState.current_uA / 1000);
    Serial.print("mA, Charging: ");
    if (cbbState.charging)
      Serial.print("Yes");
    else
      Serial.print("No");
    Serial.print(", Voltage: ");
    Serial.print(cbbState.cell_voltage);
    Serial.println("V");
  
    delay(1000);
  
}