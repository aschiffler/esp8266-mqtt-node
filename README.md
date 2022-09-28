# Introduction for the esp8266-mqtt-node
This repository holds a sample code and a corresponding platformIO project using the Arduino Framework to connect a esp8266 dev board to a mqtt broker.
The code is for demonstration purposes and does directly use hardcoded connection settings and credentials. So you have to customize at least the following lines in [main.cpp, lines 11-18](blob/main/src/main.cpp) to use the code:
```c
const char* ssid = "WIFINAME";
const char* password = "WIFI_PASS";

const char* mqtt_server = "SERVER_IP";
const char* mqtt_server_port = "SERVER_PORT";
const char* mqttUser = "user";
const char* mqttPassword = "pass";
```
For the variable ```mqtt_server``` use either a ipv4 address or a domain name.

# Overview
Various exp8266 exists and can be used to realize eg. IoT applications. The microcontroller needs to be flashed with a corresponding firmware to realize the application. 
Principel steps
1. Write and compile c/c++ code
2. Create the flashable firmware
3. Flash the firmware and test the application

## Quickstart: Use gitpod for browser integrated development
For the steps sketch above you will need a IDE like Micorosft VSCode, the needed software frameworks and libraries.
The setup of all this is already prepared here in this repository by using gitpod. The only thing you need is a github account.

Click here 👇 to start your development environment.

[![Click here to start your development environment](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/aschiffler/esp8266-mqtt-node)

If you do not like to use gitpod, then follow the instructions to install and use the platformIO project within VSCode and clone this repository. (see as reference: [link](https://randomnerdtutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/))

## How to use gitpod
After starting the instance it takes a minute to be ready

![](doc/gitpod_pulling_image.png)

If the environment is ready it will look like the following image.

During the startup the code is automatically compiled and the firmware is created. In the output area marked by 1️⃣ below you will find the information about the build process and a link to a webpage where you can flash the firmware to your esp8266 development board.

![](doc/gitpod_overview.png)

### [Flash the firmware](#flash)
The succesful built firmware file will be in the folder ```esp-web-flash```  and is named ```firmware.bin```.
You can use the gitpod environment where a browser-based flash tool is integrated. Just follow the link marked by 1️⃣ (see above) and another tab will open:

![](doc/flash_tool.png)

Click connect and flash the firmware.

### [Adjust, improve or extend the code](#edit)
Open the main source file ```main.cpp``` from folder ```src``` 2️⃣ do your edits and save the file 3️⃣. Then type in the terminal 4️⃣ the command ```pio run```. This shall start the compilation and the creation of the firmware. If successful you can go to the above section [Flash the firmware](#flash) to upload your modified firmware to your device.
