// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
custom adaption of keymap_german.h
*******************************************************************************/

#pragma once
#include "keycodes.h"
// clang-format off

// Aliases
#define PC_DE_CIRC KC_GRV  // ^ (dead)
#define PC_DE_1    KC_1    // 1
#define PC_DE_2    KC_2    // 2
#define PC_DE_3    KC_3    // 3
#define PC_DE_4    KC_4    // 4
#define PC_DE_5    KC_5    // 5
#define PC_DE_6    KC_6    // 6
#define PC_DE_7    KC_7    // 7
#define PC_DE_8    KC_8    // 8
#define PC_DE_9    KC_9    // 9
#define PC_DE_0    KC_0    // 0
#define PC_DE_SS   KC_MINS // ß
#define PC_DE_ACUT KC_EQL  // ´ (dead)
#define PC_DE_Q    KC_Q    // Q
#define PC_DE_W    KC_W    // W
#define PC_DE_E    KC_E    // E
#define PC_DE_R    KC_R    // R
#define PC_DE_T    KC_T    // T
#define PC_DE_Z    KC_Y    // Z
#define PC_DE_U    KC_U    // U
#define PC_DE_I    KC_I    // I
#define PC_DE_O    KC_O    // O
#define PC_DE_P    KC_P    // P
#define PC_DE_UDIA KC_LBRC // Ü
#define PC_DE_PLUS KC_RBRC // +
#define PC_DE_A    KC_A    // A
#define PC_DE_S    KC_S    // S
#define PC_DE_D    KC_D    // D
#define PC_DE_F    KC_F    // F
#define PC_DE_G    KC_G    // G
#define PC_DE_H    KC_H    // H
#define PC_DE_J    KC_J    // J
#define PC_DE_K    KC_K    // K
#define PC_DE_L    KC_L    // L
#define PC_DE_ODIA KC_SCLN // Ö
#define PC_DE_ADIA KC_QUOT // Ä
#define PC_DE_HASH KC_NUHS // #
#define PC_DE_LABK KC_NUBS // <
#define PC_DE_Y    KC_Z    // Y
#define PC_DE_X    KC_X    // X
#define PC_DE_C    KC_C    // C
#define PC_DE_V    KC_V    // V
#define PC_DE_B    KC_B    // B
#define PC_DE_N    KC_N    // N
#define PC_DE_M    KC_M    // M
#define PC_DE_COMM KC_COMM // ,
#define PC_DE_DOT  KC_DOT  // .
#define PC_DE_MINS KC_SLSH // -
#define PC_DE_DEG  S(PC_DE_CIRC) // °
#define PC_DE_EXLM S(PC_DE_1)    // !
#define PC_DE_DQUO S(PC_DE_2)    // "
#define PC_DE_SECT S(PC_DE_3)    // §
#define PC_DE_DLR  S(PC_DE_4)    // $
#define PC_DE_PERC S(PC_DE_5)    // %
#define PC_DE_AMPR S(PC_DE_6)    // &
#define PC_DE_SLSH S(PC_DE_7)    // /
#define PC_DE_LPRN S(PC_DE_8)    // (
#define PC_DE_RPRN S(PC_DE_9)    // )
#define PC_DE_EQL  S(PC_DE_0)    // =
#define PC_DE_QUES S(PC_DE_SS)   // ?
#define PC_DE_GRV  S(PC_DE_ACUT) // ` (dead)
#define PC_DE_ASTR S(PC_DE_PLUS) // *
#define PC_DE_QUOT S(PC_DE_HASH) // '
#define PC_DE_RABK S(PC_DE_LABK) // >
#define PC_DE_SCLN S(PC_DE_COMM) // ;
#define PC_DE_COLN S(PC_DE_DOT)  // :
#define PC_DE_UNDS S(PC_DE_MINS) // _
#define PC_DE_SUP2 ALGR(PC_DE_2)    // ²
#define PC_DE_SUP3 ALGR(PC_DE_3)    // ³
#define PC_DE_LCBR ALGR(PC_DE_7)    // {
#define PC_DE_LBRC ALGR(PC_DE_8)    // [
#define PC_DE_RBRC ALGR(PC_DE_9)    // ]
#define PC_DE_RCBR ALGR(PC_DE_0)    // }
#define PC_DE_BSLS ALGR(PC_DE_SS)   // (backslash)
#define PC_DE_AT   ALGR(PC_DE_Q)    // @
#define PC_DE_EURO ALGR(PC_DE_E)    // €
#define PC_DE_TILD ALGR(PC_DE_PLUS) // ~
#define PC_DE_PIPE ALGR(PC_DE_LABK) // |
#define PC_DE_MICR ALGR(PC_DE_M)    // µ

