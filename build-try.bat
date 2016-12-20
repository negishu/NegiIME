ant debug -Dsdk.dir=%ANDROID_SDK_ROOT%

adb uninstall negi.android

adb install ./bin/NegiIME-debug.apk

