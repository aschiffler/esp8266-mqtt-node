Import("env")
import os

print("Start")

def post_program_action(source, target, env):
    print("Firmware bin-file was built!")
    src_bin = env.subst("${BUILD_DIR}/${PROGNAME}.bin")
    os.rename(src_bin,"esp-web-flash/firmware.bin")
    print("-------------------------------------------------------")
    print("Follow this link (ctrl + click) to flash the firmware: ")
    url = os.system("gp url 3000");
    print("-------------------------------------------------------")
   

env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", post_program_action)

