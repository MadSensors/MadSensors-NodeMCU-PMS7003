
# Wifi Credentials
The wifi credentials of the user must be stored in a file named "wifi_credentials.h". This file must not be uploaded to the git repository, otherwise the user's credentials will be comprimised. As such, the file will be included in the .gitignore and needs to be created by the user locally. The template for this file is as follows:

// MadSensors Token (Must be created using the MadSensors platform)\
#ifndef TOKEN\
#define TOKEN "INSERT_HERE"\
#endif

// Your WiFi Credentials (replace with your WiFi credentials)\
#ifndef WIFISSID\
#define WIFISSID "INSERT_HERE"\
#endif

#ifndef WIFIPASS\
#define WIFIPASS "INSERT_HERE"\
#endif

// Device Name (Must be created using the MadSensors platform)\
#ifndef DEVICE_NAME\
#define DEVICE_NAME "INSERT_HERE"\
#endif
