#pragma once

#define RGB_MATRIX_SLEEP // turn off effects when suspended
#undef RGB_MATRIX_DEFAULT_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR

// combo config

#define COMBO_ONLY_FROM_LAYER 0 // make combos work on all layers
//#define COMBO_STRICT_TIMER
#define COMBO_TERM 35       // how quickly all combo keys must be pressed in succession to trigger
#define COMBO_MUST_HOLD_MODS     // if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_HOLD_TERM 200     // how long at least one of the combo keys must be held to trigger


// tap hold config
#define PERMISSIVE_HOLD
#define TAPPING_TERM 180