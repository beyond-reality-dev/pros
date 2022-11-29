/**
 * \file devices/vdml_motors.cpp
 *
 * Contains functions for interacting with the V5 Motors.
 *
 * Copyright (c) 2017-2022, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "kapi.h"
#include "pros/encoder.hpp"

namespace pros {
inline namespace v5 {
using namespace pros::c;

Encoder::Encoder(const std::uint8_t port, const pros::v5::Motor_Gears gearset, const bool reverse,
                 const pros::v5::Motor_Units encoder_units)
    : _port(port) {
	set_gearing(gearset);
	set_reversed(reverse);
	set_encoder_units(encoder_units);
	if (port < 0) set_reversed(true);
}

std::int32_t Motor::operator=(std::int32_t voltage) const {
	push_motor_configuration();
	return motor_move(_port, voltage);
}

std::int32_t Encoder::reset() {

}

std::int32_t Encoder::set_position(std::uint32_t position) {

}

std::int32_t Encoder::reset_position(void) {

}

std::int32_t Encoder::get_position() {

}

std::int32_t Encoder::get_velocity() {

}

std::int32_t Encoder::set_reversed(bool value) {

}

std::int32_t Encoder::reverse() {

}

std::int32_t Encoder::is_reversed() {
    
}

void Motor::push_motor_configuration() const {
	_motor_mutex.take();
	set_gearing(_gearset);
	set_reversed(_reverse);
	set_encoder_units(_encoder_units);
	_motor_mutex.give();
}
