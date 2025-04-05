#pragma once

#define RGB_MATRIX_SLEEP     // turn off effects when suspended
#undef RGB_MATRIX_DEFAULT_MODE
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR

//combo config

#define COMBO_TERM 50 // how quickly all combo keys must be pressed in succession to trigger
#define COMBO_MUST_HOLD_MOD // if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_HOLD_TERM 100 // how long at least one of the combo keys must be held to trigger
#define COMBO_ONLY_FROM_LAYER 0 // make combos work on all layers

// tap hold config
#define PERMISSIVE_HOLD
#define TAPPING_TERM 150
#define QUICK_TAP_TERM 100