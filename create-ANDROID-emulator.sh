#!/bin/sh
echo "where /root/Android/Sdk is the android-studio install dir"




echo '
export ANDROID_SDK_HOME=/root/Android/Sdk
export PATH=$PATH:/usr/lib64/ccache:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/var/lib/snapd/snap/bin:/usr/bin/gradle-6.5.1/bin:/root/Android/Sdk/tools/bin:/root/Android/Sdk/tools:/root/Android/Sdk/platform-tools/:/root/Android/Sdk/build-tools/29.0.2/:/root/Android/Sdk/tools/bin/
' >> /root/.bashrc

source /root/.bashrc





sdkmanager --install "platforms;android-29"
sdkmanager --install "build-tools;29.0.2"
sdkmanager --install "system-images;android-29;google_apis_playstore;x86"
echo "no" | avdmanager --verbose create avd --force --name Nexus --abi google_apis_playstore/x86 --package "system-images;android-29;google_apis_playstore;x86"


echo '
#!/bin/bash
cd /root/Android/Sdk/emulator
QTWEBENGINE_DISABLE_SANDBOX=1 ./emulator @Nexus -no-boot-anim -netdelay none -no-snapshot -wipe-data -skin 768x1280 & 
' > /usr/bin/EMULATOR
chmod +x EMULATOR

echo "/usr/bin/EMULATOR should spawn a Nexus style android emulator run adb install apkfilename.apk or "adb shell" then "logcat" to inspect running emulator, apk"
