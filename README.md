# Interactive wall project

![Screenshot of emptyExample](emptyExample.png)

### Setting Up
* Flashing raspbian OS on an micro SD card to be used by the Raspberry Pi.
* Set all necessary configurations for raspberry pi on first time boot. (i.e country, time, language, wiFi)
* Password set is 'ombakdevhouse'
* Update software when prompted
* Configure and compiling openframeworks on raspberry pi https://openframeworks.cc/setup/raspberrypi/raspberry-pi-getting-started/
* There will be an issue compiling OF. The solution is here https://forum.openframeworks.cc/t/rpi-4-raspbian-buster-openframeworks/32856/23
  Simply, 'ctrl f', search 'I compiled and ran the polygon example' and follow the changes written.
* Running the polygon example should be no issue

### ofOMXPlayer
* Follow build instructions here https://github.com/jvcleave/ofxOMXPlayer
* Git clone the repo inside the addon folder in the openFrameworks directory
* CD into the ofOMXPlayer and type in 'sudo ./install_depends.sh'

### HDMI AUDI0
* CD into boot and edit the config.txt file
* Uncomment "hdmi_drive=2"
* Additionally change gpu_mem to 


### Expected Behavior

When launching this app, you should see a light-gray screen. 

* There's no interaction. 
* There's nothing to see. 
* That's it. 

Instructions for using the app:

* There's nothing to do. Move along.

### Other classes used in this file

This example uses no other classes.
