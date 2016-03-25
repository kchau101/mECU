#ifndef ENGINE_PARAMS_H
#define ENGINE_PARAMS_H

/* Define the global system variables which define useful engine information. 
 * These will be visible to every state so there can be data passing between
 * states if necessary.*/
 
 typedef enum temp_unit {
	 FAHRENHEIT, CELSIUS, RANKINE, KELVIN /* All the possible values which temperature can represent. */
 } Temp_Unit;
 
 typedef struct temperature_tenths {
	 uint16_t value; /* The value of the temperature in tenths of a unit */
	 Temp_Unit units;
 } Temperature;
 
typedef union barometric_pressure {
	uint16_t units_kPa;
	uint16_t 
}
 
typedef struct system_vars {
	uint16_t engine_rpm;
	uint8_t throttle_percentage; /* 0-100 */
	Temperature coolant_temperature;
	uint8_t battery_voltage;
	
} System_Vars;


#endif