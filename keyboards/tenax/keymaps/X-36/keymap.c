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

#include "sendstring_brazilian_abnt2.h"
#include "lib/repeat.h"

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
	_MIS,
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
	REPEAT,
};

#define HR_PINL KC_LGUI
#define HR_RINL KC_LALT
#define HR_MIDL KC_LCTL
#define HR_INDL KC_LSFT

#define HR_PINR KC_RGUI
#define HR_RINR KC_LALT
#define HR_MIDR KC_RCTL
#define HR_INDR KC_RSFT

#define HR_R MT(MOD_LGUI, BR_R)
#define HR_S MT(MOD_LALT, BR_S)
#define HR_T MT(MOD_LCTL, BR_T)
#define HR_H MT(MOD_LSFT, BR_H)
#define HR_D LT(_ACT, BR_D)

#define HR_N MT(MOD_RSFT, BR_N)
#define HR_I MT(MOD_RCTL, BR_I)
#define HR_A MT(MOD_LALT, BR_A)
#define HR_O MT(MOD_RGUI, BR_O)
#define HR_L LT(_ACT, BR_L)

#define HR_TAB  LT(_MIS, KC_TAB)
#define HR_E    LT(_NAV, BR_E)
#define HR_BSPC LT(_MOU, KC_BSPC)

#define HR_ENT LT(_SYM, KC_ENT)
#define HR_SPC LT(_NUM, KC_SPC)
#define HR_ESC LT(_FUN, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base */
	[_BASE] = LAYOUT_split_3x5_3(
		BR_J,    BR_C,    BR_Y,    BR_F,    BR_K,    BR_Z,    BR_W,   BR_U,    REPEAT,    BR_Q,
		HR_R,    HR_S,    HR_T,    HR_H,    BR_P,    BR_M,    HR_N,   HR_I,    HR_A,    HR_O,
		BR_X,    BR_V,    BR_G,    HR_D,    BR_B,    BR_QUOT, HR_L,   BR_COMM, BR_DOT, BR_SLSH,
		                  HR_TAB,  HR_E,    HR_BSPC, HR_ENT,  HR_SPC, HR_ESC
		),
	[_NUM] = LAYOUT_split_3x5_3(
		BR_EXLM, BR_4,    BR_5,    BR_6,    BR_COMM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		BR_COLN, BR_1,    BR_2,    BR_3,    BR_EQL,  XXXXXXX, HR_INDR, HR_MIDR, HR_RINR, HR_PINR,
		BR_PLUS, BR_7,    BR_8,    BR_9,    BR_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		                  BR_DOT,  BR_0,    BR_MINS, XXXXXXX, XXXXXXX, XXXXXXX
		),
	[_SYM] = LAYOUT_split_3x5_3(
		BR_ASTR, BR_AMPR, BR_LCBR, BR_RCBR, ND_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		BR_SCLN, BR_AT,   BR_LPRN, BR_RPRN, ND_GRV,  XXXXXXX, HR_INDR, HR_MIDR, HR_RINR, HR_PINR,
		ND_TILD, BR_PERC, BR_LBRC, BR_RBRC, BR_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		                  BR_HASH, BR_DLR,  BR_UNDS, XXXXXXX, XXXXXXX, XXXXXXX
		),
	[_FUN] = LAYOUT_split_3x5_3(
		KC_F12, KC_F4,    KC_F5,   KC_F6,   KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		KC_F11, KC_F1,    KC_F2,   KC_F3,   KC_EQL,  XXXXXXX, HR_INDR, HR_MIDR, HR_RINR, HR_PINR,
		KC_F10, KC_F7,    KC_F8,   KC_F9,   KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		                  RESET,   KC_DEL,  KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX
		),
	[_MED] = LAYOUT_split_3x5_3(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,
		HR_PINL, HR_INDL, HR_MIDL, HR_INDL, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
		                  XXXXXXX, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE
		),
	[_NAV] = LAYOUT_split_3x5_3(
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME, KC_END,  KC_AGIN,
		HR_PINL, HR_INDL, HR_MIDL, HR_INDL, XXXXXXX, KC_INS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, KC_PGDN, KC_COPY, KC_CUT,  KC_UNDO,
		                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX
		),
	[_MOU] = LAYOUT_split_3x5_3(
		BR_Q,    XXXXXXX, KC_LABK, KC_RABK, XXXXXXX, KC_DOWN, KC_RGHT, KC_HOME, KC_END,  KC_AGIN,
		KC_ENT,  KC_SPC,  KC_LEFT, KC_RGHT, XXXXXXX, KC_INS,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
		BR_X,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   KC_LEFT, KC_COPY, KC_CUT,  KC_UNDO,
		                  XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2
		),
	[_ACT] = LAYOUT_split_3x5_3(
		XXXXXXX, BR_CCED, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BR_UACT, BR_ATIL, BR_OTIL,
		XXXXXXX, XXXXXXX, XXXXXXX, HR_INDL, XXXXXXX, XXXXXXX, HR_INDR, BR_IACT, BR_AACT, BR_OACT,
		XXXXXXX, XXXXXXX, XXXXXXX, BR_ECIR, XXXXXXX, XXXXXXX, XXXXXXX, BR_AGRV, BR_ACIR, BR_OCIR,
		                  XXXXXXX, BR_EACT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
		),
	[_MIS] = LAYOUT_split_3x5_3(
		BR_Q,    BR_W,    BR_F,    BR_P,    BR_B,    BR_J,    BR_L,   BR_U,    BR_Y,    BR_QUOT,
		KC_ENT,  KC_BTN1, KC_BTN3, KC_BTN2, BR_G,    BR_M,    HR_N,   HR_E,    HR_I,    HR_O,
		BR_Z,    BR_X,    BR_C,    XXXXXXX,    BR_V,    BR_K,    HR_H,   BR_COMM, BR_DOT,  BR_SLSH,
		                  XXXXXXX, KC_SPC,  HR_TAB,  HR_ENT,  HR_SPC, HR_ESC
		),
};

