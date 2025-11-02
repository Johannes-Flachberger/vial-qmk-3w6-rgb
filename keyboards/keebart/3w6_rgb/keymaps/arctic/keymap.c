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
#include "custom_keycodes_german_mac_iso.h"
#include "custom_keycodes_german_pc.h"

enum os_modes { OS_MAC = 0, OS_PC };

enum custom_keycodes {
  SWITCH_OS = SAFE_RANGE,
  ALT_TAB,
  CTL_TAB,
  MA_RIGHT,
  MA_LEFT,
  MA_WRDR,
  MA_WRDL,
  MA_LINEL,
  MA_LINER,
  MA_BLOCK_DOWN,
  MA_BLOCK_UP,
  MA_COPY,
  MA_CUT,
  MA_PASTE,
  MA_PASTE_S,
  MA_UNDO,
  MA_QUIT,
  MA_FIND,
  MA_OS_SEARCH,
  MA_LOCK,
  MA_SAVE,
  GUI_TAB
};

enum layers { _ALPHA = 0, _ALPHA_QWERTY, _SYM, _NAV, _NUM, _FUN };

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
  COMBO_RCTL_LALT,
  COMBO_RCTL_RGUI_LALT,
  COMBO_RGUI_LALT
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

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_LCTL] = COMBO(combo_ts, KC_LCTL),
    [COMBO_RCTL] = COMBO(combo_ne, KC_RCTL),
    [COMBO_LGUI] = COMBO(combo_ta, KC_LGUI),
    [COMBO_RGUI] = COMBO(combo_no, KC_RGUI),
    [COMBO_LALT] = COMBO(combo_tr, KC_LALT),
    [COMBO_RALT] = COMBO(combo_ni, KC_LALT),
    [COMBO_LCTL_LGUI] = COMBO(combo_tsa, LCTL(KC_LGUI)),
    [COMBO_LCTL_LGUI_LALT] = COMBO(combo_tsra, LCTL(LGUI(KC_LALT))),
    [COMBO_LGUI_LALT] = COMBO(combo_tra, LGUI(KC_LALT)),
    [COMBO_LCTL_LALT] = COMBO(combo_tsr, LCTL(KC_LALT)),
    [COMBO_RCTL_RGUI] = COMBO(combo_neo, RCTL(KC_RGUI)),
    [COMBO_RCTL_RGUI_LALT] = COMBO(combo_neio, RCTL(RGUI(KC_LALT))),
    [COMBO_RGUI_LALT] = COMBO(combo_nio, RGUI(KC_LALT)),
    [COMBO_RCTL_LALT] = COMBO(combo_nei, RCTL(KC_LALT)),
};

enum os_modes os_mode = OS_PC;

