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
#include "pros/motors.hpp"
#include "vdml/vdml.h"

namespace pros {
inline namespace v5 {
using namespace pros::c;

Motor::Motor(const std::uint8_t port, const motor_gearset_e_t gearset, const bool reverse,
             const motor_encoder_units_e_t encoder_units)
    : _port(port), _gearset(gearset), _reverse(reverse), _encoder_units(encoder_units) {
	set_gearing(gearset);
	set_reversed(reverse);
	set_encoder_units(encoder_units);
}

Motor::Motor(const std::uint8_t port, const motor_gearset_e_t gearset, const bool reverse)
    : _port(port), _gearset(gearset), _reverse(reverse), _encoder_units(E_MOTOR_ENCODER_DEGREES) {
	set_gearing(gearset);
	set_reversed(reverse);
}

Motor::Motor(const std::uint8_t port, const motor_gearset_e_t gearset)
    : _port(port), _gearset(gearset), _reverse(false), _encoder_units(E_MOTOR_ENCODER_DEGREES) {
	set_gearing(gearset);
}

Motor::Motor(const std::uint8_t port, const bool reverse)
    : _port(port), _gearset(E_MOTOR_GEARSET_36), _reverse(reverse), _encoder_units(E_MOTOR_ENCODER_DEGREES) {
	set_reversed(reverse);
}

Motor::Motor(const std::uint8_t port)
    : _port(port), _gearset(E_MOTOR_GEARSET_36), _reverse(false), _encoder_units(E_MOTOR_ENCODER_DEGREES) {}

std::int32_t Motor::operator=(std::int32_t voltage) const {
	push_configuration();
	std::int32_t rtn = motor_move(_port, voltage);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::move(std::int32_t voltage) const {
	push_configuration();
	std::int32_t rtn = motor_move(_port, voltage);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::move_absolute(const double position, const std::int32_t velocity) const {
	push_configuration();
	std::int32_t rtn = motor_move_absolute(_port, position, velocity);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::move_relative(const double position, const std::int32_t velocity) const {
	push_configuration();
	std::int32_t rtn = motor_move_relative(_port, position, velocity);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::move_velocity(const std::int32_t velocity) const {
	push_configuration();
	std::int32_t rtn = motor_move_velocity(_port, velocity);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::move_voltage(const std::int32_t voltage) const {
	push_configuration();
	std::int32_t rtn = motor_move_voltage(_port, voltage);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::brake(void) const {
	push_configuration();
	std::int32_t rtn = motor_brake(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::modify_profiled_velocity(const std::int32_t velocity) const {
	push_configuration();
	std::int32_t rtn = motor_modify_profiled_velocity(_port, velocity);
	pop_configuration();
	return rtn;
}

double Motor::get_actual_velocity(void) const {
	push_configuration();
	std::int32_t rtn = motor_get_actual_velocity(_port);
	pop_configuration();
	return rtn;
}

motor_brake_mode_e_t Motor::get_brake_mode(void) const {
	push_configuration();
	motor_brake_mode_e_t rtn = motor_get_brake_mode(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::get_current_draw(void) const {
	push_configuration();
	std::int32_t rtn = motor_get_current_draw(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::get_current_limit(void) const {
	push_configuration();
	std::int32_t rtn = motor_get_current_limit(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::is_over_current(void) const {
	push_configuration();
	std::int32_t rtn = motor_is_over_current(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::get_direction(void) const {
	push_configuration();
	std::int32_t rtn = motor_get_direction(_port);
	pop_configuration();
	return rtn;
}

double Motor::get_efficiency(void) const {
	push_configuration();
	double rtn = motor_get_efficiency(_port);
	pop_configuration();
	return rtn;
}

motor_encoder_units_e_t Motor::get_encoder_units(void) const {
	return _encoder_units;
}

std::uint32_t Motor::get_faults(void) const {
	push_configuration();
	std::uint32_t rtn = motor_get_faults(_port);
	pop_configuration();
	return rtn;
}

std::uint32_t Motor::get_flags(void) const {
	push_configuration();
	std::uint32_t rtn = motor_get_flags(_port);
	pop_configuration();
	return rtn;
}

motor_gearset_e_t Motor::get_gearing(void) const {
	return _gearset;
}

motor_pid_full_s_t Motor::get_pos_pid(void) const {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	// claim_port(_port, E_DEVICE_MOTOR, NULL);
	//  push_configuration;
	motor_pid_full_s_t rtn = motor_get_pos_pid(_port);
	pop_configuration();
	// return_port(_port, NULL);
	return rtn;
#pragma GCC diagnostic pop
}

motor_pid_full_s_t Motor::get_vel_pid(void) const {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	// claim_port(_port, E_DEVICE_MOTOR, NULL);
	//  push_configuration;
	motor_pid_full_s_t rtn = motor_get_vel_pid(_port);
	pop_configuration();
	// return_port(_port, NULL);
	return rtn;
#pragma GCC diagnostic pop
}

std::int32_t Motor::get_raw_position(std::uint32_t* const timestamp) const {
	push_configuration();
	std::int32_t rtn = motor_get_raw_position(_port, timestamp);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::is_over_temp(void) const {
	push_configuration();
	std::int32_t rtn = motor_is_over_temp(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::is_stopped(void) const {
	push_configuration();
	std::int32_t rtn = motor_is_stopped(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::get_zero_position_flag(void) const {
	push_configuration();
	std::int32_t rtn = motor_get_zero_position_flag(_port);
	pop_configuration();
	return rtn;
}

double Motor::get_position(void) const {
	push_configuration();
	double rtn = motor_get_position(_port);
	pop_configuration();
	return rtn;
}

double Motor::get_power(void) const {
	push_configuration();
	double rtn = motor_get_power(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::is_reversed(void) const {
	return _reverse;
}

double Motor::get_temperature(void) const {
	push_configuration();
	double rtn = motor_get_temperature(_port);
	pop_configuration();
	return rtn;
}

double Motor::get_target_position(void) const {
	push_configuration();
	double rtn = motor_get_target_position(_port);
	pop_configuration();
	return rtn;
}

double Motor::get_torque(void) const {
	push_configuration();
	double rtn = motor_get_torque(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::get_target_velocity(void) const {
	push_configuration();
	std::int32_t rtn = motor_get_target_velocity(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::get_voltage(void) const {
	push_configuration();
	std::int32_t rtn = motor_get_voltage(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::get_voltage_limit(void) const {
	push_configuration();
	std::int32_t rtn = motor_get_voltage_limit(_port);
	pop_configuration();
	return rtn;
}

std::uint8_t Motor::get_port(void) const {
	return _port;
}

std::int32_t Motor::tare_position(void) const {
	push_configuration();
	std::int32_t rtn = motor_tare_position(_port);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::set_brake_mode(const motor_brake_mode_e_t mode) const {
	push_configuration();
	std::int32_t rtn = motor_set_brake_mode(_port, mode);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::set_current_limit(const std::int32_t limit) const {
	push_configuration();
	std::int32_t rtn = motor_set_current_limit(_port, limit);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::set_encoder_units(const motor_encoder_units_e_t units) const {
	_encoder_units = units;
	return motor_set_encoder_units(_port, _encoder_units);
}

std::int32_t Motor::set_gearing(const motor_gearset_e_t gearset) const {
	_gearset = gearset;
	return motor_set_gearing(_port, _gearset);
}

motor_pid_s_t Motor::convert_pid(double kf, double kp, double ki, double kd) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    // push_configuration();
	motor_pid_s_t rtn = motor_convert_pid(kf, kp, ki, kd);
	// pop_configuration();
	return rtn;
#pragma GCC diagnostic pop
}

motor_pid_full_s_t Motor::convert_pid_full(double kf, double kp, double ki, double kd, double filter, double limit,
                                           double threshold, double loopspeed) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	motor_pid_full_s_t rtn = motor_convert_pid_full(kf, kp, ki, kd, filter, limit, threshold, loopspeed);
	return rtn;
#pragma GCC diagnostic pop
}

std::int32_t Motor::set_pos_pid(const motor_pid_s_t pid) const {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	push_configuration();
	std::int32_t rtn = motor_set_pos_pid(_port, pid);
	pop_configuration();
	return rtn;
#pragma GCC diagnostic pop
}

std::int32_t Motor::set_pos_pid_full(const motor_pid_full_s_t pid) const {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	push_configuration();
	std::int32_t rtn = motor_set_pos_pid_full(_port, pid);
	pop_configuration();
	return rtn;
#pragma GCC diagnostic pop
}

std::int32_t Motor::set_vel_pid(const motor_pid_s_t pid) const {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	push_configuration();
	std::int32_t rtn = motor_set_vel_pid(_port, pid);
	pop_configuration();
	return rtn;
#pragma GCC diagnostic pop
}

std::int32_t Motor::set_vel_pid_full(const motor_pid_full_s_t pid) const {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	push_configuration();
	std::int32_t rtn = motor_set_vel_pid_full(_port, pid);
	pop_configuration();
	return rtn;
#pragma GCC diagnostic pop
}

std::int32_t Motor::set_zero_position(const double position) const {
	push_configuration();
	std::int32_t rtn = motor_set_zero_position(_port, position);
	pop_configuration();
	return rtn;
}

std::int32_t Motor::set_reversed(const bool reverse) const {
	_reverse = reverse;
	return motor_set_reversed(_port, _reverse);
}

std::int32_t Motor::set_voltage_limit(const std::int32_t limit) const {
	push_configuration();
	std::int32_t rtn = motor_set_voltage_limit(_port, limit);
	pop_configuration();
	return rtn;
}


int Motor::push_configuration() const {
    claim_port_i(_port, pros::c::E_DEVICE_MOTOR);
	_temp_motor_values.gearset = (motor_gearset_e_t)vexDeviceMotorGearingGet((V5_DeviceT)(device->device_info));
	_temp_motor_values.reverse = vexDeviceMotorReverseFlagGet((V5_DeviceT)(device->device_info));
	_temp_motor_values.encoder_units =
	    (motor_encoder_units_e_t)vexDeviceMotorEncoderUnitsGet((V5_DeviceT)(device->device_info));
	vexDeviceMotorGearingSet((V5_DeviceT)(device->device_info), (V5MotorGearset)_gearset);
	vexDeviceMotorReverseFlagSet((V5_DeviceT)(device->device_info), _reverse);
	vexDeviceMotorEncoderUnitsSet((V5_DeviceT)(device->device_info), (V5MotorEncoderUnits)_encoder_units);
	return_port(_port, 1);
}

int Motor::pop_configuration() const {
	claim_port_i(_port, pros::c::E_DEVICE_MOTOR);
	vexDeviceMotorGearingSet((V5_DeviceT)(device->device_info), (V5MotorGearset)_temp_motor_values.gearset);
	vexDeviceMotorReverseFlagSet((V5_DeviceT)(device->device_info), _temp_motor_values.reverse);
	vexDeviceMotorEncoderUnitsSet((V5_DeviceT)(device->device_info), (V5MotorEncoderUnits)_temp_motor_values.encoder_units);
	return_port(_port, 1);
	pros::c::mutex_give(_motor_mutex);
}

namespace literals {
const pros::Motor operator"" _mtr(const unsigned long long int m) {
	return pros::Motor(m, false);
}
const pros::Motor operator"" _rmtr(const unsigned long long int m) {
	return pros::Motor(m, true);
}

}  // namespace literals
}  // namespace v5
}  // namespace pros
