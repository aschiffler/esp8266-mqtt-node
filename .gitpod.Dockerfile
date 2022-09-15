FROM gitpod/workspace-full:2022-05-08-14-31-53

USER gitpod
RUN  pip install --upgrade platformio
RUN  pio pkg install -g --no-save -p espressif8266@4.0.1
RUN  pio pkg install -g --no-save -t toolchain-esp32ulp -t toolchain-xtensa  -t tool-cmake -t tool-ninja -t toolchain-xtensa-esp32 -t tool-esptoolpy -t framework-arduinoespressif8266 -t tool-scons