// alt tab, gui tab, ctl tab
bool is_alt_tab_active = false;
bool is_ctl_tab_active = false;
bool is_gui_tab_active = false;
bool is_del_mode_active = false;
// LED Nummerierung: Links oben = 0, dann schlangenlinien nach rechts und
// hinunter, wechsel auf andere Hälfte im Thumb cluster
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    [_ALPHA] = LAYOUT_split_3x5_3(
        DE_Q, DE_W, DE_F,  DE_P, DE_B,                                          DE_J, DE_L, DE_U,    DE_Y,   DE_PLUS,
        DE_A, DE_R, DE_S,  DE_T, DE_G,                                          DE_M, DE_N, DE_E,    DE_I,   DE_O,
        DE_Z, DE_X, DE_C,  DE_D, DE_V,                                          DE_K, DE_H, DE_COMM, DE_DOT, DE_MINS,
        LT(_NUM, KC_ENT) , LSFT_T(KC_BSPC) , LT(_NAV,  KC_SPC),     LT(_NUM, KC_TAB), LT( _SYM, KC_SPC) , LT(_FUN, KC_ENT)
    ),
    
    [_SYM] = LAYOUT_split_3x5_3(
        RALT(DE_E), DE_PIPE , DE_DLR  , DE_LBRC , DE_RBRC ,                 DE_PERC , DE_QUES, DE_UDIA , DE_QUOT , DE_CIRC ,
        DE_ADIA ,   DE_SLSH , DE_SS   , DE_LPRN , DE_RPRN ,                 DE_HASH , DE_EXLM, DE_PLUS , DE_DQUO , DE_ODIA , 
        DE_LABK ,   DE_BSLS , DE_RABK , DE_LCBR , DE_RCBR ,                 DE_AT   , DE_AMPR, DE_ASTR ,  DE_EQL,  DE_TILD,
                                      _______, _______, _______,     _______, _______, _______     
    ),   

    [_NAV] = LAYOUT_split_3x5_3(
        MA_LOCK, MA_QUIT,      MA_FIND , CTL_TAB , KC_PSCR   ,       XXXXXXX , XXXXXXX       , MA_LINEL , MA_LINER , XXXXXXX ,
        KC_ESC , MA_OS_SEARCH, LT(0,MA_SAVE) , ALT_TAB , MA_PASTE_S,       XXXXXXX , MA_LEFT       , LT(0,MA_WRDL)  , MA_WRDR  , MA_RIGHT,
        MA_UNDO, MA_CUT,       MA_COPY , GUI_TAB , MA_PASTE  ,       XXXXXXX , MA_BLOCK_DOWN , KC_DOWN  , KC_UP    , MA_BLOCK_UP,
                                     _______, _______, _______,      LT(0,KC_BSPC) , LSFT_T(KC_SPC), KC_DEL
    ),
  
    [_NUM] = LAYOUT_split_3x5_3(
        DE_MINS , DE_7   , DE_8   , DE_9   , XXXXXXX ,                         XXXXXXX, KC_VOLD, KC_MUTE   ,  KC_VOLU , XXXXXXX,
        DE_0    , DE_4   , DE_5   , DE_6   , DE_SLSH ,                         XXXXXXX, KC_MPRV, KC_MPLY   ,  KC_MNXT , XXXXXXX,
        DE_DOT  , DE_1   , DE_2   , DE_3   , DE_COMM ,                         XXXXXXX, DE_ACUT, S(DE_ACUT),  DE_DEG  , XXXXXXX,
                                   _______, _______, _______,     _______, _______, _______
    ),

    [_FUN] = LAYOUT_split_3x5_3(
        XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10,                         XXXXXXX , XXXXXXX  , XXXXXXX,  XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11,                         XXXXXXX , SWITCH_OS, XXXXXXX,  XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12,                         XXXXXXX , XXXXXXX  , XXXXXXX,  XXXXXXX, XXXXXXX,
                                     _______, _______, _______,     _______, _______, _______
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
  // Intercept hold function
  if (!record->tap.count && (keycode == LT(0, KC_BSPC))) {
    is_del_mode_active = record->event.pressed ? true : false;
    return false;
  }

  if (keycode == LT(0, MA_SAVE)) {
    if (!record->tap.count) { // Intercept hold function to switch os mode
      os_mode = (os_mode == OS_MAC) ? OS_PC : OS_MAC;
    } else if (record->event.pressed) { // MA_SAVE MACRO
      os_mode == OS_PC ? tap_code16(LCTL(DE_S)) : tap_code16(LGUI(DE_S));
    }
    return false;
  }

  if (keycode == LT(0, MA_WRDL)) {
    if (!record->tap.count) { // Intercept hold function to switch os mode
      os_mode = (os_mode == OS_MAC) ? OS_PC : OS_MAC;
    } else if (record->event.pressed) { // MA_SAVE MACRO functionality
      if (os_mode == OS_PC) {
        is_del_mode_active ? tap_code16(C(KC_BSPC)) : tap_code16(C(KC_LEFT));
      } else {
        is_del_mode_active ? tap_code16(A(KC_BSPC)) : tap_code16(A(KC_LEFT));/
      }
    }
    return false;
  }

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

    case GUI_TAB:
      if (!is_gui_tab_active) {
        is_gui_tab_active = true;
        register_code(KC_LGUI);
      }
      tap_code(KC_TAB);
      break;

    case MA_RIGHT:
      is_del_mode_active ? tap_code16(KC_DEL) : tap_code16(KC_RIGHT);
      return true;
    case MA_LEFT:
      is_del_mode_active ? tap_code16(KC_BSPC) : tap_code16(KC_LEFT);
      return true;

    case MA_WRDR:
      if (os_mode == OS_PC) {
        is_del_mode_active ? tap_code16(C(KC_DEL)) : tap_code16(C(KC_RIGHT));
      } else {
        is_del_mode_active ? tap_code16(A(KC_DEL)) : tap_code16(A(KC_RIGHT));
      }
      return true;

    case MA_LINEL:
      if (os_mode == OS_PC) {
        if (is_del_mode_active) {
          tap_code16(S(KC_LEFT)); // moves to previous line if the cursor is at
                                  // the beginning of a line
          tap_code16(S(KC_HOME)); // Windows/Linux: move to start of line
          tap_code(KC_BSPC);
        } else {
          tap_code(KC_LEFT); // moves to previous line if the cursor is at the
                             // beginning of a line
          tap_code(KC_HOME); // Windows/Linux: move to start of line
        }
      } else {
        if (is_del_mode_active) {
          tap_code(KC_BSPC); // moves to previous line if the cursor is at the
                             // beginning of a line
          tap_code16(G(KC_BSPC)); // macOS: Cmd+Left → start of line
        } else {
          tap_code(KC_LEFT); // moves to previous line if the cursor is at the
                             // beginning of a line
          tap_code16(G(KC_LEFT)); // macOS: Cmd+Left → start of line
        }
      }
      return true;

    case MA_LINER:
      if (os_mode == OS_PC) {
        if (is_del_mode_active) {
          tap_code16(S(KC_RIGHT)); // moves to previous line if the cursor is at
                                   // the beginning of a line
          tap_code16(S(KC_END));   // Windows/Linux: move to start of line
          tap_code(KC_BSPC);
        } else {
          tap_code(KC_RIGHT); // moves to previous line if the cursor is at the
                              // beginning of a line
          tap_code(KC_END);   // Windows/Linux: move to start of line
        }
      } else {
        if (is_del_mode_active) {
          tap_code(KC_DEL); // moves to previous line if the cursor is at the
                            // beginning of a line
          tap_code16(G(KC_DEL)); // macOS: Cmd+Left → start of line
        } else {
          tap_code(KC_RIGHT); // moves to previous line if the cursor is at the
                              // beginning of a line
          tap_code16(G(KC_RIGHT)); // macOS: Cmd+Left → start of line
        }
      }
      return true;

    case MA_BLOCK_DOWN:
      for (int i = 0; i < 5; i++) {
        tap_code(KC_DOWN);
      }
      return true;
    case MA_BLOCK_UP:
      for (int i = 0; i < 5; i++) {
        tap_code(KC_UP);
      }
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
    case MA_PASTE_S:
      os_mode == OS_PC ? tap_code16(C(S(DE_V))) : tap_code16(G(S(DE_V)));
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
  if ((get_highest_layer(state) == _ALPHA) ||
      (get_highest_layer(state) == _ALPHA_QWERTY)) {
    if (is_alt_tab_active == true) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
    if (is_ctl_tab_active == true) {
      unregister_code(KC_LCTL);
      is_ctl_tab_active = false;
    }
    if (is_gui_tab_active == true) {
      unregister_code(KC_LGUI);
      is_gui_tab_active = false;
    }
  }
  return state;
}
