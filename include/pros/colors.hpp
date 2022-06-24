/**
 * \file pros/colors.hpp
 *
 * Contains enum class definitions of colors
 *
 * This file should not be modified by users, since it gets replaced whenever
 * a kernel upgrade occurs.
 *
 * Copyright (c) 2017-2022 Purdue University ACM SIGBots.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License v. 2.0. If a copy of the MPL was not distributed with this
 * file You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#ifndef _PROS_COLORS_HPP_
#define _PROS_COLORS_HPP_
namespace pros{
enum class Color{
  COLOR_ALICE_BLUE = 0x00F0F8FF,
  COLOR_ANTIQUE_WHITE = 0x00FAEBD7,
  COLOR_AQUA = 0x0000FFFF,
  COLOR_AQUAMARINE = 0x007FFFD4,
  COLOR_AZURE = 0x00F0FFFF,
  COLOR_BEIGE = 0x00F5F5DC,
  COLOR_BISQUE = 0x00FFE4C4,
  COLOR_BLACK = 0x00000000,
  COLOR_BLANCHED_ALMOND = 0x00FFEBCD,
  COLOR_BLUE = 0x000000FF,
  COLOR_BLUE_VIOLET = 0x008A2BE2,
  COLOR_BROWN = 0x00A52A2A,
  COLOR_BURLY_WOOD = 0x00DEB887,
  COLOR_CADET_BLUE = 0x005F9EA0,
  COLOR_CHARTREUSE = 0x007FFF00,
  COLOR_CHOCOLATE = 0x00D2691E,
  COLOR_CORAL = 0x00FF7F50,
  COLOR_CORNFLOWER_BLUE = 0x006495ED,
  COLOR_CORNSILK = 0x00FFF8DC,
  COLOR_CRIMSON = 0x00DC143C,
  COLOR_CYAN = 0x0000FFFF,
  COLOR_DARK_BLUE = 0x0000008B,
  COLOR_DARK_CYAN = 0x00008B8B,
  COLOR_DARK_GOLDENROD = 0x00B8860B,
  COLOR_DARK_GRAY = 0x00A9A9A9,
  COLOR_DARK_GREEN = 0x00006400,
  COLOR_DARK_KHAKI = 0x00BDB76B,
  COLOR_DARK_MAGENTA = 0x008B008B,
  COLOR_DARK_OLIVE_GREEN = 0x00556B2F,
  COLOR_DARK_ORANGE = 0x00FF8C00,
  COLOR_DARK_ORCHID = 0x009932CC,
  COLOR_DARK_RED = 0x008B0000,
  COLOR_DARK_SALMON = 0x00E9967A,
  COLOR_DARK_SEA_GREEN = 0x008FBC8F,
  COLOR_DARK_SLATE_GRAY = 0x002F4F4F,
  COLOR_DARK_TURQUOISE = 0x0000CED1,
  COLOR_DARK_VIOLET = 0x009400D3,
  COLOR_DEEP_PINK = 0x00FF1493,
  COLOR_DEEP_SKY_BLUE = 0x0000BFFF,
  COLOR_DIM_GRAY = 0x00696969,
  COLOR_DODGER_BLUE = 0x001E90FF,
  COLOR_FIRE_BRICK = 0x00B22222,
  COLOR_FLORAL_WHITE = 0x00FFFAF0,
  COLOR_FOREST_GREEN = 0x00228B22,
  COLOR_FUCHSIA = 0x00FF00FF,
  COLOR_GAINSBORO = 0x00DCDCDC,
  COLOR_GHOST_WHITE = 0x00F8F8FF,
  COLOR_GOLD = 0x00FFD700,
  COLOR_GOLDENROD = 0x00DAA520,
  COLOR_GRAY = 0x00808080,
  COLOR_GREEN = 0x00008000,
  COLOR_GREEN_YELLOW = 0x00ADFF2F,
  COLOR_HONEYDEW = 0x00F0FFF0,
  COLOR_HOT_PINK = 0x00FF69B4,
  COLOR_INDIAN_RED = 0x00CD5C5C,
  COLOR_INDIGO = 0x004B0082,
  COLOR_IVORY = 0x00FFFFF0,
  COLOR_KHAKI = 0x00F0E68C,
  COLOR_LAVENDER = 0x00E6E6FA,
  COLOR_LAVENDER_BLUSH = 0x00FFF0F5,
  COLOR_LAWN_GREEN = 0x007CFC00,
  COLOR_LEMON_CHIFFON = 0x00FFFACD,
  COLOR_LIGHT_BLUE = 0x00ADD8E6,
  COLOR_LIGHT_CORAL = 0x00F08080,
  COLOR_LIGHT_CYAN = 0x00E0FFFF,
  COLOR_LIGHT_GOLDENROD_YELLOW = 0x00FAFAD2,
  COLOR_LIGHT_GREEN = 0x0090EE90,
  COLOR_LIGHT_GRAY = 0x00D3D3D3,
  COLOR_LIGHT_PINK = 0x00FFB6C1,
  COLOR_LIGHT_SALMON = 0x00FFA07A,
  COLOR_LIGHT_SEA_GREEN = 0x0020B2AA,
  COLOR_LIGHT_SKY_BLUE = 0x0087CEFA,
  COLOR_LIGHT_SLATE_GRAY = 0x00778899,
  COLOR_LIGHT_STEEL_BLUE = 0x00B0C4DE,
  COLOR_LIGHT_YELLOW = 0x00FFFFE0,
  COLOR_LIME = 0x0000FF00,
  COLOR_LIME_GREEN = 0x0032CD32,
  COLOR_LINEN = 0x00FAF0E6,
  COLOR_MAGENTA = 0x00FF00FF,
  COLOR_MAROON = 0x00800000,
  COLOR_MEDIUM_AQUAMARINE = 0x0066CDAA,
  COLOR_MEDIUM_BLUE = 0x000000CD,
  COLOR_MEDIUM_ORCHID = 0x00BA55D3,
  COLOR_MEDIUM_PURPLE = 0x009370DB,
  COLOR_MEDIUM_SEA_GREEN = 0x003CB371,
  COLOR_MEDIUM_SLATE_BLUE = 0x007B68EE,
  COLOR_MEDIUM_SPRING_GREEN = 0x0000FA9A,
  COLOR_MEDIUM_TURQUOISE = 0x0048D1CC,
  COLOR_MEDIUM_VIOLET_RED = 0x00C71585,
  COLOR_MIDNIGHT_BLUE = 0x00191970,
  COLOR_MINT_CREAM = 0x00F5FFFA,
  COLOR_MISTY_ROSE = 0x00FFE4E1,
  COLOR_MOCCASIN = 0x00FFE4B5,
  COLOR_NAVAJO_WHITE = 0x00FFDEAD,
  COLOR_NAVY = 0x00000080,
  COLOR_OLD_LACE = 0x00FDF5E6,
  COLOR_OLIVE = 0x00808000,
  COLOR_OLIVE_DRAB = 0x006B8E23,
  COLOR_ORANGE = 0x00FFA500,
  COLOR_ORANGE_RED = 0x00FF4500,
  COLOR_ORCHID = 0x00DA70D6,
  COLOR_PALE_GOLDENROD = 0x00EEE8AA,
  COLOR_PALE_GREEN = 0x0098FB98,
  COLOR_PALE_TURQUOISE = 0x00AFEEEE,
  COLOR_PALE_VIOLET_RED = 0x00DB7093,
  COLOR_PAPAY_WHIP = 0x00FFEFD5,
  COLOR_PEACH_PUFF = 0x00FFDAB9,
  COLOR_PERU = 0x00CD853F,
  COLOR_PINK = 0x00FFC0CB,
  COLOR_PLUM = 0x00DDA0DD,
  COLOR_POWDER_BLUE = 0x00B0E0E6,
  COLOR_PURPLE = 0x00800080,
  COLOR_RED = 0x00FF0000,
  COLOR_ROSY_BROWN = 0x00BC8F8F,
  COLOR_ROYAL_BLUE = 0x004169E1,
  COLOR_SADDLE_BROWN = 0x008B4513,
  COLOR_SALMON = 0x00FA8072,
  COLOR_SANDY_BROWN = 0x00F4A460,
  COLOR_SEA_GREEN = 0x002E8B57,
  COLOR_SEASHELL = 0x00FFF5EE,
  COLOR_SIENNA = 0x00A0522D,
  COLOR_SILVER = 0x00C0C0C0,
  COLOR_SKY_BLUE = 0x0087CEEB,
  COLOR_SLATE_BLUE = 0x006A5ACD,
  COLOR_SLATE_GRAY = 0x00708090,
  COLOR_SNOW = 0x00FFFAFA,
  COLOR_SPRING_GREEN = 0x0000FF7F,
  COLOR_STEEL_BLUE = 0x004682B4,
  COLOR_TAN = 0x00D2B48C,
  COLOR_TEAL = 0x00008080,
  COLOR_THISTLE = 0x00D8BFD8,
  COLOR_TOMATO = 0x00FF6347,
  COLOR_TURQUOISE = 0x0040E0D0,
  COLOR_VIOLET = 0x00EE82EE,
  COLOR_WHEAT = 0x00F5DEB3,
  COLOR_WHITE = 0x00FFFFFF,
  COLOR_WHITE_SMOKE = 0x00F5F5F5,
  COLOR_YELLOW = 0x00FFFF00,
  COLOR_YELLOW_GREEN = 0x009ACD32,
};
} // namespace pros
#endif //_PROS_COLORS_HPP_
