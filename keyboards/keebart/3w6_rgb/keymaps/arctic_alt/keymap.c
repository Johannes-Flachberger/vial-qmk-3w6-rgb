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


enum os_modes {
    OS_MAC = 0,
    OS_PC
};

enum os_modes os_mode = OS_PC;

// Super alt tab and super alt ctl
bool is_alt_tab_active = false;
bool is_ctl_tab_active = false;


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
    MA_LOCK
};

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
        DE_Q, DE_W, DE_F,  DE_P,         DE_B,                        DE_J, DE_L,         DE_U,    DE_Y,   DE_PLUS,
        DE_A, DE_R, DE_S,  LSFT_T(DE_T), DE_G,                        DE_M, RSFT_T(DE_N), DE_E,    DE_I,   DE_O,
        DE_Z, DE_X, DE_C,  DE_D,         DE_V,                        DE_K, DE_H,         DE_COMM, DE_DOT, DE_MINS,
        LGUI_T(KC_BSPC) , LT(_NAV,KC_ENT), LCTL_T(KC_TAB),          LT(_NUM, KC_BSPC), LT(_SYM, KC_SPC), LALT_T(KC_DEL)                
    ),

    [_ALPHA_QWERTY] = LAYOUT_split_3x5_3(
        DE_Q, DE_W, DE_E, DE_R,         DE_T,                                    DE_Y, DE_U,         DE_I,    DE_O,   DE_P,  
        DE_A, DE_S, DE_D, LSFT_T(DE_F), DE_G,                                    DE_H, RSFT_T(DE_J), DE_K,    DE_L,   DE_SCLN,
        DE_Z, DE_X, DE_C, DE_V,         DE_B,                                    DE_N, DE_M,         DE_COMM, DE_DOT, DE_SLSH,
            LCTL_T(KC_BSPC) , LT(_NAV,KC_ENT), LGUI_T(KC_TAB),          LT(_NUM, KC_BSPC), LT(_SYM, KC_SPC), LALT_T(KC_DEL)         
    ),
    
    [_SYM] = LAYOUT_split_3x5_3(
        RALT(DE_E), DE_PIPE , DE_EQL ,  DE_LBRC , DE_RBRC ,                 DE_TILD,DE_QUES, DE_UDIA , DE_PERC  , DE_ACUT ,
        DE_ADIA ,   DE_SLSH , DE_SS ,   DE_LPRN , DE_RPRN ,                 DE_AT , DE_EXLM, DE_DQUO , DE_QUOT  , DE_ODIA , 
        DE_DLR ,    DE_BSLS , DE_HASH , DE_LCBR , DE_RCBR ,                 DE_DEG, DE_AMPR, DE_LABK , DE_RABK  , DE_CIRC ,
                                      _______, KC_LSFT, _______,     _______, _______, _______     
    ),   

    [_NAV] = LAYOUT_split_3x5_3(
        MA_LOCK, CTL_TAB, MA_QUIT,     KC_PSCR,         XXXXXXX,                KC_PGUP, MA_WRD_BSPC, MA_WRDL,   MA_WRDR,  MA_WRD_DEL,
        KC_ESC,  ALT_TAB,  MA_OS_SEARCH, LSFT_T(XXXXXXX), XXXXXXX,                KC_PGDN, KC_LEFT,     KC_DOWN,   KC_UP,   KC_RGHT,
        MA_UNDO, MA_CUT,   MA_COPY,     MA_FIND,         MA_PASTE  ,             XXXXXXX, MA_LINE_BSPC, KC_HOME,   KC_END, MA_LINE_DEL,
                                          _______, _______, _______,        LGUI_T(KC_BSPC), _______, OSM(KC_RALT)    
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        XXXXXXX, KC_VOLD, KC_MUTE,  KC_VOLU ,  XXXXXXX,                                    DE_PLUS, DE_7   , DE_8   , DE_9   , DE_SLSH ,
        MO(_FUN), KC_MPRV, KC_MPLY,  KC_MNXT,  XXXXXXX,                                    DE_0,    DE_4   , DE_5   , DE_6   , DE_DOT  , 
        XXXXXXX, RM_VALD, XXXXXXX,  RM_VALU,   XXXXXXX,                                    DE_MINS, DE_1   , DE_2   , DE_3   , DE_ASTR ,
                                        _______, _______, _______,     _______, _______, _______
    ),
    [_FUN] = LAYOUT_split_3x5_3(
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                         DF(_ALPHA_QWERTY) , KC_F7, KC_F8, KC_F9, KC_F10,
        _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                         DF(_ALPHA_COLEMAK), KC_F4, KC_F5, KC_F6, KC_F11,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          SWITCH_OS, KC_F1, KC_F2, KC_F3, KC_F12,
                                     _______, _______, _______,     _______, _______, _______
    )
};


// ######### RGB Stuff ##########
void keyboard_post_init_user(void) {
    rgb_matrix_sethsv_noeeprom(15, 255, 60); //dark orange
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    //uint8_t layer = get_highest_layer(layer_state); 

    if (is_caps_word_on() == true || host_keyboard_led_state().caps_lock) {
        unsigned char value = rgb_matrix_get_val();
        if (value <= 155) value = value + 100;
        else value = 255; 
        RGB rgb = hsv_to_rgb((HSV){0,0,value});
        for(int i = 15; i <= 20; i++) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }  
    }
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

    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        tap_code(KC_TAB);
      }
      break;

    case CTL_TAB:
      if (record->event.pressed) {
        if (!is_ctl_tab_active) {
          is_ctl_tab_active = true;
          register_code(KC_LCTL);
        }
        tap_code(KC_TAB);
      }
      break;

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

    case MA_LINE_DEL:
        if (record->event.pressed) {
                tap_code16(LSFT(KC_END));
                tap_code(KC_BSPC);
        }
        return true;

    case MA_LINE_BSPC:
        if (record->event.pressed) {
            tap_code16(LSFT(KC_HOME));
            tap_code(KC_DEL);
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
    
    case MA_QUIT:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(LALT(KC_F4));
            else if (is_alt_tab_active == true) tap_code(DE_Q);
            else tap_code16(LGUI(DE_Q));
        }
        return true; 

    case MA_FIND:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(LCTL(DE_F));
            else tap_code16(LGUI(DE_F));
        }
        return true;
    
    case MA_OS_SEARCH:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(KC_LGUI);
            else tap_code16(LGUI(KC_SPC));
        }
        return true;
    
    case MA_LOCK:
        if (record->event.pressed) {
            if(os_mode == OS_PC) tap_code16(LGUI(DE_L));
            else tap_code16(LGUI(KC_ESC));
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

// Super alt tab

layer_state_t layer_state_set_user(layer_state_t state) {
    if ((get_highest_layer(state) == _ALPHA_COLEMAK) || (get_highest_layer(state) == _ALPHA_QWERTY)) {
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


