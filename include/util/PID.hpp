#ifndef PID_H
#define PID_H

/*
 * This is a struct that contains PID parameters.
 */
typedef struct{
	float kP;
	float kI;
	float kD;
	float EpsilonInner;
	float EpsilonOuter;
	float dInner;
	float dOuter;
	float sigma;
	float lastValue;
	float lastTarget;
	unsigned long lastTime;
	float LastSetPoint;
} PID;

PID pidInit(float fKP, float fKI, float fKD, float fEpsilonInner, float fEpsilonOuter,float dInner, float dOuter);
float pidCalculate(PID pid, float fSetPoint, float fProcessVariable, float dt);

#endif