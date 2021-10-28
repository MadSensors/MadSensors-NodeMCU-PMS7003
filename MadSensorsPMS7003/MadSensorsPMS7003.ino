// MadSensors - Send PMS7003 Data Example
//
// Authors: Jose Zorrilla <jose@madsensors.com>, Brendan Munoz <brenmun00@gmail.com>
// Website: https://madsensors.com
// Description: This example reads the PM 1.0, 2.5 and 10.0 data from a
// This sketch is only to show how to use the PMS7003 with the MadSensors library for ESP8266
// The "pms.h" source code is based on the following Tutorial by Mr. Alam from: https://how2electronics.com/interfacing-pms5003-air-quality-sensor-arduino/#PMS5003_Air_Quality_Sensor
// Variables such as TOKEN, WIFISSID, WIFIPASS and DEVICE_NAME have been omitted and can be defined manually in the "sensitive_data.h" header

#include <MadSensors-esp8266.h>
#include <SoftwareSerial.h>
#include "wifi_credentials.h"
#include "pms.h"

// Assign D1 and D2 to pms7003 serial port
SoftwareSerial pmsSerial(4, 5);

// Create the MadSensors object
MadSensor madSensor(DEVICE_NAME, TOKEN);

long lastPing = 0;
void setup()
{
  // Connect to the WiFi network
  madSensor.connectWifi(WIFISSID, WIFIPASS);
  pmsSerial.begin(9600);
}
void loop()
{
  // Send a value every 30 seconds
  if ((millis() - lastPing) > 30000)
   {  
    // Read PM 1.0, 2.5 and 10.0 data
    if (readPMSdata(&pmsSerial)){
    pms10_particle_data =data.particles_10um; //1.0 um
    pms25_particle_data =data.particles_25um; //2.5 um
    pms100_particle_data =data.particles_100um; //20.0 um
    }
    // Add pm 1.0, 2.5 and 10.0 particle data to 
    madSensor.addNewValue("pm_1", pms10_particle_data);
    madSensor.addNewValue("pm_2_5", pms25_particle_data);
    madSensor.addNewValue("pm_10", pms100_particle_data);

    // Shows the payload
    Serial.print("JSON Payload: ");
    Serial.println(madSensor.getPOSTrequest());

    // Send the value to the MadSensor server
    Serial.print("Server Reply: ");
    Serial.println(madSensor.sendAll());

    lastPing = millis();
   }
}
