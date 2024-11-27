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

#define OS_MAC false
#define OS_PC true

enum custom_keycodes {
    SWITCH_OS = SAFE_RANGE,
    MA_WRDR,
    MA_WRDL,
    MA_WRD_DEL,
    MA_WRD_BSPC,
    MA_COPY,
    MA_CUT,
    MA_PASTE,
    MA_UNDO,
};

bool os_mode = OS_PC;

enum layers
{
    _ALPHA_COLEMAK  = 0,
    _ALPHA_QWERTY,
    _SYM,
    _NAV,
    _NUM,
    _FUN,
    _UML
};
// LED Nummerierung: Links oben = 0, dann schlangenlinien nach rechts und hinunter, wechsel auf andere Hälfte im Thumb cluster
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    
    [_ALPHA_COLEMAK] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                       KC_J, KC_L,         KC_U,         KC_Y,         KC_QUOT,
        LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_G,                       KC_M, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O),
        KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,                       KC_K, KC_H,         KC_COMM,      KC_DOT,       KC_SCLN,
                        KC_BSPC, LT(_NAV,KC_ENT), LT(_NUM, KC_TAB),          LT(_FUN, KC_ESC), LT(_SYM, KC_SPC), LT(_UML, KC_DEL)         
    ),

    [_ALPHA_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                           KC_Y, KC_U,         KC_I,         KC_O,         KC_P,  
        LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G,                                           KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN),
        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                                           KC_N, KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,
                                                KC_BSPC, LT(_NAV,KC_ENT), LT(_NUM, KC_TAB),          LT(_FUN, KC_ESC), LT(_SYM, KC_SPC), LT(_UML, KC_DEL)         
    ),
    
    [_SYM] = LAYOUT_split_3x5_3(
        DE_GRV  , DE_UNDS , DE_LBRC , DE_RBRC , DE_PIPE ,                                DE_QUOT , DE_HASH , DE_TILD , DE_QUES , DE_RABK ,
        DE_PLUS , DE_MINS , DE_LPRN , DE_RPRN , DE_SLSH ,                                DE_DQUO , DE_AT   , DE_PERC , DE_EXLM , DE_LABK , 
        DE_ASTR , DE_EQL  , DE_LCBR , DE_RCBR , DE_BSLS ,                                DE_CIRC , DE_DEG  ,  DE_DLR , DE_AMPR , DE_ACUT ,
                                        _______, _______, _______,     _______, _______, _______         
    ),
    [_NAV] = LAYOUT_split_3x5_3(
        KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             KC_PGUP,     MA_WRDL, KC_UP  , MA_WRDR,  KC_PGDN,
        LCTL_T(XXXXXXX), LALT_T(XXXXXXX), LGUI_T(XXXXXXX), LSFT_T(XXXXXXX), XXXXXXX,            KC_HOME,     KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,
        MA_UNDO, MA_CUT, MA_COPY, MA_PASTE, KC_PSCR,                                            MA_WRD_BSPC, KC_BSPC, XXXXXXX, KC_DEL,   MA_WRD_DEL,
                                        _______, _______, _______,     _______, _______, _______         
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      DE_PLUS, DE_7   , DE_8   , DE_9   , DE_SLSH ,
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,                                    DE_0,    DE_4   , DE_5   , DE_6   , DE_DOT  , 
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,                                    DE_MINS, DE_1   , DE_2   , DE_3   , DE_ASTR ,
                                        _______, _______, _______,     _______, _______, _______
    ),
    [_FUN] = LAYOUT_split_3x5_3(
        XXXXXXX, KC_VOLD,   KC_MUTE,           KC_VOLU,            XXXXXXX,                            XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_MPRV, KC_MPLY,   KC_MSTP,           KC_MNXT,            XXXXXXX,                            XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11,
        XXXXXXX, SWITCH_OS, DF(_ALPHA_QWERTY), DF(_ALPHA_COLEMAK), XXXXXXX,                            XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12,
                                                             _______, _______, _______,     _______, _______, _______
    ),
    [_UML] = LAYOUT_split_3x5_3(
        XXXXXXX,         XXXXXXX,         XXXXXXX,       XXXXXXX,         XXXXXXX,            XXXXXXX, XXXXXXX,         DE_UDIA,         XXXXXXX,         XXXXXXX,
        LCTL_T(DE_ADIA), LALT_T(XXXXXXX), LGUI_T(DE_SS), LSFT_T(XXXXXXX), XXXXXXX,            XXXXXXX, RSFT_T(XXXXXXX), RGUI_T(XXXXXXX), RALT_T(XXXXXXX), RCTL_T(DE_ODIA),
        XXXXXXX,         XXXXXXX,         XXXXXXX,       XXXXXXX,         XXXXXXX,            XXXXXXX, XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,
                                                             _______, _______, _______,     _______, _______, _______
    ),
};



// ######### RGB Stuff ##########
void keyboard_post_init_user(void) {
    rgb_matrix_sethsv_noeeprom(15, 255, 30); //dark orange
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    //uint8_t layer = get_highest_layer(layer_state); 

    if (is_caps_word_on() == true || host_keyboard_led_state().caps_lock) {
        unsigned char value = rgb_matrix_get_val();
        if (value <= 205) value = value + 50;
        else value = 255; 
        RGB rgb = hsv_to_rgb((HSV){0,255,value});
        for(int i = 15; i <= 20; i++) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }

        
    }  
    /*
    if (os_mode == OS_PC) {
        RGB rgb = hsv_to_rgb((HSV){0,0,rgb_matrix_get_val()}); //white
        rgb_matrix_set_color(16, rgb.r, rgb.g, rgb.b);
    }
    if (os_mode == OS_MAC) {
        RGB rgb = hsv_to_rgb((HSV){15, 255, rgb_matrix_get_val()}); // dark orange
        rgb_matrix_set_color(16, rgb.r, rgb.g, rgb.b);
    }
    */
    return false;
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
    switch (keycode) {
    case SWITCH_OS:
        if (record->event.pressed) {
            if (os_mode == OS_PC) {
                os_mode = OS_MAC;
                SEND_STRING("MAC");
            } 
            else {
                os_mode = OS_PC;
                SEND_STRING("PC");
            }
        } 
        return true;

    case MA_WRDR:
        if (record->event.pressed){
            if(os_mode == OS_PC) tap_code16(LCTL(KC_RIGHT));
            else tap_code16(LALT(KC_RIGHT));
        }
        return true;

    case MA_WRDL:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(LCTL(KC_LEFT));
            else tap_code16(LALT(KC_LEFT));
        }
        return true;

    case MA_WRD_DEL:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(LCTL(KC_DEL));
            else tap_code16(LALT(KC_DEL));
        }
        return true;

    case MA_WRD_BSPC:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(LCTL(KC_BSPC));
            else tap_code16(LALT(KC_BSPC));
        }
        return true; 

    case MA_COPY:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(LCTL(DE_C));
            else tap_code16(LGUI(DE_C));
        }
        return true; 
    
    case MA_CUT:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(LCTL(DE_X));
            else tap_code16(LGUI(DE_X));
        }
        return true; 

    case MA_PASTE:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(LCTL(DE_V));
            else tap_code16(LGUI(DE_V));
        }
        return true; 

    case MA_UNDO:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(LCTL(DE_Z));
            else tap_code16(LGUI(DE_Z));
        }
        return true; 

    }

    // ##### map german MAC keycodes to german PC ############
    if (record->event.pressed && os_mode == OS_PC) {
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
    return true;
};