void
add_accent(uint16_t alpha_keycode, uint16_t accent_keycode)
{
	uint8_t mod_state;

	mod_state = get_mods();

	unregister_mods(MOD_MASK_SHIFT);
	tap_code16(accent_keycode);
	set_mods(mod_state);
	tap_code(alpha_keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_caps_word(keycode, record))
		return false;

	process_repeat_key(keycode, record, REPEAT);
	switch(keycode) {
	case ND_TILD:
		if (record->event.pressed) {
			SEND_STRING("~");
		}
		break;
	case ND_CIRC:
		if (record->event.pressed) {
			SEND_STRING("^");
		}
		break;
	case ND_GRV:
		if (record->event.pressed) {
			SEND_STRING("`");
		}
		break;
	case BR_AACT:
		if (record->event.pressed) {
			add_accent(BR_A, BR_ACUT);
		}
		break;
	case BR_ATIL:
		if (record->event.pressed) {
			add_accent(BR_A, BR_TILD);
		}
		break;
	case BR_AGRV:
		if (record->event.pressed) {
			add_accent(BR_A, BR_GRV);
		}
		break;
	case BR_ACIR:
		if (record->event.pressed) {
			add_accent(BR_A, BR_CIRC);
		}
		break;
	case BR_EACT:
		if (record->event.pressed) {
			add_accent(BR_E, BR_ACUT);
		}
	break;
	case BR_ECIR:
		if (record->event.pressed) {
			add_accent(BR_E, BR_CIRC);
		}
		break;
	case BR_IACT:
		if (record->event.pressed) {
			add_accent(BR_I, BR_ACUT);
		}
		break;
	case BR_OACT:
		if (record->event.pressed) {
			add_accent(BR_O, BR_ACUT);
		}
		break;
	case BR_OCIR:
		if (record->event.pressed) {
			add_accent(BR_O, BR_CIRC);
		}
		break;
	case BR_OTIL:
		if (record->event.pressed) {
			add_accent(BR_O, BR_TILD);
		}
		break;
	case BR_UACT:
		if (record->event.pressed) {
			add_accent(BR_U, BR_ACUT);
		}
		break;
	}
	return true;
}

bool caps_word_press_user(uint16_t keycode) {
	switch (keycode) {
	/* Keycodes that continue Caps Word, with shift applied. */
	case BR_A ... BR_Z:
	case BR_AACT ... BR_UACT:
	case REPEAT:
		add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
		return true;

	/* Keycodes that continue Caps Word, without shifting. */
	case BR_1 ... BR_0:
	case KC_BSPC:
	case BR_MINS:
	case BR_UNDS:
		return true;
	default:
		return false;  // Deactivate Caps Word.
	}
}

enum combo_events {
  CAPS_COMBO,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM caps_combo[] = {HR_H, HR_N, COMBO_END};

combo_t key_combos[] = {
  [CAPS_COMBO] = COMBO_ACTION(caps_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        caps_word_on();
      }
      break;
  }
}
