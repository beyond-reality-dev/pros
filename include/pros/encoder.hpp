/**
 * \file pros/rotation.hpp
 * \ingroup cpp-rotation
 *
 * Contains prototypes for functions related to the VEX Rotation Sensor.
 *
 * Visit https://pros.cs.purdue.edu/v5/tutorials/topical/rotation.html to learn
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
 * \defgroup cpp-rotation VEX Rotation Sensor C++ API
 */
#ifndef _PROS_ENCODER_HPP_
#define _PROS_ENCODER_HPP_

#include <cstdint>
#include <iostream>

namespace pros {
inline namespace v5 {
/**
 * \addtogroup cpp-encoder
 */
class Encoder {

	public:
	Encoder();

	virtual std::int32_t reset();

	virtual std::int32_t set_position(std::uint32_t position) const;

	virtual std::int32_t reset_position(void) const;

	virtual std::int32_t get_position() const;

	virtual std::int32_t get_velocity() const;

	virtual std::int32_t set_reversed(bool value) const;

	virtual std::int32_t reverse() const;

	virtual std::int32_t is_reversed() const;
	///@}


};
}
}  // namespace pros

#endif
