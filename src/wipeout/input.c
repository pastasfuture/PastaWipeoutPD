#include "input.h"
#include "game.h"

#define INPUT_ACTION_MAX 32

static float actions_state[INPUT_ACTION_MAX];
static bool actions_pressed[INPUT_ACTION_MAX];
static bool actions_released[INPUT_ACTION_MAX];
float input_state(uint8_t action);
bool input_pressed(uint8_t action);
bool input_released(uint8_t action);
void input_update(PlaydateAPI* pd);

float input_state(uint8_t action) {
    return actions_state[action];
}

bool input_pressed(uint8_t action) {
    return actions_pressed[action];
}

bool input_released(uint8_t action) {
    return actions_released[action];
}

void input_update(PlaydateAPI* pd)
{
	PDButtons current;
	PDButtons pressed;
	pd->system->getButtonState(&current, &pressed, NULL);
	//if (current & kButtonA)
	//{
	//	pd->system->logToConsole("button A or B pushed");
	//}

	actions_state[A_THRUST] = (current & kButtonA) ? 1.0f : 0.0f;
	actions_pressed[A_THRUST] = (pressed & kButtonA) ? true : false;

	actions_state[A_UP] = (current & kButtonUp) ? 1.0f : 0.0f;
	actions_state[A_DOWN] = (current & kButtonDown) ? 1.0f : 0.0f;
	actions_state[A_LEFT] = (current & kButtonLeft) ? 1.0f : 0.0f;
	actions_state[A_RIGHT] = (current & kButtonRight) ? 1.0f : 0.0f;

	if ((current & (kButtonLeft | kButtonRight)) == 0)
	{
		// both air brakes when no direction is pressed
		actions_state[A_BRAKE_LEFT] = (current & kButtonB) ? 1.0f : 0.0f;
		actions_state[A_BRAKE_RIGHT] = (current & kButtonB) ? 1.0f : 0.0f;
	}
	else
	{
		// Directional breaking
		actions_state[A_BRAKE_LEFT] = (current & kButtonLeft) && (current & kButtonB) ? 1.0f : 0.0f;
		actions_state[A_BRAKE_RIGHT] = (current & kButtonRight) && (current & kButtonB) ? 1.0f : 0.0f;
	}
	

	actions_pressed[A_CHANGE_VIEW] = (pressed & kButtonA) && (pressed & kButtonB) ? true : false;
}