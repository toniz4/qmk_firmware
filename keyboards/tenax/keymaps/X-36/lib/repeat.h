#pragma once

#include QMK_KEYBOARD_H

#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

void process_repeat_key(uint16_t keycode, const keyrecord_t *record, int repeat_keycode);
