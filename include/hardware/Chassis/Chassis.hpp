/** 
 * @file Chassis.hpp
 * 
 * @author Jayson De La Vega, R&D Team
 * @brief  This file contains class declarations for a meccanum chassis object
 * @date 2024-01-24
 */
#ifndef CHASSIS_H
#define CHASSIS_H

#include "arduino_freertos.h"
#include "queue.h"

#include "ros.h"
#include "geometry_msgs/Twist.h"

#include "hardware/Motor/MotorControl.h"

#define NUM_MOTORS 4
#define tskCHASSIS_PRIORITY 1

/**
 * @struct Chassis_t
 * 
 * @brief This class specifies the class interface for the chassis.
 * 
 * This class provides a class interface for a non-holonomic chassis 
 * with meccanum wheels.
 * The chassis, with the corresponding wheel numbers is as such:
 * @verbatim
              ^  +x
              |
       [1]---------[2]
        |   Front   |
 y <--- |     x z+  |
        |           |
       [4]---------[3]
   @endverbatim
 *
 */
typedef struct {
  MotorControl* m1;	/**< Motor 1 */
  MotorControl* m2;	/**< Motor 2 */
  MotorControl* m3;	/**< Motor 3 */
  MotorControl* m4;	/**< Motor 4 */

  uint16_t velocityCorrection;	/**< state variable for velocity correction when line following */
  double velocityCorrectionGain;	/**< velocity correction gain */
} Chassis_t;

/**
 * @brief Initializes chassis object
 * 
 * @param chassis_ptr The chassis object to be initialized
 */
void Chassis_init(Chassis_t* chassis_ptr);

/**
 * @brief Sets line following error for Chassis drive control
 * 
 * @param chassis_ptr The chassis object
 * @param err The line following error
 */
void Chassis_setVelocityCorrection(Chassis_t* chassis_ptr, uint16_t err);

/**
 * @brief Calculates Chassis wheel speeds from a velocity command
 * 
 * @param chassis_ptr The chassis object
 * @param cmd_vel The command velocity as a ROS geometry_msgs/Twist
 */
void Chassis_meccanum_kinematics(Chassis_t* chassis_ptr, geometry_msgs::Twist cmd_vel);

#endif // !CHASSIS_H
