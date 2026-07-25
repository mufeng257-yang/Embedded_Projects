#include "pid.h"

void PID_Init(PID_TypeDef *pid, float kp, float ki, float kd, float max, float min)
{
    pid->Kp = kp;
    pid->Ki = ki;
    pid->Kd = kd;
    pid->integral = 0.0f;
    pid->last_error = 0.0f;
    pid->output_max = max;
    pid->output_min = min;
}
PID_TypeDef jiaoduhuan;
PID_TypeDef Aspeedhuan;
PID_TypeDef Bspeedhuan;
float PID_Compute(PID_TypeDef *pid, float setpoint, float measurement)
{
    float error = setpoint - measurement;
    float proportional = pid->Kp * error;
	
    if (pid->Ki != 0.0f) {
				pid->integral +=error+pid->last_error;
				
        float limit = pid->output_max / pid->Ki;
        if (pid->integral > limit) pid->integral = limit;
        else if (pid->integral < -limit) pid->integral = -limit;
    } else {
        pid->integral = 0.0f;
    }
    float integral_out = pid->Ki * pid->integral;
		
    float derivative; 
		derivative=pid->Kd *(error-pid->last_error);
		pid->last_error=error;
    float output = proportional + integral_out + derivative;
    if (output > pid->output_max) output = pid->output_max;
    else if (output < pid->output_min) output = pid->output_min;
    return output;
}
void PID_Reset(PID_TypeDef *pid)
{
    pid->integral = 0.0f;
    pid->last_error = 0.0f;
}
