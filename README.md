# MadSensors-NodeMCU-PMS7003

## Introduction
This project utilises a Plantower PMS7003 particulate matter sensor and a NodeMCU ESP8266-12E to remotely send live air-quality data to MadSensor's "NodeMCUBrendan" Dashboard. The data consists of PM 1.0, PM 2.5 and PM 10.0 particle readings which are plotted overtime at 30 second intervals. This file will go throught the steps on how to set up both the NodeMCU and the PMS7003 to then be used with the provided code.

## NodeMCU with Arduino IDE
For this project, the NodeMCU will be programmed in the Arduino IDE and as such ESP8266-12E suppourt must be installed. The steps to do so are as follows:
- In the Arduino IDE: select "File > Preferences" and paste <http://arduino.esp8266.com/stable/package_esp8266com_index.json> into the "Additional Boards Manager URLs:" field then click "OK".
![image](https://user-images.githubusercontent.com/49784557/111945605-1e6abc00-8b2e-11eb-8752-3b1e4bd85be9.png)
- From this, select "Tools > Board > Boards Manager..." to open the Boards Manager to then search and install "ESP8266 by ESP8266 Community"
![image](https://user-images.githubusercontent.com/49784557/111949097-35141180-8b34-11eb-961e-af17a872858a.png)
Now that NodeMCU suppourt is installed, the "ESP-12E Module" Board can be selected by going to "Tools > Board > NodeMCU 1.0 (ESP-12E Module)".

## Plantower PMS7003
The PMS7003 is a particle concentration sensor which can be used to obtain the number of suspended particles in the air. This is accomplished using laser scattering, in which a laser is used to radiate the suspending particles in the air and the curve of scattering light change overtime can be found. From this, equivalent particle diameter and the number of particles with different diameter per unit volume can be calculated using the sensor's built-in microprocessor. The datasheet for this sensor provides the following functional diagram:
![image](https://user-images.githubusercontent.com/49784557/111959957-3dc01400-8b43-11eb-89e6-76f510b0dc74.png)

The Pin Definitions for the PMS7003 can be found in its datasheet:

![image](https://user-images.githubusercontent.com/49784557/111960871-6563ac00-8b44-11eb-892d-cef19db42e58.png)

Where:
- Pin 1 and 2 are 5V
- Pin 3 and 4 are GND
- Pins 6 and 8 are not connected
- Pin 7 and 9 are the Serial Port RX and TX, and
- Pin 10 and 5 are SET and RESET 

For more information about the PMS7003 sensor, the datasheet can be found [here](https://download.kamami.com/p564008-p564008-PMS7003%20series%20data%20manua_English_V2.5.pdf).

## Connecting the PMS7003 to the NodeMCU
The PMS7003 datasheet provides a circuit diagram of the PMS7003 connected to a generic Host MCU. This is how the sensor will be connected to the NodeMCU, with some minor modifications. For this project, only VCC, GND, RX and TX will be needed. Therefore, the pins being used on the NodeMCU will be Vin (5V), GND and D1 (GPIO4) as well as D2 (GPIO5) for the RX and TX pins. From this, the NodeMCU and the PMS7003 should be ready to use with the provided code.

![image](https://user-images.githubusercontent.com/49784557/111967222-e4101780-8b4b-11eb-9d5e-29a14caffb67.png)

![image](https://user-images.githubusercontent.com/49784557/111967713-7adcd400-8b4c-11eb-8498-7f48905b4c9f.png)
