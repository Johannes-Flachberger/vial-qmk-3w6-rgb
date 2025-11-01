// Copyright 2025 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
custom adaptation of keymap_german_mac_iso.h
*******************************************************************************/

#pragma once
#include "keycodes.h"
// clang-format off

// Aliases
#define DE_CIRC KC_GRV  // ^ (dead)
#define DE_1    KC_1    // 1
#define DE_2    KC_2    // 2
#define DE_3    KC_3    // 3
#define DE_4    KC_4    // 4
#define DE_5    KC_5    // 5
#define DE_6    KC_6    // 6
#define DE_7    KC_7    // 7
#define DE_8    KC_8    // 8
#define DE_9    KC_9    // 9
#define DE_0    KC_0    // 0
#define DE_SS   KC_MINS // ß
#define DE_ACUT KC_EQL  // ´ (dead)
#define DE_Q    KC_Q    // Q
#define DE_W    KC_W    // W
#define DE_E    KC_E    // E
#define DE_R    KC_R    // R
#define DE_T    KC_T    // T
#define DE_Z    KC_Y    // Z
#define DE_U    KC_U    // U
#define DE_I    KC_I    // I
#define DE_O    KC_O    // O
#define DE_P    KC_P    // P
#define DE_UDIA KC_LBRC // Ü
#define DE_PLUS KC_RBRC // +
#define DE_A    KC_A    // A
#define DE_S    KC_S    // S
#define DE_D    KC_D    // D
#define DE_F    KC_F    // F
#define DE_G    KC_G    // G
#define DE_H    KC_H    // H
#define DE_J    KC_J    // J
#define DE_K    KC_K    // K
#define DE_L    KC_L    // L
#define DE_ODIA KC_SCLN // Ö
#define DE_ADIA KC_QUOT // Ä
#define DE_HASH KC_NUHS // #
#define DE_LABK KC_NUBS // <
#define DE_Y    KC_Z    // Y
#define DE_X    KC_X    // X
#define DE_C    KC_C    // C
#define DE_V    KC_V    // V
#define DE_B    KC_B    // B
#define DE_N    KC_N    // N
#define DE_M    KC_M    // M
#define DE_COMM KC_COMM // ,
#define DE_DOT  KC_DOT  // .
#define DE_MINS KC_SLSH // -
#define DE_DEG  S(DE_CIRC) // °
#define DE_EXLM S(DE_1)    // !
#define DE_DQUO S(DE_2)    // "
#define DE_SECT S(DE_3)    // §
#define DE_DLR  S(DE_4)    // $
#define DE_PERC S(DE_5)    // %
#define DE_AMPR S(DE_6)    // &
#define DE_SLSH S(DE_7)    // /
#define DE_LPRN S(DE_8)    // (
#define DE_RPRN S(DE_9)    // )
#define DE_EQL  S(DE_0)    // =
#define DE_QUES S(DE_SS)   // ?
#define DE_GRV  S(DE_ACUT) // ` (dead)
#define DE_ASTR S(DE_PLUS) // *
#define DE_QUOT S(DE_HASH) // '
#define DE_RABK S(DE_LABK) // >
#define DE_SCLN S(DE_COMM) // ;
#define DE_COLN S(DE_DOT)  // :
#define DE_UNDS S(DE_MINS) // _
#define DE_DLQU RALT(DE_CIRC) // „
#define DE_IEXL RALT(DE_1)    // ¡
#define DE_LDQU RALT(DE_2)    // “
#define DE_PILC RALT(DE_3)    // ¶
#define DE_CENT RALT(DE_4)    // ¢
#define DE_LBRC RALT(DE_5)    // [
#define DE_RBRC RALT(DE_6)    // ]
#define DE_PIPE RALT(DE_7)    // |
#define DE_LCBR RALT(DE_8)    // {
#define DE_RCBR RALT(DE_9)    // }
#define DE_NEQL RALT(DE_0)    // ≠
#define DE_IQUE RALT(DE_SS)   // ¿
#define DE_LDAQ RALT(DE_Q)    // «
#define DE_NARS RALT(DE_W)    // ∑
#define DE_EURO RALT(DE_E)    // €
#define DE_REGD RALT(DE_R)    // ®
#define DE_DAGG RALT(DE_T)    // †
#define DE_OMEG RALT(DE_Z)    // Ω
#define DE_DIAE RALT(DE_U)    // ¨ (dead)
#define DE_FRSL RALT(DE_I)    // ⁄
#define DE_OSTR RALT(DE_O)    // Ø
#define DE_PI   RALT(DE_P)    // π
#define DE_BULT RALT(DE_UDIA) // •
#define DE_PLMN RALT(DE_PLUS) // ±
#define DE_ARNG RALT(DE_A)    // Å
#define DE_SLQU RALT(DE_S)    // ‚
#define DE_PDIF RALT(DE_D)    // ∂
#define DE_FHK  RALT(DE_F)    // ƒ
#define DE_COPY RALT(DE_G)    // ©
#define DE_FORD RALT(DE_H)    // ª
#define DE_MORD RALT(DE_J)    // º
#define DE_INCR RALT(DE_K)    // ∆
#define DE_AT   RALT(DE_L)    // @
#define DE_OE   RALT(DE_ODIA) // Œ
#define DE_AE   RALT(DE_ADIA) // Æ
#define DE_LSQU RALT(DE_HASH) // ‘
#define DE_LTEQ RALT(DE_LABK) // ≤
#define DE_YEN  RALT(DE_Y)    // ¥
#define DE_AEQL RALT(DE_X)    // ≈
#define DE_CCCE RALT(DE_C)    // Ç
#define DE_SQRT RALT(DE_V)    // √
#define DE_INTG RALT(DE_B)    // ∫
#define DE_TILD RALT(DE_N)    // ~ (dead)
#define DE_MICR RALT(DE_M)    // µ
#define DE_INFN RALT(DE_COMM) // ∞
#define DE_ELLP RALT(DE_DOT)  // …
#define DE_NDSH RALT(DE_MINS) // –
#define DE_NOT  S(RALT(DE_1))    // ¬
#define DE_RDQU S(RALT(DE_2))    // ”
#define DE_PND  S(RALT(DE_4))    // £
#define DE_FI   S(RALT(DE_5))    // ﬁ
#define DE_BSLS S(RALT(DE_7))    // (backslash)
#define DE_STIL S(RALT(DE_8))    // ˜
#define DE_MDDT S(RALT(DE_9))    // ·
#define DE_MACR S(RALT(DE_0))    // ¯
#define DE_DOTA S(RALT(DE_SS))   // ˙
#define DE_RNGA S(RALT(DE_ACUT)) // ˚
#define DE_RDAQ S(RALT(DE_Q))    // »
#define DE_PERM S(RALT(DE_E))    // ‰
#define DE_CEDL S(RALT(DE_R))    // ¸
#define DE_DACU S(RALT(DE_T))    // ˝
#define DE_CARN S(RALT(DE_Z))    // ˇ
#define DE_AACU S(RALT(DE_U))    // Á
#define DE_UCIR S(RALT(DE_I))    // Û
#define DE_NARP S(RALT(DE_P))    // ∏
#define DE_APPL S(RALT(DE_PLUS)) //  (Apple logo)
#define DE_IACU S(RALT(DE_S))    // Í
#define DE_TM   S(RALT(DE_D))    // ™
#define DE_IDIA S(RALT(DE_F))    // Ï
#define DE_IGRV S(RALT(DE_G))    // Ì
#define DE_OACU S(RALT(DE_H))    // Ó
#define DE_DLSI S(RALT(DE_J))    // ı
#define DE_FL   S(RALT(DE_L))    // ﬂ
#define DE_GTEQ S(RALT(DE_LABK)) // ≥
#define DE_DDAG S(RALT(DE_Y))    // ‡
#define DE_UGRV S(RALT(DE_X))    // Ù
#define DE_LOZN S(RALT(DE_V))    // ◊
#define DE_LSAQ S(RALT(DE_B))    // ‹
#define DE_RSAQ S(RALT(DE_N))    // ›
#define DE_BREV S(RALT(DE_M))    // ˘
#define DE_OGON S(RALT(DE_COMM)) // ˛
#define DE_DIV  S(RALT(DE_DOT))  // ÷
#define DE_MDSH S(RALT(DE_MINS)) // —

