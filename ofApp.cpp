#include "ofApp.h"
#include "wiringPi.h"
#include "ofxOMXPlayer.h"
string videoName[6] = {ofToDataPath("/home/pi/openFrameworks/apps/myApps/interactiveWall/bin/data/_solarfarm.mp4"),
	ofToDataPath("/home/pi/openFrameworks/apps/myApps/interactiveWall/bin/data/_building.mp4"),
	ofToDataPath("/home/pi/openFrameworks/apps/myApps/interactiveWall/bin/data/_paint.mp4"),
	ofToDataPath("/home/pi/openFrameworks/apps/myApps/interactiveWall/bin/data/_lights.mp4"),
	ofToDataPath("/home/pi/openFrameworks/apps/myApps/interactiveWall/bin/data/_lightsaber.mp4"),
	ofToDataPath("/home/pi/openFrameworks/apps/myApps/interactiveWall/bin/data/_washingmachine.mp4")};


int videoDimension[6][2]={{1506,966},{556,864},{1196,302},{172,284},{660,712},{558,558}};


bool sensor0 = false;
bool sensor1 = false;
bool sensor2 = false;
int i = 0;
int j = 0;
ofxOMXPlayerSettings settings[6];

//--------------------------------------------------------------
void ofApp::setup(){

	if(wiringPiSetup() == -1){
		printf("Error on wiringPi setup\n");
	}
	
	pinMode(0,INPUT);
	pinMode(3,INPUT);
	pinMode(21,INPUT);
	//pinMode(21,INPUT);
	//pinMode(22,INPUT);
	//pinMode(23,INPUT);
    ofSetFrameRate(60);
    ofBackground(0, 0, 0);
    //first video
    for(i = 0; i<6; i++){
		
    settings[i].videoPath = videoName[i];
	settings[i].useHDMIForAudio = true;	//default true
	settings[i].enableTexture = true;		//default true
	settings[i].enableLooping = false;		//default true
	settings[i].enableAudio = true;		//default true, save resources by disabling
}
	ofSetOrientation(OF_ORIENTATION_180);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(digitalRead(0)){
	omxPlayer[0].setup(settings[0]);
	    omxPlayer[1].setup(settings[1]);
	   
    }
    for(j = 0; j<6; j++)
    {
	if(!omxPlayer[j].isPlaying())
	{
	    omxPlayer[j].close();
	}
    }
	
 if(digitalRead(3)){
	omxPlayer[2].setup(settings[2]);
	    omxPlayer[3].setup(settings[3]);
	   
	}
 if(digitalRead(21)){
	omxPlayer[4].setup(settings[4]);
	    omxPlayer[5].setup(settings[5]);
	}
	
	//  bool isPlaying();
	//  bool videoHasEnded;
	// void play();
    // void stop();
	//  void SetOrientation(int degreesClockWise, bool doMirror=false);
}
//--------------------------------------------------------------
void ofApp::draw(){
    omxPlayer[0].draw(170,ofGetWindowHeight()-476*1.4,746*1.4, 476*1.4); //solar
    omxPlayer[1].draw(ofGetWindowWidth()-678,0,678, ofGetWindowHeight()); //building
    omxPlayer[2].draw(0,0,600*2, 140*2); //KK
    omxPlayer[3].draw(0, 750, 84*1.8, 138*1.8); //Lamp
    omxPlayer[4].draw(465,140,328*0.7, 350*0.7); //light saber
    omxPlayer[5].draw(930,250,176*1.7, 242*1.7); //washing machine
    //ofDrawBitmapString(to_string(ofGetMouseX())+","+to_string(ofGetMouseY()), 10, 10);
    //ofDrawBitmapString(omxPlayer[0].getInfo(), 10, 300);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
     switch(key)
        {
                //triggers parachute animation
            case 'q':
				omxPlayer[0].setup(settings[0]);
	    omxPlayer[1].setup(settings[1]);
                break;
	     case 'w':
		     omxPlayer[2].setup(settings[2]);
	    omxPlayer[3].setup(settings[3]);
		     break;
	     case 'e':
		     omxPlayer[4].setup(settings[4]);
	    omxPlayer[5].setup(settings[5]);
		    break;
        }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
