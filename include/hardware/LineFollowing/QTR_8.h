/**
 * @file QTR_8.h
 * 
 * @author your name (you@domain.com)
 * @brief Header file for QTR8 sensor definitions
 * @date 2024-07-31
 * 
 * The QTR8 sensor is an array of infrared sensors. This file contains functions
 * for applications of the QTR8 sensor in line-following.
 */
#ifndef QTR_8_H
#define QTR_8_H

#include <stdint.h>
#include <arduino_freertos.h>
#include <atomic>

/** Number of Sensors (TODO: Move to hardware defs) */
#define NUM_SENSORS 16

/** Threshold */
#define QTR_THRESHOLD 0.5

/**
 * @brief Struct object representing QTR8 sensor
 * 
 * Treat all QTR_8 members as private!
 */
typedef struct
{
  uint16_t* pins; /**< The struct pins as an array */
  uint16_t* data; /**< The data for each pin as an array */
  uint16_t sampleSize; /**< The number of samples to take for each pin */

  /** Callback function */
  void (*qtr_cb)(uint16_t);
} QTR_8_t;

/**
 * @brief Initialize a QTR struct object
 * 
 * @param qtr_ptr QTR object to initialize
 * @param pins the pins array
 * @param sampleSize the sample size
 * @return true if successful, false if failed
 */
bool QTR_8_init(QTR_8_t* qtr_ptr, uint16_t* pins, uint16_t sampleSize);

/**
 * @brief Find the center of the line of the QTR
 * 
 * @param qtr_ptr QTR object
 * @return center position of QTR as a double
 */
double QTR_8_findPos(QTR_8_t* qtr_ptr);

/**
 * @brief Update QTR_8 data array
 * 
 * @param qtr_ptr QTR object to update
 */
void QTR_8_sensorRead(QTR_8_t* qtr_ptr);

#endif