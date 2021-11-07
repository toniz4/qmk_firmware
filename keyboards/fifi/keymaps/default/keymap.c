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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_BASE,
	_NAV,
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
};

#define HR_PINL KC_LGUI
#define HR_RINL KC_LALT
#define HR_MIDL KC_LCTL
#define HR_INDL KC_LSFT

#define HR_PINR KC_RGUI
#define HR_RINR KC_RALT
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

#define HR_DEL  LT(_NAV, KC_DEL)
#define HR_BSPC LT(_NAV, KC_BSPC)
#define HR_TAB  LT(_NAV, KC_TAB)

#define HR_ENT LT(_SYM, KC_ENT)
#define HR_SPC LT(_NUM, KC_SPC)
#define HR_ESC LT(_FUN, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
	[_BASE] = LAYOUT_split_3x5_3(
			BR_Q,    BR_W,    BR_F,    BR_P,    BR_B,    BR_J,    BR_L,   BR_U,    BR_Y,    BR_QUOT,
			HR_A,    HR_R,    HR_S,    HR_T,    BR_G,    BR_M,    HR_N,   HR_E,    HR_I,    HR_O,
			BR_Z,    BR_X,    BR_C,    HR_D,    BR_V,    BR_K,    HR_H,   BR_COMM, BR_DOT,  BR_SLSH,
			                  HR_DEL,  HR_BSPC, HR_TAB,  HR_ENT,  HR_SPC, HR_ESC
	),
	[_NUM] = LAYOUT_split_3x5_3(
			BR_ASTR, BR_7,    BR_8,    BR_9,    BR_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			BR_SCLN, BR_4,    BR_5,    BR_6,    BR_EQL,  XXXXXXX, HR_INDR, HR_MIDR, HR_RINR, HR_PINR,
			ND_GRV,  BR_1,    BR_2,    BR_3,    BR_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			                  BR_DOT,  BR_0,    BR_MINS, XXXXXXX, XXXXXXX, XXXXXXX
	),
	[_SYM] = LAYOUT_split_3x5_3(
			BR_EXLM, BR_AMPR, BR_LCBR, BR_RCBR, ND_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			BR_COLN, BR_AT,   BR_LPRN, BR_RPRN, BR_PLUS, XXXXXXX, HR_INDR, HR_MIDR, HR_RINR, HR_PINR,
			ND_TILD, BR_PERC, BR_LBRC, BR_RBRC, BR_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			                  BR_HASH, BR_DLR,  BR_UNDS, XXXXXXX, XXXXXXX, XXXXXXX
	),
	[_FUN] = LAYOUT_split_3x5_3(
			KC_F12, KC_F7,    KC_F8,   KC_F9,   KC_B,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			KC_F11, KC_F4,    KC_F5,   KC_F6,   KC_EQL,  RESET,   HR_INDR, HR_MIDR, HR_RINR, HR_PINR,
			KC_F10, KC_F1,    KC_F2,   KC_F3,   KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			                  KC_DEL,  KC_BSPC, KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX
	),
	[_NAV] = LAYOUT_split_3x5_3(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
			HR_PINL, HR_INDL, HR_MIDL, HR_INDL, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   KC_LEFT, XXXXXXX, XXXXXXX, XXXXXXX,
			                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	),
	[_ACT] = LAYOUT_split_3x5_3(
			XXXXXXX, BR_ACIR, BR_ATIL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BR_UACT, XXXXXXX, BR_OTIL,
			BR_AACT, BR_AGRV, XXXXXXX, HR_INDL, XXXXXXX, XXXXXXX, HR_INDR, BR_EACT, BR_IACT, BR_OACT,
			XXXXXXX, XXXXXXX, BR_CCED, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BR_ECIR, XXXXXXX, BR_OCIR,
			                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (!is_keyboard_master())
		return OLED_ROTATION_180;  // flips the display 180 degrees if offhand

	return OLED_ROTATION_270;
}

#define L_BASE 0
#define L_NUM 2
#define L_SYM 4
#define L_FUN 8
#define L_NAV 16

