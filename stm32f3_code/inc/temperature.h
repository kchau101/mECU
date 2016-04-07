#ifndef TEMPERATURE_H
#define TEMPERATURE_H
	typedef enum temp_unit {
		FAHRENHEIT, CELSIUS, RANKINE, KELVIN /* All the possible values which temperature can represent. */
	} Temp_Unit;
	 
	/* The temperature struct contains the value of a temperature reading in ADC counts,
	 * and also contains the conversion factor to the specified temp_unit */
	 typedef struct temperature {
		uint16_t counts;
		uint16_t conversion_factor;
		Temp_Unit units;
	 } Temperature;
	 
	 void initTemperature(Temperature *temp, uint16_t conversion_factor, Temp_Unit units);
	 uint16_t getTemperature(Temperature *temp );
 #endif