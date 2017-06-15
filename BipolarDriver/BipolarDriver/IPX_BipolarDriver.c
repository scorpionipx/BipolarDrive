/*
 * IPX_BipolarDriver.c
 *
 * Created: 29-May-17 10:41:49 AM
 *  Author: ScorpionIPX
 */ 

#include "Global.h"
#include "IPX_BipolarDriver.h"
#include <util/delay.h>
#include <stdlib.h>


void set_angle(uint16 degrees, uint8 direction)
{
	
}

void init_bipolar_control(void)
{
	MOTOR_DDR |= (1 << MOTOR_COIL_A_POSITIVE) | (1 << MOTOR_COIL_A_NEGATIVE) | (1 << MOTOR_COIL_B_POSITIVE) | (1 << MOTOR_COIL_B_NEGATIVE);
	MOTOR_PORT &= ~((1 << MOTOR_COIL_A_POSITIVE) | (1 << MOTOR_COIL_A_NEGATIVE) | (1 << MOTOR_COIL_B_POSITIVE) | (1 << MOTOR_COIL_B_NEGATIVE));
}


void spin_to_angle()
{
	if((abs(ANGLE - DESIRED_ANGLE) > (STEP_DEGREES / 2)) && (ANGLE < DESIRED_ANGLE))
	{
		bipolar_wave_drive_forward_one_step();
		ANGLE += STEP_DEGREES;
	}
	if((abs(ANGLE - DESIRED_ANGLE) > (STEP_DEGREES / 2)) && (ANGLE > DESIRED_ANGLE))
	{
		bipolar_wave_drive_backward_one_step();
		ANGLE -= STEP_DEGREES;
	}
	_delay_ms(2);
}

void bipolar_wave_drive_forward_one_step()
{
	switch(LAST_STEP)
	{
		case BIPOLAR_STEP_1:
		{
			MOTOR_STEP_2;
			LAST_STEP = BIPOLAR_STEP_2;
			break;
		}
		case BIPOLAR_STEP_2:
		{
			MOTOR_STEP_3;
			LAST_STEP = BIPOLAR_STEP_3;
			break;
		}
		case BIPOLAR_STEP_3:
		{
			MOTOR_STEP_4;
			LAST_STEP = BIPOLAR_STEP_4;
			break;
		}
		case BIPOLAR_STEP_4:
		{
			MOTOR_STEP_1;
			LAST_STEP = BIPOLAR_STEP_1;
			break;
		}
		default:
		{
			LAST_STEP = BIPOLAR_STEP_1;
			break;
		}
	}
}

void bipolar_wave_drive_backward_one_step()
{
	switch(LAST_STEP)
	{
		case BIPOLAR_STEP_1:
		{
			MOTOR_STEP_4;
			LAST_STEP = BIPOLAR_STEP_4;
			break;
		}
		case BIPOLAR_STEP_2:
		{
			MOTOR_STEP_1;
			LAST_STEP = BIPOLAR_STEP_1;
			break;
		}
		case BIPOLAR_STEP_3:
		{
			MOTOR_STEP_2;
			LAST_STEP = BIPOLAR_STEP_2;
			break;
		}
		case BIPOLAR_STEP_4:
		{
			MOTOR_STEP_3;
			LAST_STEP = BIPOLAR_STEP_3;
			break;
		}
		default:
		{
			LAST_STEP = BIPOLAR_STEP_1;
			break;
		}
	}
}

void bipolar_wave_drive_forward()
{
	unsigned int STEP_DELAY_MS = 250;
	
	MOTOR_STEP_1;
	_delay_ms(STEP_DELAY_MS);
	
	MOTOR_STEP_2;
	_delay_ms(STEP_DELAY_MS);
	
	MOTOR_STEP_3;
	_delay_ms(STEP_DELAY_MS);
	
	MOTOR_STEP_4;
	_delay_ms(STEP_DELAY_MS);
}


void bipolar_high_torque_full_step_drive_forward()
{
	unsigned int STEP_DELAY_MS = 100;
	
	SET_COIL_A_POSITIVE;
	RESET_COIL_A_NEGATIVE;
	RESET_COIL_B_POSITIVE;
	SET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);
	
	SET_COIL_A_POSITIVE;
	RESET_COIL_A_NEGATIVE;
	SET_COIL_B_POSITIVE;
	RESET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);
	
	RESET_COIL_A_POSITIVE;
	SET_COIL_A_NEGATIVE;
	SET_COIL_B_POSITIVE;
	RESET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);
	

	RESET_COIL_A_POSITIVE;
	SET_COIL_A_NEGATIVE;
	RESET_COIL_B_POSITIVE;
	SET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);
	
}

void bipolar_forward_half_step_drive_forward()
{
	unsigned int STEP_DELAY_MS = 10;
	
	SET_COIL_A_POSITIVE;
	RESET_COIL_A_NEGATIVE;
	RESET_COIL_B_POSITIVE;
	SET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);
	
	SET_COIL_A_POSITIVE;
	RESET_COIL_A_NEGATIVE;
	RESET_COIL_B_POSITIVE;
	RESET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);
	
	SET_COIL_A_POSITIVE;
	RESET_COIL_A_NEGATIVE;
	SET_COIL_B_POSITIVE;
	RESET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);

	RESET_COIL_A_POSITIVE;
	RESET_COIL_A_NEGATIVE;
	SET_COIL_B_POSITIVE;
	RESET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);
	
	RESET_COIL_A_POSITIVE;
	SET_COIL_A_NEGATIVE;
	SET_COIL_B_POSITIVE;
	RESET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);
	
	RESET_COIL_A_POSITIVE;
	SET_COIL_A_NEGATIVE;
	RESET_COIL_B_POSITIVE;
	RESET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);
	
	RESET_COIL_A_POSITIVE;
	SET_COIL_A_NEGATIVE;
	RESET_COIL_B_POSITIVE;
	SET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);

	RESET_COIL_A_POSITIVE;
	RESET_COIL_A_NEGATIVE;
	RESET_COIL_B_POSITIVE;
	SET_COIL_B_NEGATIVE;
	_delay_ms(STEP_DELAY_MS);
	
}

