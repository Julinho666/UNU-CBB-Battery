# UNU-CBB-Battery (MAX17301)

# Hardware description
The CBB battery is a power bank that can be charged using a voltage of 20 - 60 V. 
The battery delivers 5 V at the output with a maximum current of 2.5 A. 
There is a MAX17301 on the board, which can be used to check the battery level.

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

After Uploading the sketch   open terminal (115000Baud)

example: SOC: 49% VFSOC: 49%, Current: -0.52mA, Charging: No, Voltage: 3.70V

SOC is the calculated SOC by counting the current(m5 algorithm)

VFSOC ist the calculated SOC by Voltage

## Charging Fuse (broken?)

The PCB contains an SMD fuse responsible for charging. 
If this fuse fails, the charging circuit will no longer function, but the CBB will still be recognized by the MDB. 
A 2A slow-blow fuse is currently installed; it is recommended to replace it with a 3A slow-blow fuse (Size 1206 63V).
![cbb_fuse](https://github.com/user-attachments/assets/a6803dd4-b04a-48ec-adb8-78d67661ac6b)


## License
This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
