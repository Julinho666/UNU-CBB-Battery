# UNU-CBB-Battery

## Connections UNU-CBB-Battery
![Belegung CBB1](https://github.com/user-attachments/assets/ac5430ca-d72d-4de4-86c8-051947f3a087)


| Name | Color | Function|
|------|-------|------|
| GND | GREEN | Common Ground |
| CHARGE +|  BLACK |Input 20-60V 10W |
| ENABLE | YELLOW | Connect to GND--> CBB OFF |
| +5V out | BLUE | 5V Out max 2,5A |
| SCL |	RED		|IC2 SCL|  
| SDA|	WHITE |IC2 SDA|  




## Connect CBB to Arduino

| Arduino | Color | CBB |
|---------|-------|-----|
| GND | GREEN |GND |
| A4 | WHITE | SDA(pullup 4K7 to 3V3) |
| A5 | RED | SCL(pullup 4K7 to 3V3) |
| 3V3 |			|Pullups|  

After Flashing the Arduino open terminal (115000Baud)

example: SOC: 49% VFSOC: 49%, Current: -0.52mA, Charging: No, Voltage: 3.70V

SOC is the calculated SOC by counting the current(m5 algorithm)
VFSOC ist the calculated SOC by Voltage


## License
This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].
