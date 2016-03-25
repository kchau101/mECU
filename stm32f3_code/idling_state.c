#include "idling_state.h"

int idling_state(void) {
	// Idle state, do nothing
	const char* state_desc = "IDLING";
	char a = 0;
	while (a < 254) 
	{
		a++;
	}
	return IDLING_STATE;
}