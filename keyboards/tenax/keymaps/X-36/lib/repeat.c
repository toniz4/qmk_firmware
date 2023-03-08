#include "repeat.h"

#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

// Initialize variables holding the bitfield
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record, int repeat_keycode) {
	mod_state = get_mods();
	oneshot_mod_state = get_oneshot_mods();
	if (keycode != repeat_keycode) {
		// Early return when holding down a pure layer key
		// to retain modifiers
		switch (keycode) {
		case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
		case QK_MOMENTARY ... QK_MOMENTARY_MAX:
		case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
		case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
		case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
		case QK_TO ... QK_TO_MAX:
		case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
			return;
		}
		last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
		switch (keycode) {
		case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
		case QK_MOD_TAP ... QK_MOD_TAP_MAX:
			if (record->event.pressed) {
				last_keycode = GET_TAP_KC(keycode);
			}
			break;
		default:
			if (record->event.pressed) {
				last_keycode = keycode;
			}
			break;
		}
	} else { // keycode == repeat_keycode
		if (record->event.pressed) {
			register_mods(last_modifier);
			register_code16(last_keycode);
		} else {
			unregister_code16(last_keycode);
			unregister_mods(last_modifier);
		}
	}
}
