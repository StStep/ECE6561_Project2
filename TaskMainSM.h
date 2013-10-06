#ifndef TASK_MAIN_SM_H
#define TASK_MAIN_SM_H

#include "StateMachine.h"
#include "MotorSuite.h"
#include "SensorSuite.h"
#include "LCDSuite.h"

//From Early Imp
extern "C" 
{

// structure to hold event data passed into state machine
struct LightData : public EventData
{
    int LeftLightSen;
    int RightLightSen;
};

/**Find State Declarations**/
typedef enum{FS_INIT, FS_ALIGN_BLACK, FS_ALIGN_WHITE, FS_ROTATE_ALIGN, FS_IDLE} FindSM_state;
FindSM_state Find_Next_State;
bool tape_flag = 0;

//Function
FindSM_state FS_rotate_align(int LeftLightSen, int RightLightSen);

/** Track State Declarations **/
typedef enum{TS_CRUISE, TS_ALIGN_GREY, TS_STEP, TS_ALIGN_GREY_RV, TS_STEP2, 
									   TS_ALIGN_GREY2, TS_STEP3, TS_ALIGN_GREY_RV2,
									   TS_WAYPOINT, TS_STEP4} TrackSM_state;
float RMMult = 1.00;
float LMMult = 1.00;
int GryCnt = 0;
TrackSM_state Track_Next_State;

//Function
TrackSM_state TS_cruise(int LeftLightSen, int RightLightSen);

}
 
// the MainTask state machine class
class TaskMainSM : public StateMachine
{
public:
    TaskMainSM() : StateMachine(ST_MAX_STATES) {}
 
    // external events taken by this state machine
    void Touch(LightData*);
    void Run(LightData*);
	void Reset();
private:
    // state machine state functions
	void ST_Start();
	void ST_Find(LightData*);	
	void ST_Track(LightData*);
	void ST_Idle();
 
    // state map to define state function order
    BEGIN_STATE_MAP
        STATE_MAP_ENTRY(&TaskMainSM::ST_Start)
		STATE_MAP_ENTRY(&TaskMainSM::ST_Find)
		STATE_MAP_ENTRY(&TaskMainSM::ST_Track)
		STATE_MAP_ENTRY(&TaskMainSM::ST_Idle)
    END_STATE_MAP
 
    // state enumeration order must match the order of state
    // method entries in the state map
    enum E_States { 
        ST_START = 0,
		ST_FIND,
		ST_TRACK,
		ST_IDLE,
        ST_MAX_STATES
    };
};
#endif //TASK_MAIN_SM_H