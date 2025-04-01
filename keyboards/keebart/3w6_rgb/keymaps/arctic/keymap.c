/* Copyright 2021 weteor
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_german_mac_iso.h"
#include "keycodes_german_pc.h"

// clang-format off
enum os_modes {
    OS_MAC = 0,
    OS_PC
};

enum custom_keycodes {
    SWITCH_OS = SAFE_RANGE,
    ALT_TAB,
    CTL_TAB,
    MA_WRDR,
    MA_WRDL,
    MA_WRD_DEL,
    MA_WRD_BSPC,
    MA_LINE_DEL,
    MA_LINE_BSPC,
    MA_COPY,
    MA_CUT,
    MA_PASTE,
    MA_UNDO,
    MA_QUIT,
    MA_FIND,
    MA_OS_SEARCH,
    MA_LOCK,
    MA_SAVE
};

enum layers
{
    _ALPHA  = 0,
    _SYML,
    _SYMR,
    _NAV,
    _NUM,
    _FUN
};

// define combo names
enum combos {
    COMBO_LCTL,
    COMBO_RCTL,
    COMBO_LGUI,
    COMBO_RGUI,
    COMBO_LALT,
    COMBO_RALT,
    COMBO_LCTL_LGUI,
    COMBO_LCTL_LALT,
    COMBO_LCTL_LGUI_LALT,
    COMBO_LGUI_LALT,
    COMBO_RCTL_RGUI,
    COMBO_RCTL_RALT,
    COMBO_RCTL_RGUI_RALT,
    COMBO_RGUI_RALT,
    COMBO_SFT
};

// define keys that make up combos
const uint16_t PROGMEM combo_ts[] = {DE_T, DE_S, COMBO_END};
const uint16_t PROGMEM combo_tr[] = {DE_T, DE_R, COMBO_END};
const uint16_t PROGMEM combo_ta[] = {DE_T, DE_A, COMBO_END};
const uint16_t PROGMEM combo_ne[] = {DE_N, DE_E, COMBO_END};
const uint16_t PROGMEM combo_ni[] = {DE_N, DE_I, COMBO_END};
const uint16_t PROGMEM combo_no[] = {DE_N, DE_O, COMBO_END};
const uint16_t PROGMEM combo_tsr[] = {DE_T, DE_S, DE_R, COMBO_END};
const uint16_t PROGMEM combo_tsra[] = {DE_T, DE_S, DE_R, DE_A, COMBO_END};
const uint16_t PROGMEM combo_tra[] = {DE_T, DE_R, DE_A, COMBO_END};
const uint16_t PROGMEM combo_tsa[] = {DE_T, DE_S, DE_A, COMBO_END};
const uint16_t PROGMEM combo_nei[] = {DE_N, DE_E, DE_I, COMBO_END};
const uint16_t PROGMEM combo_neio[] = {DE_N, DE_E, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_nio[] = {DE_N, DE_I, DE_O, COMBO_END};
const uint16_t PROGMEM combo_neo[] = {DE_N, DE_E, DE_O, COMBO_END};
const uint16_t PROGMEM combo_sft[] = {LT(_SYML, KC_SPC), LT(_SYMR, KC_ENT), COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_LCTL] = COMBO(combo_ts, KC_LCTL),
    [COMBO_RCTL] = COMBO(combo_ne, KC_RCTL),
    [COMBO_LGUI] = COMBO(combo_tr, KC_LGUI),
    [COMBO_RGUI] = COMBO(combo_ni, KC_RGUI),
    [COMBO_LALT] = COMBO(combo_ta, KC_LALT),
    [COMBO_RALT] = COMBO(combo_no, KC_RALT),
    [COMBO_LCTL_LGUI] = COMBO(combo_tsr, LCTL(KC_LGUI)),
    [COMBO_LCTL_LGUI_LALT] = COMBO(combo_tsra, LCTL(LGUI(KC_LALT))),
    [COMBO_LGUI_LALT] = COMBO(combo_tra, LGUI(KC_LALT)),
    [COMBO_LCTL_LALT] = COMBO(combo_tsa, LCTL(KC_LALT)),
    [COMBO_RCTL_RGUI] = COMBO(combo_nei, RCTL(KC_RGUI)),
    [COMBO_RCTL_RGUI_RALT] = COMBO(combo_neio, RCTL(RGUI(KC_RALT))),
    [COMBO_RGUI_RALT] = COMBO(combo_nio, RGUI(KC_RALT)),
    [COMBO_RCTL_RALT] = COMBO(combo_neo, RCTL(KC_RALT)),
    [COMBO_RCTL_RALT] = COMBO(combo_sft, KC_LSFT),

};

enum os_modes os_mode = OS_PC;

// Super alt tab and super alt ctl
bool is_alt_tab_active = false;
bool is_ctl_tab_active = false;

// LED Nummerierung: Links oben = 0, dann schlangenlinien nach rechts und hinunter, wechsel auf andere Hälfte im Thumb cluster
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_ALPHA] = LAYOUT_split_3x5_3(
        DE_Q, DE_W, DE_F,  DE_P, DE_B,                                    DE_J, DE_L, DE_U,    DE_Y,   DE_PLUS,
        DE_A, DE_R, DE_S,  DE_T, DE_G,                                    DE_M, DE_N, DE_E,    DE_I,   DE_O,
        DE_Z, DE_X, DE_C,  DE_D, DE_V,                                    DE_K, DE_H, DE_COMM, DE_DOT, DE_MINS,
     KC_ENT , LT(_SYML, KC_SPC), LT(_NAV,  KC_BSPC),          LT(_NUM, KC_BSPC), LT(_SYMR, KC_ENT) , LT(_FUN, KC_TAB)
    ),
    
    [_SYML] = LAYOUT_split_3x5_3(
        RALT(DE_E), DE_PIPE , DE_EQL ,  DE_LBRC , DE_RBRC ,                 LSFT(DE_J), LSFT(DE_L) , LSFT(DE_U) , LSFT(DE_Y) , LSFT(DE_PLUS) ,
        DE_ADIA ,   DE_SLSH , DE_SS ,   DE_LPRN , DE_RPRN ,                 LSFT(DE_M), LSFT(DE_N) , LSFT(DE_E) , LSFT(DE_I) , LSFT(DE_O) , 
        DE_DLR ,    DE_BSLS , DE_HASH , DE_LCBR , DE_RCBR ,                 LSFT(DE_K), LSFT(DE_H) , LSFT(DE_COMM) , LSFT(DE_DOT) , LSFT(DE_MINS) ,
                                      _______, _______, _______,     _______, _______, _______     
    ),   

    [_SYMR] = LAYOUT_split_3x5_3(
        LSFT(DE_Q), LSFT(DE_W) , LSFT(DE_F) , LSFT(DE_P) , LSFT(DE_B) ,                 DE_TILD,DE_QUES, DE_UDIA , DE_PERC  , DE_ACUT ,
        LSFT(DE_A), LSFT(DE_R) , LSFT(DE_S) , LSFT(DE_T) , LSFT(DE_G) ,                 DE_AT , DE_EXLM, DE_DQUO , DE_QUOT  , DE_ODIA , 
        LSFT(DE_Z), LSFT(DE_X) , LSFT(DE_C) , LSFT(DE_D) , LSFT(DE_V) ,                 DE_DEG, DE_AMPR, DE_LABK , DE_RABK  , DE_CIRC ,
                                      _______, _______, _______,     _______, _______, _______     
    ),  

    [_NAV] = LAYOUT_split_3x5_3(
        MA_LOCK, CTL_TAB,  MA_FIND, MA_QUIT     , XXXXXXX,                KC_PGUP, MA_WRD_BSPC,  MA_WRDL,   MA_WRDR, MA_WRD_DEL,
        KC_ESC,  ALT_TAB,  MA_SAVE, MA_OS_SEARCH, KC_TAB ,                KC_PGDN, KC_LEFT,      KC_DOWN,   KC_UP,   KC_RGHT,
        MA_UNDO, MA_CUT,   MA_COPY, KC_PSCR     , MA_PASTE,               XXXXXXX, MA_LINE_BSPC, KC_HOME,   KC_END,  MA_LINE_DEL,
                                     _______, KC_LSFT, _______,      _______, KC_LSFT, KC_DEL    
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        XXXXXXX, KC_VOLD, KC_MUTE,  KC_VOLU ,  XXXXXXX,                        DE_PLUS  , DE_7   , DE_8   , DE_9   , DE_ASTR ,
        XXXXXXX, KC_MPRV, KC_MPLY,  KC_MNXT,  XXXXXXX,                         DE_MINS  , DE_4   , DE_5   , DE_6   , DE_SLSH ,
        XXXXXXX, KC_BRID, XXXXXXX,  KC_BRIU,   XXXXXXX,                        DE_COMM  , DE_1   , DE_2   , DE_3   , DE_DOT  ,
                                         _______, KC_LSFT, _______,     _______, KC_LSFT, DE_0
    ),
    [_FUN] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                         XXXXXXX , KC_F7, KC_F8, KC_F9, KC_F10,
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                         XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11,
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                         SWITCH_OS, KC_F1, KC_F2, KC_F3, KC_F12,
                                     _______, KC_LSFT, _______,     _______, KC_LSFT, _______
    )
};

// clang-format on

// ######### RGB Stuff ##########
void keyboard_post_init_user(void) {
    rgb_matrix_sethsv_noeeprom(15, 255, 20); // dark orange
}

// ######### OS Detection ##########

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            os_mode = OS_MAC;
            break;
        case OS_WINDOWS:
        case OS_LINUX:
        case OS_UNSURE:
            os_mode = OS_PC;
            break;
    }

    return true;
}

// ############## MACROS ################

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case SWITCH_OS:
                if (os_mode == OS_PC) {
                    os_mode = OS_MAC;
                    SEND_STRING("MAC");
                } else {
                    os_mode = OS_PC;
                    SEND_STRING("PC");
                }
                return true;

            case ALT_TAB:
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                tap_code(KC_TAB);
                break;

            case CTL_TAB:
                if (!is_ctl_tab_active) {
                    is_ctl_tab_active = true;
                    register_code(KC_LCTL);
                }
                tap_code(KC_TAB);
                break;

            case MA_WRDR:
                os_mode == OS_PC ? tap_code16(LCTL(KC_RIGHT)) : tap_code16(LALT(KC_RIGHT));
                return true;

            case MA_WRDL:
                os_mode == OS_PC ? tap_code16(LCTL(KC_LEFT)) : tap_code16(LALT(KC_LEFT));
                return true;

            case MA_WRD_DEL:
                os_mode == OS_PC ? tap_code16(LCTL(KC_DEL)) : tap_code16(LALT(KC_DEL));
                return true;

            case MA_WRD_BSPC:
                os_mode == OS_PC ? tap_code16(LCTL(KC_BSPC)) : tap_code16(LALT(KC_BSPC));
                return true;

            case MA_LINE_DEL:
                os_mode == OS_PC ? tap_code16(LSFT(KC_END)) : tap_code(KC_BSPC);
                return true;

            case MA_LINE_BSPC:
                os_mode == OS_PC ? tap_code16(LSFT(KC_HOME)) : tap_code(KC_DEL);
                return true;

            case MA_COPY:
                os_mode == OS_PC ? tap_code16(LCTL(DE_C)) : tap_code16(LGUI(DE_C));
                return true;

            case MA_CUT:
                os_mode == OS_PC ? tap_code16(LCTL(DE_X)) : tap_code16(LGUI(DE_X));
                return true;

            case MA_PASTE:
                os_mode == OS_PC ? tap_code16(LCTL(DE_V)) : tap_code16(LGUI(DE_V));
                return true;

            case MA_UNDO:
                os_mode == OS_PC ? tap_code16(LCTL(DE_Z)) : tap_code16(LGUI(DE_Z));
                return true;

            case MA_QUIT:
                if (os_mode == OS_PC)
                    tap_code16(LALT(KC_F4));
                else if (is_alt_tab_active == true)
                    tap_code(DE_Q);
                else
                    tap_code16(LGUI(DE_Q));

                return true;

            case MA_FIND:
                os_mode == OS_PC ? tap_code16(LCTL(DE_F)) : tap_code16(LGUI(DE_F));
                return true;

            case MA_OS_SEARCH:
                os_mode == OS_PC ? tap_code16(KC_LGUI) : tap_code16(LGUI(KC_SPC));
                return true;

            case MA_LOCK:
                os_mode == OS_PC ? tap_code16(LGUI(DE_L)) : tap_code16(LGUI(KC_ESC));
                return true;
            case MA_SAVE:
                os_mode == OS_PC ? tap_code16(LCTL(DE_S)) : tap_code16(LGUI(DE_S));
                return true;
        }

        // ##### map german MAC keycodes to german PC ############
        if (os_mode == OS_PC) {
            switch (keycode) {
                case DE_LCBR:
                    tap_code16(PC_DE_LCBR);
                    return false;
                case DE_LBRC:
                    tap_code16(PC_DE_LBRC);
                    return false;
                case DE_RBRC:
                    tap_code16(PC_DE_RBRC);
                    return false;
                case DE_RCBR:
                    tap_code16(PC_DE_RCBR);
                    return false;
                case DE_BSLS:
                    tap_code16(PC_DE_BSLS);
                    return false;
                case DE_AT:
                    tap_code16(PC_DE_AT);
                    return false;
                case DE_EURO:
                    tap_code16(PC_DE_EURO);
                    return false;
                case DE_TILD:
                    tap_code16(PC_DE_TILD);
                    return false;
                case DE_PIPE:
                    tap_code16(PC_DE_PIPE);
                    return false;
                case DE_MICR:
                    tap_code16(PC_DE_MICR);
                    return false;
            }
        }
    }
    return true;
};

// Super alt tab

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == _ALPHA) {
        if (is_alt_tab_active == true) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
        if (is_ctl_tab_active == true) {
            unregister_code(KC_LCTL);
            is_ctl_tab_active = false;
        }
    }
    return state;
}
