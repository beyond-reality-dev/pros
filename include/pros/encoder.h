/**
 * \file pros/encoder.h
 * \ingroup c-encoder
 *
 * Contains prototypes for functions related to the VEX encoder Sensor.
 *
 * Visit https://pros.cs.purdue.edu/v5/tutorials/topical/encoder.html to learn
 * more.
 *
 * This file should not be modified by users, since it gets replaced whenever
 * a kernel upgrade occurs.
 *
 * \copyright (c) 2017-2022, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 * 
 * \defgroup c-encoder VEX encoder Sensor C API
 */

#ifndef _PROS_ENCODER_H_
#define _PROS_ENCODER_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
namespace pros {
namespace c {
#endif

/**
 * \ingroup c-encoder
 */

/**
 * \addtogroup c-encoder
 *  @{
 */

#define ENCODER_MINIMUM_DATA_RATE 5

/**
 * Reset encoder Sensor 
 *
 * Reset the current absolute position to be the same as the
 * encoder Sensor angle.
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an encoder Sensor
 *
 * \param port
 *        The V5 encoder Sensor port number from 1-21
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * #define ENCODER_PORT 1
 * 
 * void opcontrol() {
 *   while (true) {
 * 
 *     if(controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_X)){
 *       encoder_reset(ENCODER_PORT);
 *     }
 *     delay(20);
 *   }
 * }
 * \endcode
 */
int32_t encoder_reset(uint8_t port);


/**
 * Set the encoder Sensor position reading to a desired encoder value
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an encoder Sensor
 *
 * \param port
 *		  The V5 encoder Sensor port number from 1-21
 * \param position 
 * 		  The position in terms of ticks
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * #define ENCODER_PORT 1
 * 
 * void opcontrol() {
 *   while (true) {
 * 
 *     if(controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_X)){
 *       encoder_set_position(ENCODER_PORT, 600);
 *     }
 *   delay(20);
 *   }
 * }
 * \endcode
 */
int32_t encoder_set_position(uint8_t port, uint32_t position);

/**
 * Reset the encoder Sensor position to 0
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an encoder Sensor
 *
 * \param port
 *		  The V5 encoder Sensor port number from 1-21

 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * #define ENCODER_PORT 1
 * 
 * void opcontrol() {
 *   while (true) {
 * 
 *     if(controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_X)){
 *       encoder_reset_position(ENCODER_PORT);
 *     }
 *       delay(20);
 *     }
 * }
 * \endcode
 */
int32_t encoder_reset_position(uint8_t port);

/**
 * Get the encoder Sensor's current position in centidegrees
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an encoder Sensor
 *
 * \param  port
 * 				 The V5 encoder Sensor port number from 1-21
 * \return The position value or PROS_ERR_F if the operation failed, setting
 * errno.
 * 
 * \b Example
 * \code
 * #define ENCODER_PORT 1
 * 
 * void opcontrol() {
 *   while (true) {
 *     printf("Position: %d Ticks \n", encoder_get_position(ENCODER_PORT));
 *     delay(20);
 *   }
 * }
 * \endcode
 */
int32_t encoder_get_position(uint8_t port);

/**
 * Get the encoder Sensor's current velocity in centidegrees per second
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an encoder Sensor
 *
 * \param  port
 * 				 The V5 encoder Sensor port number from 1-21
 * \return The velocity value or PROS_ERR_F if the operation failed, setting
 * errno.
 * 
 * \b Example
 * \code
 * #define ENCODER_PORT 1
 * 
 * void opcontrol() {
 *   while (true) {
 *     printf("Velocity: %d Ticks \n", encoder_get_velocity(ENCODER_PORT));
 *     delay(20);
 *   }
 * }
 * \endcode
 */
int32_t encoder_get_velocity(uint8_t port);

/**
 * Set the encoder Sensor's direction reversed flag
 * 
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an encoder Sensor
 *
 * \param  port
 * 				 The V5 encoder Sensor port number from 1-21
 * \param  value
 * 				 Determines if the direction of the encoder Sensor is reversed or not.
 * 
 * \return 1 if operation succeeded or PROS_ERR if the operation failed, setting
 * errno.
 * 
 * \b Example
 * \code
 * #define ENCODER_PORT 1
 * 
 * void opcontrol() {
 *   encoder encoder_sensor(ENCODER_PORT);
 *   while (true) {
 * 
 *     if(controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_X)){
 *       encoder_set_reversed(ENCODER_PORT);
 *     }
 *     delay(20);
 *   }
 * }
 * \endcode
 */
int32_t encoder_set_reversed(uint8_t port, bool value);

/**
 * Reverse the encoder Sensor's direction
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an encoder Sensor
 *
 * \param  port
 * 				 The V5 encoder Sensor port number from 1-21
 *
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * #define ENCODER_PORT 1
 * 
 * void opcontrol() {
 *   encoder encoder_sensor(ENCODER_PORT);
 *   while (true) {
 * 
 *     if(controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_X)){
 *       encoder_reverse(ENCODER_PORT);
 *     }
 *     delay(20);
 *   }
 * }
 * \endcode
 */
int32_t encoder_reverse(uint8_t port);

/**
 * Initialize the encoder Sensor with a reverse flag
 *
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an encoder Sensor
 *
 * \param  port
 * 				 The V5 encoder Sensor port number from 1-21
 * \param  reverse_flag
 * 				 Determines if the encoder Sensor is reversed or not.
 * 
 * \return 1 if the operation was successful or PROS_ERR if the operation
 * failed, setting errno.
 * 
 * \b Example
 * \code
 * 
 * \endcode
 */
int32_t encoder_init_reverse(uint8_t port, bool reverse_flag);

/**
 * Get the encoder Sensor's reversed flag
 * 
 * This function uses the following values of errno when an error state is
 * reached:
 * ENXIO - The given value is not within the range of V5 ports (1-21).
 * ENODEV - The port cannot be configured as an encoder Sensor
 *
 * \param  port
 * 				 The V5 encoder Sensor port number from 1-21
 * 
 * \return Boolean value of if the encoder Sensor's direction is reversed or not
 * or PROS_ERR if the operation failed, setting errno.
 * 
 * \b Example
 * \code
 * #define ENCODER_PORT 1
 * 
 * void opcontrol() {
 *   encoder encoder_sensor(ENCODER_PORT);
 *   while (true) {
 * 
 *     if(controller_get_digital(CONTROLLER_MASTER, E_CONTROLLER_DIGITAL_X)){
 *       encoder_is_reversed(ENCODER_PORT);
 *     }
 *   delay(20);
 *   }
 * }
 * \endcode
 */
int32_t encoder_is_reversed(uint8_t port);

///@}

#ifdef __cplusplus
} //namespace C
} //namespace pros
} //extern "C"
#endif

#endif