void oled_render_layer_state(void) {
	oled_write_P(PSTR("Layer\n"), false);

	oled_write_P(PSTR(" Def "), layer_state == 0);
	oled_write_P(PSTR(" Nav "), CHECK_BIT(layer_state, _NAV) != 0);
	oled_write_P(PSTR(" Sym "), CHECK_BIT(layer_state, _SYM) != 0);
	oled_write_P(PSTR(" Num "), CHECK_BIT(layer_state, _NUM) != 0);
	oled_write_P(PSTR(" Fun "), CHECK_BIT(layer_state, _FUN) != 0);
	oled_write_P(PSTR(" Act "), CHECK_BIT(layer_state, _ACT) != 0);
}

void
oled_render_mod_state(void)
{
	int mod_state;
	mod_state = get_mods();

	oled_write_ln_P(PSTR("\nMods\n"), false);
	oled_write_P(PSTR(" "), false);
	oled_write_P(PSTR("G"), (mod_state & MOD_MASK_GUI) != 0);
	oled_write_P(PSTR("A"), (mod_state & MOD_MASK_ALT) != 0);
	oled_write_P(PSTR("S"), (mod_state & MOD_MASK_SHIFT) != 0);
	oled_write_P(PSTR("C"), (mod_state & MOD_MASK_CTRL) != 0);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

static void oled_render_logo(void) {
	static const char  PROGMEM logo[] = {
		// 'grey', 128x32px
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
		0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
		0x0f, 0x0f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xef, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
		0xe0, 0xf0, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
		0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 
		0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	oled_write_raw_P(logo, sizeof(logo));
}

void oled_task_user(void) {
	if (is_keyboard_master()) {
		oled_render_layer_state();
		oled_render_mod_state();
	} else {
		oled_render_logo();
	}
}
#endif // OLED_ENABLE

uint8_t tmp_mods;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_ACUT);
				set_mods(tmp_mods);
				tap_code(BR_A);
			} else {
				tap_code(BR_ACUT);
				tap_code(BR_A);
			}
		} 		
		break;
	case BR_ATIL: 
		if (record->event.pressed) {
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_TILD);
				set_mods(tmp_mods);
				tap_code(BR_A);
			} else {
				tap_code(BR_TILD);
				tap_code(BR_A);
			}
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
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				tap_code(BR_TILD);
				tap_code(BR_A);
			} else {
				register_code(KC_LSFT);
				tap_code(BR_TILD);
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_A);
			}
		}
		break;
	case BR_EACT: 
		if (record->event.pressed) {
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_ACUT);
				set_mods(tmp_mods);
				tap_code(BR_E);
			} else {
				tap_code(BR_ACUT);
				tap_code(BR_E);
			}
		} 		
	break;
	case BR_ECIR: 
		if (record->event.pressed) {
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				tap_code(BR_TILD);
				tap_code(BR_E);
			} else {
				register_code(KC_LSFT);
				tap_code(BR_TILD);
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_E);
			}
		}
		break;
	case BR_IACT: 
		if (record->event.pressed) {
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_ACUT);
				set_mods(tmp_mods);
				tap_code(BR_I);
			} else {
				tap_code(BR_ACUT);
				tap_code(BR_I);
			}
		} 		
		break;
	case BR_OACT: 
		if (record->event.pressed) {
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_ACUT);
				set_mods(tmp_mods);
				tap_code(BR_O);
			} else {
				tap_code(BR_ACUT);
				tap_code(BR_O);
			}
		} 		
		break;
	case BR_OCIR: 
		if (record->event.pressed) {
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				tap_code(BR_TILD);
				tap_code(BR_O);
			} else {
				register_code(KC_LSFT);
				tap_code(BR_TILD);
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_O);
			}
		}
		break;
	case BR_OTIL: 
		if (record->event.pressed) {
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_TILD);
				set_mods(tmp_mods);
				tap_code(BR_O);
			} else {
				tap_code(BR_TILD);
				tap_code(BR_O);
			}
		} 		
		break;
	case BR_UACT: 
		if (record->event.pressed) {
			tmp_mods = get_mods();
			if (tmp_mods & MOD_MASK_SHIFT) {
				unregister_mods(MOD_MASK_SHIFT);
				tap_code(BR_ACUT);
				set_mods(tmp_mods);
				tap_code(BR_U);
			} else {
				tap_code(BR_ACUT);
				tap_code(BR_U);
			}
		} 		
		break;
	}
	return true;
}
