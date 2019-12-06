# Interactive wall project

### Setting Up
* Flashing raspbian OS on an micro SD card to be used by the Raspberry Pi.
* Set all necessary configurations for raspberry pi on first time boot. (i.e country, time, language, wiFi)
* Password set is 'ombakdevhouse'
* Update software when prompted
* Configure and compiling openframeworks on raspberry pi https://openframeworks.cc/setup/raspberrypi/raspberry-pi-getting-started/
  **Important**: **Make sure to download Openframeworks version 0.10.0 and not the latest 0.11.0** To do this, everything that has 0.11.0 in     the commands should be changed to 0.10.0
* There will be an issue compiling OF. The solution is here https://forum.openframeworks.cc/t/rpi-4-raspbian-buster-openframeworks/32856/23
  Simply, 'ctrl f', search 'I compiled and ran the polygon example' and follow the changes written.
* Running the polygon example should be no issue.

### ofOMXPlayer
* Follow build instructions here https://github.com/jvcleave/ofxOMXPlayer
* Git clone the repo inside the addon folder in the openFrameworks directory
* CD into the ofOMXPlayer and type in 'sudo ./install_depends.sh'

### HDMI AUDIO
* CD into boot and edit the config.txt file
* Uncomment "hdmi_drive=2"


### Final steps
* Clone the repository shared to you into the /openFrameworks/apps/myApps folder.
* CD into interactiveWall.
* Open config.make and insert the required project flags as done in the **Setting up section for the polygon example**
* Run 'make clean' on the terminal in the wallApp directory
* Run 'make'.
* CD into bin and run the executable. (./interactiveWall)

### Expected Behavior
When launching this app, you should expect to see the animations playing with button presses or with the capacitive sensors.
(Key presss - q, w, e), to exit press r.




