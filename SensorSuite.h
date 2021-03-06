#ifndef _SensorSuite_
#define _SensorSuite_

// ECRobot++ API (http://lejos-osek.sourceforge.net/html/index.html)
#include "LightSensor.h"
//#include "SonarSensor.h"
#include "SoundSensor.h"
#include "TouchSensor.h"
#include "Clock.h"
#include "Motor.h"
#include "Nxt.h"

using namespace ecrobot;

//Light Sensor Stuff
// values for colored tape
#define WHITEHIGH 700
#define WHITELOW 550
#define GREYHIGH 540
#define GREYLOW 450
#define BLACKHIGH 420
#define BLACKLOW 0

#define GRY_CNT_THRESH 4

//Light Sensor Defines
#define isBlk(x) (x < BLACKHIGH && x >BLACKLOW)
#define isWht(x) (x < WHITEHIGH && x >WHITELOW)
#define isGry(x) (x < GREYHIGH && x >GREYLOW)

//typedef enum{BLACK, GREY, WHITE} Color;

extern "C" 
{

// Initialize Sensors
LightSensor  leftLight(PORT_3, true); // init light sensor ON
LightSensor  rightLight(PORT_1, true);
TouchSensor  touch(PORT_4);
bool Next = false;
//SonarSensor  sonar(PORT_2);

//Function Declarations
int GetLeftLightSen();
int GetRightLightSen();
int GetTouchSen();

} //End Extern C
#endif 
 
