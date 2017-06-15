/*
 * IPX_BipolarDriver.h
 *
 * Created: 29-May-17 10:42:04 AM
 *  Author: ScorpionIPX
 */ 


#ifndef IPX_BIPOLARDRIVER_H_
#define IPX_BIPOLARDRIVER_H_

#include <avr/io.h>

#define MOTOR_PORT PORTB
#define MOTOR_DDR DDRB
#define MOTOR_COIL_A_POSITIVE PB0
#define MOTOR_COIL_A_NEGATIVE PB1
#define MOTOR_COIL_B_POSITIVE PB2
#define MOTOR_COIL_B_NEGATIVE PB3

#define MOTOR_STEP_1 MOTOR_PORT &= ~((1 << MOTOR_COIL_A_NEGATIVE) | (1 << MOTOR_COIL_B_POSITIVE) | (1 << MOTOR_COIL_B_NEGATIVE)); MOTOR_PORT |= (1 << MOTOR_COIL_A_POSITIVE)
#define MOTOR_STEP_2 MOTOR_PORT &= ~((1 << MOTOR_COIL_A_POSITIVE) | (1 << MOTOR_COIL_A_NEGATIVE) | (1 << MOTOR_COIL_B_NEGATIVE)); MOTOR_PORT |= (1 << MOTOR_COIL_B_POSITIVE)
#define MOTOR_STEP_3 MOTOR_PORT &= ~((1 << MOTOR_COIL_A_POSITIVE) | (1 << MOTOR_COIL_B_POSITIVE) | (1 << MOTOR_COIL_B_NEGATIVE)); MOTOR_PORT |= (1 << MOTOR_COIL_A_NEGATIVE)
#define MOTOR_STEP_4 MOTOR_PORT &= ~((1 << MOTOR_COIL_A_POSITIVE) | (1 << MOTOR_COIL_B_POSITIVE) | (1 << MOTOR_COIL_A_NEGATIVE)); MOTOR_PORT |= (1 << MOTOR_COIL_B_NEGATIVE)

#define SET_COIL_A_POSITIVE MOTOR_PORT |= 1 << MOTOR_COIL_A_POSITIVE
#define SET_COIL_A_NEGATIVE MOTOR_PORT |= 1 << MOTOR_COIL_A_NEGATIVE
#define SET_COIL_B_POSITIVE MOTOR_PORT |= 1 << MOTOR_COIL_B_POSITIVE
#define SET_COIL_B_NEGATIVE MOTOR_PORT |= 1 << MOTOR_COIL_B_NEGATIVE

#define RESET_COIL_A_POSITIVE MOTOR_PORT &= ~(1 << MOTOR_COIL_A_POSITIVE)
#define RESET_COIL_A_NEGATIVE MOTOR_PORT &= ~(1 << MOTOR_COIL_A_NEGATIVE)
#define RESET_COIL_B_POSITIVE MOTOR_PORT &= ~(1 << MOTOR_COIL_B_POSITIVE)
#define RESET_COIL_B_NEGATIVE MOTOR_PORT &= ~(1 << MOTOR_COIL_B_NEGATIVE)

#define MOTOR_OFF MOTOR_PORT &= ~((1 << MOTOR_COIL_A_POSITIVE) | (1 << MOTOR_COIL_A_NEGATIVE) | (1 << MOTOR_COIL_B_POSITIVE) | (1 << MOTOR_COIL_B_NEGATIVE))

void init_bipolar_control(void);
void bipolar_wave_drive_forward();
void bipolar_high_torque_full_step_drive_forward();
void bipolar_forward_half_step_drive_forward();
void set_angle(uint16 degrees, uint8 direction);
void bipolar_wave_drive_forward_one_step();
void bipolar_wave_drive_backward_one_step();
void spin_to_angle();

#endif /* IPX_BIPOLARDRIVER_H_ */