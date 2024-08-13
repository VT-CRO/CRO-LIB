/** 
 * @file PID.hpp
 * 
 * @author Jayson De La Vega, R&D Team
 * @date 
 * Last Modified: 1/24/2024
 * @brief  This file contains PID utiilty functions.
 * 
 * @details This file contains PID utility functions. Adapted from functions provided by Jay Katyan (jkatyan@vt.edu).
 */

#ifndef PID_H
#define PID_H

/** 
 * @struct PID
 * 
 * @brief This is a struct that contains PID parameters.
 */
typedef struct{
	float kP;	/**< Proportional gain */
	float kI;	/**< Integral gain */
	float kD;	/**< Derivative gain */
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

/**
 * @fn PID pidInit(float fKP, float fKI, float fKD, float fEpsilonInner, float fEpsilonOuter,float dInner, float dOuter)
 * 
 * @brief Initializes a PID instance.
 * 
 * This function returns a PID struct which can be used to calculate a PID signal.
 * 
 * @param fKP proportional gain
 * @param fKI integral gain
 * @param fKD derivative gain
 * @param fEpsilonInner uhhh, idk
 * @param fEpsilonOuter uhhh, idk
 * @param dInner uhhh, idk
 * @param douter uhhh, idk
 * 
 * @return an instance of PID parameters
 */
PID pidInit(float fKP, float fKI, float fKD, float fEpsilonInner, float fEpsilonOuter,float dInner, float dOuter);

/**
 * @fn float pidCalculate(PID pid, float fSetPoint, float fProcessVariable, float dt)
 * 
 * @brief Calculates PID signal
 * 
 * This function calculates a float signal based on given PID parameters and a set point.
 *
 * @param pid instance of PID structure
 * @param fSetPoint set point of PID controller
 * @param fProcessVariable sensor/feedback value
 * @param dt delta time from last pid calculation
 *
 * @return output value constrained from -255 to 255
 */
float pidCalculate(PID pid, float fSetPoint, float fProcessVariable, float dt);

#endif