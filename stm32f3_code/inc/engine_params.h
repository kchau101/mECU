#ifndef ENGINE_PARAMS_H
#define ENGINE_PARAMS_H

#include "uart.h"
#include "temperature.h"
/* Define the global system variables which define useful engine information. 
 * These will be visible to every state so there can be data passing between
 * states if necessary.*/

typedef enum pressure_unit {
	KPA, PSI, PSIG
} Pressure_Unit;

typedef struct pressure {
	uint16_t counts;
	float conversion_factor;
	Pressure_Unit units;
} Pressure;

typedef struct voltage {
	uint8_t counts;
	float conversion_factor;
} Voltage;

typedef struct air_volume {
	uint16_t counts;
	float conversion_factor;
} Air_Volume;

typedef enum boolean {
	ON, OFF
} Boolean;

typedef struct output {
	GPIO_TypeDef *gpio_port;
	uint16_t GPIO_Pin;
	Boolean active;
} Output;

typedef enum percentage {
	p00, p01, p02, p03, p04, 
	p05, p06, p07, p08, p09,
	p10, p11, p12, p13, p14,
	p15, p16, p17, p18, p19,
	p20, p21, p22, p23, p24,
	p25, p26, p27, p28, p29,
	p30, p31, p32, p33, p34,
	p35, p36, p37, p38, p39,
	p40, p41, p42, p43, p44,
	p45, p46, p47, p48, p49,
	p50, p51, p52, p53, p54,
	p55, p56, p57, p58, p59,
	p60, p61, p62, p63, p64,
	p65, p66, p67, p68, p69,
	p70, p71, p72, p73, p74,
	p75, p76, p77, p78, p79,
	p80, p81, p82, p83, p84,
	p85, p86, p87, p88, p89,
	p90, p91, p92, p93, p94,
	p95, p96, p97, p98, p99,
	p100
} Percentage;

typedef struct pwm_output {
	GPIO_TypeDef *gpio_port;
	uint16_t GPIO_Pin;
	Percentage duty_cycle;
} PWM_Output;

typedef struct injectors {
	Output injector_1;
	Output injector_2;
	Output injector_3;
	Output injector_4;
	Output injector_5;
	Output injector_6;
	Output injector_7;
	Output injector_8;
} Injectors;

typedef enum trim {
	trim_p00, trim_p01, trim_p02, trim_p03, trim_p04, 
	trim_p05, trim_p06, trim_p07, trim_p08, trim_p09,
	trim_p10, trim_p11, trim_p12, trim_p13, trim_p14,
	trim_p15, trim_p16, trim_p17, trim_p18, trim_p19,
	trim_p20, trim_p21, trim_p22, trim_p23, trim_p24,
	trim_p25, trim_n25, trim_n24, trim_n23, trim_n22,
	trim_n21, trim_n20, trim_n19, trim_n18, trim_n17,
	trim_n16, trim_n15, trim_n14, trim_n13, trim_n12,
	trim_n11, trim_n10, trim_n09, trim_n08, trim_n07,
	trim_n06, trim_n05, trim_n04, trim_n03, trim_n02,
	trim_n01
} Trim;

typedef struct system_vars {
	/**** System Inputs ****/
	uint16_t engine_rpm;
	Percentage throttle_percentage; /* 0-100 */
	Temperature coolant_temp;
	Temperature intake_air_temp;
	Voltage battery_voltage;
	Pressure barometric_presure;
	Boolean brake_pedal_depressed;
	Boolean ac_on;
	Boolean cooling_fan_on;
	Boolean blower_fan_on;
	Boolean headlights_on;
	Boolean power_steering_on;
	Boolean clutch_depressed;
	Boolean key_switch_crank; /* Engine crank state */
	Boolean key_switch_on; /* Are accessories on? Can also run diagnostics on sensors and injector which have power. */ 
	Air_Volume intake_air_volume; /* AFM Sensor Input, like vane-type on Miata; Measures air volume */
	Pressure manifold_abs_pressure; /* MAP Sensor Input */
	
	/**** System Outputs ****/
	Injectors fuel_injectors; 
	Output purge_solenoid;
	Output ac_relay;
	Output igniters[4];
	PWM_Output idle_speed_control;
	
	/**** Internal Data ****/
	/* To keep track of any data the ECU needs that's not directly pulled from a sensor. */
	uint16_t knock_count; /* Keep track how many knock events have occurred. */
	uint16_t misfire_count;
	Trim short_term_fuel_trim;
	Trim long_term_fuel_trim;
	
	/**** Debug Information ****/
	char debug_msg[81]; /* Used to store debug messages which can be read out with GDB. */
	Print printer; /* Printer object to control buffered serial prints */
} System_Vars;


#endif