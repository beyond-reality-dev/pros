/**
 * \file devices/vdml_rotation.cpp
 *
 * Contains functions for interacting with the VEX Rotation sensor.
 *
 * Copyright (c) 2017-2022, Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "pros/rotation.hpp"
#include "vdml/vdml.h"

#include "v5_api.h"

// Here are some important notes about the following macros and precautions if these ever
// need modified in the futre:
//  1) The claim_port_i() creates a local variable called "device". This was an issue in
//     these macros because both push and pop configuration call claim_port_i(). This is
//     why most of the macros' code is surrounded by { }. Since "device" is not needed
//     outside of the macros, putting the macro in a new scope fixes the redefinition
//     errors generated
//  2) The _temp_reverse_flag is defined outside of the scope because it is used in both
//     of the macros. Any variables that need to be shared between macros need to be
//     defined outside of the private scopes
//  3) If the code ever changes such that both macros need to access "device", it is
//     probably best to define another "v5_smart_device_s_t*" outside the scope in
//     push_configuration, set it equal to "device" in the private scope for the push
//     macro, and then reference it in the pop macro. 
#define push_configuration                                                          \
    bool _temp_reverse_flag;                                                        \
	{                                                                               \
    pros::c::mutex_take(_rotation_mutex, TIMEOUT_MAX);                              \
	claim_port_i(_port, pros::c::E_DEVICE_ROTATION);                                \
	_temp_reverse_flag =                                                            \
        vexDeviceMotorReverseFlagGet((V5_DeviceT)(device->device_info));            \
	vexDeviceMotorReverseFlagSet((V5_DeviceT)(device->device_info), _reverse_flag); \
	return_port(_port, 1);                                                          \
    }

#define pop_configuration                                                               \
    {                                                                                   \
	claim_port_i(_port, pros::c::E_DEVICE_ROTATION);                                    \
	vexDeviceMotorReverseFlagSet((V5_DeviceT)(device->device_info), _temp_reverse_flag);\
	return_port(_port, 1);                                                              \
	pros::c::mutex_give(_rotation_mutex);                                               \
    }

namespace pros {
inline namespace v5 {

Rotation::Rotation(const std::uint8_t port, const bool reverse_flag) : _port(port) {
	_reverse_flag = reverse_flag;
	pros::c::rotation_init_reverse(port, reverse_flag);
}

std::int32_t Rotation::reset() {
	push_configuration;
	std::int32_t rtn = pros::c::rotation_reset(_port);
	pop_configuration;
	return rtn;
}

std::int32_t Rotation::set_data_rate(std::uint32_t rate) const {
	push_configuration;
	std::int32_t rtn = pros::c::rotation_set_data_rate(_port, rate);
	pop_configuration;
	return rtn;
}

std::int32_t Rotation::set_position(std::uint32_t position) {
	push_configuration;
	std::int32_t rtn = pros::c::rotation_set_position(_port, position);
	pop_configuration;
	return rtn;
}

std::int32_t Rotation::reset_position(void) {
	push_configuration;
	std::int32_t rtn = pros::c::rotation_reset_position(_port);
	pop_configuration;
	return rtn;
}

std::int32_t Rotation::get_position(void) {
	push_configuration;
	std::int32_t rtn = pros::c::rotation_get_position(_port);
	pop_configuration;
	return rtn;
}

std::int32_t Rotation::get_velocity(void) {
	push_configuration;
	std::int32_t rtn = pros::c::rotation_get_velocity(_port);
	pop_configuration;
	return rtn;
}

std::int32_t Rotation::get_angle(void) {
	push_configuration;
	std::int32_t rtn = pros::c::rotation_get_angle(_port);
	pop_configuration;
	return rtn;
}

std::int32_t Rotation::set_reversed(bool value) {
	_reverse_flag = value;
	push_configuration;
	std::int32_t rtn = pros::c::rotation_set_reversed(_port, value);
	pop_configuration;
	return rtn;
}

std::int32_t Rotation::reverse(void) {
	push_configuration;
	std::int32_t rtn = pros::c::rotation_reverse(_port);
	pop_configuration;
	return rtn;
}

std::int32_t Rotation::get_reversed(void) {
	push_configuration;
	std::int32_t rtn = pros::c::rotation_get_reversed(_port);
	pop_configuration;
	return rtn;
}

}  // namespace v5
}  // namespace pros
