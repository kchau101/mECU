#ifndef MEGASQUIRT_PROTOCOL_H
#define MEGASQUIRT_PROTOCOL_H

#define MEGASQUIRT_RT_DATA_LENGTH 112
// The old ['a' 00 06] response format
typedef struct megasquirt_rt_data {
	uint16_t uptime;
	uint16_t bank1_pulse_width;
	uint16_t bank2_pulse_width;
	uint16_t rpm;
	int16_t spark_advance_deg;
	uint8_t squirt;
	uint8_t engine_status;
	uint8_t afrtgt_1; // Bank 1 AFR Target
	uint8_t afrtgt_2; // Bank 2 AFR Target
	/* Not used */
	uint8_t nc;
	uint8_t nc2;
	/************/
	int16_t baro_pressure;
	int16_t manifold_pressure;
	int16_t coolant_temp;
	int16_t throttle_position;
	int16_t battery_voltage;
	int16_t O2_afr_1;
	int16_t O2_afr_2;
	int16_t bank1_ego_correction;
	int16_t bank2_ego_correction;
	int16_t air_density_correction;
	int16_t warmup_correction;
	int16_t accel_enrichment;
	int16_t tps_fuel_cut;
	int16_t baro_correction;
	int16_t gamma_correction;
	int16_t bank1_volumetric_efficiency;
	int16_t bank2_volumetric_efficiency;
	int16_t idle_air_stepper_position;
	int16_t cold_advance_deg;
	int16_t tps_derivative;
	int16_t map_derivative;
	int16_t dwell_time_ms;
	int16_t maf;
	uint8_t load;
	int16_t fuel_correction;
	uint8_t io_status;
	uint8_t knock_retard;
	int16_t EAE_correction_1;
	int16_t o2sensor_1_voltage;
	int16_t o2sensor_2_voltage;
	int16_t not_used;
	int16_t not_used2;
	int16_t EAE_correction_2;
	int16_t not_used3;
	int16_t not_used4;
	int16_t not_used5;
	int16_t not_used6;
	int16_t not_used7;
	int16_t not_used8;
	int16_t not_used9;
	int16_t not_used10;
	int16_t not_used11;
	int16_t not_used12;
	uint16_t not_used13;
	uint8_t not_used14;
	uint8_t not_used15;
	uint32_t not_used16;
	/* End of implemented fields */
} Megasquirt_RT_Data;


#endif