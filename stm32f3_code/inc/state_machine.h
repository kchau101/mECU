#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include "engine_params.h"
 
typedef enum state {ILLEGAL_STATE, RDY_STATE, 
					INIT_STATE, IDLING_STATE, CRANKING_STATE,
					NUM_STATES} State;
typedef State (*state_ptr)(System_Vars*);
typedef struct state_machine {
	State current_state;
	state_ptr state_table[NUM_STATES];
} State_Machine;
/* Define an illegal state, should we accidently switch to it for some reason */
State illegal_state(System_Vars*);

#endif