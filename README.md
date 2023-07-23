# Sega Genesis/Mega Drive to JAMMA Controller Adapter

**WARNNING:** Check the compatibility of your hardware, I'm not responsible for any damage caused to your equipment. 

Simple use of jonthysell's "SegaController" library, allowing the use of Sega Genesis/Mega Drive 6-Button controllers on JAMMA  hardware.

Test Video:
- Neo Geo MVS (MV1A): [https://youtu.be/vLB6MV_LYBk](https://youtu.be/vLB6MV_LYBk)

Test done on my DIY SuperGun:
![alt text](https://github.com/MasterJhimmy/Sega-Genesis-to-JAMMA-controller-adapter/blob/main/supergun_test.jpg?raw=true)

SG_to_JAMMA Buttons:
| Sega Genesis   | JAMMA        |
|----------------|--------------|
| UP        	 | UP           |
| DOWN      	 | DOWN         |
| LEFT           | LEFT         |
| RIGHT 	     | RIGHT        |
| A              | 1            |
| B              | 2            |
| C              | 3            |
| X              | 4            |
| Y              | 5            |
| Z              | 6            |
| MODE           | COIN         |

## Requirements

- [jonthysell's SegaController library](https://github.com/jonthysell/SegaController);
- Arduino (tested only on Nano boards, other boards may need  the pin numbers in the code to be changed);
- Male DB9 connector.


## Hardware

Male DB9 Pinout (Front View): 
![alt text](https://www.consolesunleashed.com/sites/all/files/images/tech/sega-mega-drive/sega-mega-drive-controller-port-pinout.png)
 Source: [https://www.consolesunleashed.com/tech/sega-mega-drive/](https://www.consolesunleashed.com/tech/sega-mega-drive/)
 
 Respective arduino pins:
 
| DB9 Pin | Arduino Pin |
|---------|-------------|
| 1       | A0          |
| 2       | A1          |
| 3       | A2          |
| 4       | A3          |
| 5       | +5V         |
| 6       | A4          |
| 7       | D13         |
| 8       | GND         |
| 9       | A5          |

| Arduino Pin | JAMMA |
|-------------|-------|
| D1          | COIN  |
| D2          | UP    |
| D3          | DOWN  |
| D4          | LEFT  |
| D5          | RIGHT |
| D6          | 1     |
| D7          | 2     |
| D8          | 3     |
| D9          | 4     |
| D10         | 5     |
| D11         | 6     |
| D12         | START |


Wiring Diagram:
![alt text](https://github.com/MasterJhimmy/Sega-Genesis-to-JAMMA-controller-adapter/blob/main/wiring.jpg?raw=true)

## Software

After installing the "SegaController" library on your Arduino IDE, upload the code (SG_to_JAMMA.ino) to your board. If you experience random button presses, uncomment the first part of the "void setup()", which activates the software pull-up on the output connected to the JAMMA.

## Sources

Huge thanks to [jonthysell](https://github.com/jonthysell/) for their amazing library.

Also, thanks to [pcbjunkie](https://pcbjunkie.net/) for their ["ARDUINO GENESIS CONTROLLER INTERFACE"](https://pcbjunkie.net/index.php/guides/arduino-genesis-controller-interface/), which served me as a starting point for this project. 