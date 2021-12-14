/* Copyright 2021 Cássio Ávila
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOuT ANY WARRANTY; without even the implied warranty of
 * MERCHANTAbILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "sendstring_br_abnt2.h"

#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))

bool process_caps_word(uint16_t keycode, keyrecord_t* record);

// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_BASE,
	_MED,
	_NAV,
	_MOU,
	_SYM,
	_NUM,
	_FUN,
	_ACT,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
	ND_TILD = SAFE_RANGE,
	ND_CIRC,
	ND_GRV,
	BR_AACT,
	BR_AGRV,
	BR_ATIL,
	BR_ACIR,
	BR_EACT,
	BR_ECIR,
	BR_IACT,
	BR_OACT,
	BR_OTIL,
	BR_OCIR,
	BR_UACT,
	CB_SFTW,
};

#define HR_PINL KC_LGUI
#define HR_RINL KC_LALT
#define HR_MIDL KC_LCTL
#define HR_INDL KC_LSFT

#define HR_PINR KC_RGUI
#define HR_RINR KC_LALT
#define HR_MIDR KC_RCTL
#define HR_INDR KC_RSFT

#define HR_A MT(MOD_LGUI, BR_A)
#define HR_R MT(MOD_LALT, BR_R)
#define HR_S MT(MOD_LCTL, BR_S)
#define HR_T MT(MOD_LSFT, BR_T)
#define HR_D LT(_ACT, BR_D)

#define HR_N MT(MOD_RSFT, BR_N)
#define HR_E MT(MOD_RCTL, BR_E)
#define HR_I MT(MOD_LALT, BR_I)
#define HR_O MT(MOD_RGUI, BR_O)
#define HR_H LT(_ACT, BR_H)

#define HR_DEL  LT(_MED, KC_DEL)
#define HR_BSPC LT(_NAV, KC_BSPC)
#define HR_TAB  LT(_MOU, KC_TAB)

#define HR_ENT LT(_SYM, KC_ENT)
#define HR_SPC LT(_NUM, KC_SPC)
#define HR_ESC LT(_FUN, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
	[_BASE] = LAYOUT_split_3x5_3(
			BR_Q,    BR_W,    BR_F,    BR_P,    BR_B,    BR_J,    BR_L,   BR_U,    BR_Y,    BR_QUOT,
			HR_A,    HR_R,    HR_S,    HR_T,    BR_G,    BR_M,    HR_N,   HR_E,    HR_I,    HR_O,
			BR_Z,    BR_X,    BR_C,    HR_D,    BR_V,    BR_K,    HR_H,   BR_COMM, BR_DOT,  BR_SLSH,
			                  HR_DEL,  HR_BSPC,  HR_TAB,  HR_ENT,  HR_SPC, HR_ESC
	),
	[_NUM] = LAYOUT_split_3x5_3(
			BR_ASTR, BR_7,    BR_8,    BR_9,    BR_COMM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			BR_SCLN, BR_4,    BR_5,    BR_6,    BR_EQL,  XXXXXXX, HR_INDR, HR_MIDR, HR_RINR, HR_PINR,
			ND_GRV,  BR_1,    BR_2,    BR_3,    BR_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			                  BR_DOT,  BR_0,    BR_MINS, XXXXXXX, XXXXXXX, XXXXXXX
	),
	[_SYM] = LAYOUT_split_3x5_3(
			BR_EXLM, BR_AMPR, BR_LBRC, BR_RBRC, ND_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			BR_COLN, BR_AT,   BR_LPRN, BR_RPRN, BR_PLUS, XXXXXXX, HR_INDR, HR_MIDR, HR_RINR, HR_PINR,
			ND_TILD, BR_PERC, BR_LCBR, BR_RCBR, BR_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			                  BR_HASH, BR_DLR,  BR_UNDS, XXXXXXX, XXXXXXX, XXXXXXX
	),
	[_FUN] = LAYOUT_split_3x5_3(
			KC_F12, KC_F7,    KC_F8,   KC_F9,   KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			KC_F11, KC_F4,    KC_F5,   KC_F6,   KC_EQL,  RESET,   HR_INDR, HR_MIDR, HR_RINR, HR_PINR,
			KC_F10, KC_F1,    KC_F2,   KC_F3,   KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			                  KC_DEL,  KC_BSPC, KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX
	),
	[_MED] = LAYOUT_split_3x5_3(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,
			HR_PINL, HR_INDL, HR_MIDL, HR_INDL, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
			                  XXXXXXX, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE
	),
	[_NAV] = LAYOUT_split_3x5_3(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, KC_RGHT, KC_HOME, KC_END,  KC_AGIN,
			HR_PINL, HR_INDL, HR_MIDL, HR_INDL, XXXXXXX, KC_INS,  KC_PGDN, KC_PGUP, KC_PSTE, KC_CAPS,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   KC_LEFT, KC_COPY, KC_CUT,  KC_UNDO,
			                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX
	),
	[_MOU] = LAYOUT_split_3x5_3(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, KC_RGHT, KC_HOME, KC_END,  KC_AGIN,
			HR_PINL, HR_INDL, HR_MIDL, HR_INDL, XXXXXXX, KC_INS,  KC_PGDN, KC_PGUP, KC_PSTE, KC_CAPS,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   KC_LEFT, KC_COPY, KC_CUT,  KC_UNDO,
			                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	),
	[_ACT] = LAYOUT_split_3x5_3(
			XXXXXXX, BR_ACIR, BR_ATIL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BR_UACT, XXXXXXX, BR_OTIL,
			BR_AACT, BR_AGRV, XXXXXXX, HR_INDL, XXXXXXX, XXXXXXX, HR_INDR, BR_EACT, BR_IACT, BR_OACT,
			XXXXXXX, XXXXXXX, BR_CCED, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BR_ECIR, XXXXXXX, BR_OCIR,
			                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	),
};

void
add_acute(uint16_t keycode)
{
	uint8_t tmp_mods;

	tmp_mods = get_mods(); 
	if (tmp_mods & MOD_MASK_SHIFT) { 
		unregister_mods(MOD_MASK_SHIFT); 
		tap_code(BR_ACUT); 
		set_mods(tmp_mods); 
		tap_code(keycode); 
	} else { 
		tap_code(BR_ACUT); 
		tap_code(keycode); 
	} 
}

void
add_tilda(uint16_t keycode)
{
	uint8_t tmp_mods;

	tmp_mods = get_mods(); 
	if (tmp_mods & MOD_MASK_SHIFT) { 
		unregister_mods(MOD_MASK_SHIFT); 
		tap_code(BR_TILD); 
		set_mods(tmp_mods); 
		tap_code(keycode); 
	} else { 
		tap_code(BR_TILD); 
		tap_code(keycode); 
	} 
}

void
add_circumflex(uint16_t keycode)
{
	uint8_t tmp_mods;

	tmp_mods = get_mods();
	if (tmp_mods & MOD_MASK_SHIFT) {
		tap_code(BR_TILD);
		tap_code(keycode);
	} else {
		register_code(KC_LSFT);
		tap_code(BR_TILD);
		unregister_mods(MOD_MASK_SHIFT);
		tap_code(keycode);
	}
}

uint8_t tmp_mods;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_caps_word(keycode, record))
		return false;

	switch(keycode) {
	case ND_TILD: 
		if (record->event.pressed) {
			SEND_STRING("~ ");
		}
		break;
	case ND_CIRC: 
		if (record->event.pressed) {
			SEND_STRING("^ ");
		}
		break;
	case ND_GRV: 
		if (record->event.pressed) {
			SEND_STRING("` ");
		}
		break;
	case BR_AACT: 
		if (record->event.pressed) {
			add_acute(BR_A);
		} 		
		break;
	case BR_ATIL: 
		if (record->event.pressed) {
			add_tilda(BR_A);
		} 		
		break;
	case BR_AGRV: 
		if (record->event.pressed) {
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				tap_code(BR_ACUT);
				tap_code(BR_A);
			} else {
				register_code(KC_LSFT);
				tap_code(BR_ACUT);
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_A);
			}
		}
		break;
	case BR_ACIR: 
		if (record->event.pressed) {
			add_circumflex(BR_A);
		}
		break;
	case BR_EACT: 
		if (record->event.pressed) {
			add_acute(BR_E);
		} 		
	break;
	case BR_ECIR: 
		if (record->event.pressed) {
			add_circumflex(BR_E);
		}
		break;
	case BR_IACT: 
		if (record->event.pressed) {
			add_acute(BR_I);
		} 		
		break;
	case BR_OACT: 
		if (record->event.pressed) {
			add_acute(BR_O);
		} 		
		break;
	case BR_OCIR: 
		if (record->event.pressed) {
			add_circumflex(BR_O);
		}
		break;
	case BR_OTIL: 
		if (record->event.pressed) {
			add_tilda(BR_O);
		} 		
		break;
	case BR_UACT: 
		if (record->event.pressed) {
			add_acute(BR_U);
		} 		
		break;
	}
	return true;
}

bool process_caps_word(uint16_t keycode, keyrecord_t* record) {
	static bool caps_word_enabled = false;
	static bool shifted = false;

	if (!caps_word_enabled) {
		if ((keycode & CB_SFTW) == CB_SFTW) {
			clear_mods();
			clear_oneshot_mods();
			shifted = false;
			caps_word_enabled = true;
			return false;
		}
		return true;
	}

	if (!record->event.pressed)
		return true;

	if (!((get_mods() | get_oneshot_mods()) & ~MOD_MASK_SHIFT)) {
		switch (keycode) {
		case QK_MOD_TAP ... QK_MOD_TAP_MAX:
		case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
			// Earlier return if this has not been considered tapped yet.
			if (record->tap.count == 0)
				return true;
			// Get the base tapping keycode of a mod- or layer-tap key.
			keycode &= 0xff;
		}

		switch (keycode) {
		case KC_SCLN:
		case KC_A ... KC_Z:
			if (!shifted)
				register_code(KC_LSFT);
			shifted = true;
			return true;
		// Keycodes that continue caps word but shouldn't get shifted.
		case KC_1 ... KC_0:
		case KC_BSPC:
		case KC_MINS:
		case KC_UNDS:
			if (shifted) { unregister_code(KC_LSFT); }
			shifted = false;
			return true;
			// Any other keycode disables caps word.
		}
	}

	// Disable caps word.
	caps_word_enabled = false;

	if (shifted)
		unregister_code(KC_LSFT);

	shifted = false;
	return true;
}

enum combos {
	SFT_WORD,
};
const uint16_t PROGMEM shift_word[] = {HR_T, HR_N, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
	[SFT_WORD] = COMBO(shift_word, CB_SFTW),
};
