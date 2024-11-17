/**
 * @file QDC_Encoder.h
 * @author Jayson De La Vega, R&D Team
 * @brief This file contains declarations for an QDC Encoder
 * @date 2024-07-31
 * 
 * This file contains class and function declarations for an encoder based on
 * the QDC (Quadrature Decoder) peripheral.
 * 
 * The QDC is a module within Teensy 4.x that decodes quadrature signals, eliminating
 * the need to parse the signal in code. This is for hall-effect mmotor encoders
 * (one of the more common variants for hobbyist applications), which typically emit
 * quadrature signals. The Teensy's QDC module also contains registers which are
 * specifically suited for motor encoder applications.
 * 
 */
#ifndef QDC_ENCODER_H
#define QDC_ENCODER_H

#include "arduino_freertos.h"
#include "hardware/QDC/QDC.h"

/**
 * @brief This macro defines the maximum number of encoder instances that the user may instantiate at a time.
 * 
 * The Teensy 4.x contains 4 QDC channels, so only 4 QDC Encoders may be instantiated at a time.
 */
#define MAX_NUM_ENCODER_INSTANCES 4


/**
 * @brief A struct to store the state of the encoder
 */
typedef struct Encoder_state_t {
  int pos; /**< The position of the encoder */
  int posDiff; /** The difference in position from the last encoder read */
} QDC_Encoder_state_t;

/**
 * @brief This class represents an Encoder based on the Teens 4.x QDC peripheral.
 */
class QDC_Encoder {
public:

  /**
   * @brief A typedef for QDC_isr functions
   */
  typedef void(*QDC_isr)();

  /**
   * @brief Construct a new QDC Encoder object.
   * 
   * TODO: Explain what each pin does
   * 
   * @param channel The QDC channel to use (between 1-MAX_NUM_ENCODER_INSTANCES)
   * @param phaseA PhaseA signal pin number
   * @param phaseB PhaseB signal pin numer
   * @param index Index signal pin number
   * @param home Home pin number
   * @param trigger Trigger pin number
   * @param pin_pus TODO
   */
  QDC_Encoder(uint8_t channel, uint8_t phaseA, uint8_t phaseB, uint8_t index, uint8_t home, uint8_t trigger, uint8_t pin_pus);

  /**
   * @brief Destroy the qdc encoder object.
   */
  ~QDC_Encoder();

  /**
   * @brief Set the QDC peripheral configuration.
   * 
   * @param config The configuration as a QDC_config_t pointer
   */
  void setConfig(QDC_config_t* config);

  /**
   * @brief Enable all encoder interrupts.
   */
  void enableInterrupts();

  /**
   * @brief Disable an encoder interrupt.
   * 
   * @param flag Flag for the ISR to disable
   */
  void disableInterrupts(uint8_t flag);

  /**
   * @brief Clears interrupt flags. Call at the end of a QDC_ISR.
   *
   * 
   * @param flag Flag of ISR to clear
   */
  void clearInterruptFlags(uint8_t flag);

  /**
   * @brief Initializes the Encoder.
   * 
   */
  void init();

  /**
   * @brief Set the Initial Count object.
   * 
   * @param initial_pos The initial count
   */
  void setInitialCount(uint32_t initial_pos);

  /**
   * @brief Get Encoder position.
   * 
   * @return Encoder position as uint16_t
   */
  uint16_t getPosition();

  /**
   * @brief Get Encoder position hold (what is this?).
   * 
   * @return Encoder position hold as uint16_t
   */
  uint16_t getPositionHold();

  /**
   * @brief Get position difference from last Encoder position read.
   * 
   * @return Encoder position difference as uint16_t
   */
  uint16_t getPositionDifference();

  /**
   * @brief Get position hold difference from last Encoder position hold read.
   * 
   * @return Encoder position hold difference as uint16_t
   */
  uint16_t getPositionDifferenceHold();

  /**
   * @brief Get the number of revolutions of the Encoder.
   * 
   * @return Number of encoder revolutions as uint16_t
   */
  uint16_t getRevolutions();

  /**
   * @brief Get the number of hold revolutions of the Encoder.
   * 
   * @return Number of encoder hold revolutions as uint16_t
   */
  uint16_t getRevolutionsHold();

  /**
   * @brief Calculates the encoder rotational speed
   * 
   * @return Encoder rotational speed as uint16_t
   */
  uint16_t getSpeed();

  bool self_test();


  /**
   * @brief ISR for QDC channel 1
   */
  static void isrEnc1();

  /**
   * @brief ISR for QDC channel 1
   */
	static void isrEnc2();

  /**
   * @brief ISR for QDC channel 1
   */
	static void isrEnc3();

  /**
   * @brief ISR for QDC channel 1
   */
	static void isrEnc4();
  
private:
  
  /**
   * @brief Array holding instances of this class.
   * 
   * This array is automatically updated as instances of this class are created and destroyed. The 0th element is not used.
   */
  static QDC_Encoder *instances[5];

  /**
   * @brief Array holding ISRs for each encoder.
   */
  static QDC_isr isrs[];

  /**
   * @brief The attached QDC peripheral as QDC_t.
   */
  QDC_t qdc;

  /**
   * @brief Counter variable to store number of times index position is reached.
   * 
   */
  uint16_t indexCounter;

  /**
   * @brief Counter variable to store number of times home position is reached.
   */
  uint16_t homeCounter;

  /**
   * @brief What is this???
   */
  uint16_t compareValueFlag;

  /**
   * @brief ISR function to run every time an ISR is triggered.
   * 
   */
  void isr();
};

#endif // !QDC_ENCODER_H
