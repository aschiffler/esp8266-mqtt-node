Import("env")
import os

print("Start")

def post_program_action(source, target, env):
    print("Firmware bin-file was built!")
    #os.rename(src, dst)
    src_bin = env.subst("${BUILD_DIR}/${PROGNAME}.bin")
    os.rename(src_bin,"esp-web-flash/firmware.bin")
    print("Firmware bin-file was moved to Web-Flash-Tool root folder.")
   

env.AddPostAction("$BUILD_DIR/${PROGNAME}.bin", post_program_action)

