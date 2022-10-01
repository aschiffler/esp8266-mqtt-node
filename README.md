Quickstart 👇  Coding in the browser; Web-based flash-tool is included.

[![Click here to start your development environment](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/aschiffler/esp8266-mqtt-node)

# esp8266-mqtt-node

![](doc/esp8266_mosquitto_connection.png)

This repository holds a sample code and a corresponding platformIO project using the Arduino Framework to connect an esp8266 dev board to a mqtt broker.
The code is for demonstration purposes and directly uses hardcoded connection settings and credentials. So you have to customize at least the following lines in [main.cpp, lines 11-18](blob/main/src/main.cpp) and (re)build the firmware with **```pio run```** :
```c
//#define MQTT_TLS // uncomment this define to enable TLS transport
//#define MQTT_TLS_VERIFY // uncomment this define to enable broker certificate verification
const char* ssid = "YOUR-WIFI";
const char* password = "YOUR-WIFI-PSK";
const char* mqtt_server = "BROKER"; // eg. your-demo.cedalo.cloud or 192.168.1.11
const uint16_t mqtt_server_port = 1883; // or 8883 most common for tls transport
const char* mqttUser = "user";
const char* mqttPassword = "pass";
const char* mqttTopicIn = "esp-8266-in";
const char* mqttTopicOut = "esp-8266-out";
```
For the variable ```mqtt_server``` use either an ipv4 address or a domain name. Only ```tcp``` transport is supported (no WebSocket).
A detailed tutorial is available [here](https://cedalo.com/blog/)


# Overview
Various ESP8266 development boards exist and can be used to realize for example small and smart IoT applications (like [this](https://github.com/lumapu/ahoy)). The microcontroller needs to be flashed with a corresponding firmware to realize the application. 
Principal steps
1. Write and compile c/c++ code
2. Create the flashable firmware
3. Flash the firmware and test the application

## Use gitpod for browser-integrated development
For the steps sketched above you will need a IDE like Micorosft VSCode, the needed software frameworks, and libraries.
The setup of all this is already prepared here in this repository using gitpod. The only thing you need is a github account.

Click here 👇 to start your development environment.

[![Click here to start your development environment](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/aschiffler/esp8266-mqtt-node)

If you dislike using gitpod, follow the instructions to install and use the platformIO project within VSCode and clone this repository. (see as reference: [link](https://randomnerdtutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/))

## How to use gitpod
After starting the instance it takes a minute to be ready

![](doc/gitpod_pulling_image.png)

If the environment is ready it will look like the following image.

During the startup, the code is automatically compiled and the firmware is created. In the output area marked by 1️⃣ below, you will find the information about the build process and a link to a webpage where you can flash the firmware to your esp8266 development board.

![](doc/gitpod_overview.png)

### [Flash the firmware](#flash)
The successfully built firmware file will be in the folder ```esp-web-flash```  and is named ```firmware.bin```.
You can use the gitpod environment where a browser-based flash tool is integrated. Just follow the link marked by 1️⃣ (see above) and another tab will open:

![](doc/flash_tool.png)

Steps to flash the firmware:
1. Connect your esp8266 module via USB to the PC where the browser runs
2. Click connect
3. Choose the corresponding com port from the list and click connect
4. Click install ESP8266-MQTT-NODE or Logs&Console (see below)

![](doc/install_console_web_tool.png)

The installation of the firmware starts with eraseing the flash storage of the device (!).

![](doc/flash_firmware.png)

### Troubleshoot if your ESP device can not connect to the ESP-Browser-Flash-Tool
1. Make sure that the device is connected to this computer (the one that runs the browser that shows the website "ESP-BROWSER-FLASH-TOOL")
2. Most devices have a tiny light when it is powered on. If yours has one, make sure it is on.
3. Make sure that the USB cable you use can be used for data and is not a power-only cable.
4. Make sure you have the right drivers installed. Below are the drivers for common chips used in ESP devices:
- CP2102 drivers: Windows & Mac ([download](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers))
- CH342, CH343, CH9102 drivers: [Windows](https://www.wch.cn/downloads/CH341SER_ZIP.html), [Mac](https://www.wch.cn/downloads/CH34XSER_MAC_ZIP.html)
- CH340, CH341 drivers: [Windows](https://www.wch.cn/downloads/CH343SER_ZIP.html), [Mac](https://www.wch.cn/downloads/CH34XSER_MAC_ZIP.html)



### [Adjust, improve or extend the code](#edit)
Open the main source file ```main.cpp``` from folder ```src``` 2️⃣ do your edits and save the file 3️⃣. Then type in terminal 4️⃣ the command **```pio run```**. This shall start the compilation and the creation of the firmware. If successful you can go to the above section [Flash the firmware](#flash) to upload your modified firmware to your device.

## Usage of the console output
If you use the browser-based development environment you can use the ESP-Web-Flash-Tool also to monitor the serial output. A sample out put is shown below.

Connect to the device via the ESP-Browser-Flash-Tool and click on "Log&Console". Then click reset device so that the start of the console output can be capture in the opened window.

In the following screenshot you see the functionality of the sample application demonstrated. Therefore a pc-based mqtt-client-tool is connected to the mqtt broker. A message is published on "esp-8266-in" (default name) and your esp8266 device will respond to that with a message on the topic "esp-8266-out". The serial console output of the esp8266 can be seen on the window from the ESP-Browser-Flash-Tool.

![](doc/screen_mqtt_explorer_console.png)
