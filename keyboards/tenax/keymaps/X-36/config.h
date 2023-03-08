#pragma once

#undef DEBOUNCE
#define DEBOUNCE 5

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 170

#define PERMISSIVE_HOLD

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD 

// Auto Shift
/* #define NO_AUTO_SHIFT_ALPHA */
/* #define AUTO_SHIFT_TIMEOUT TAPPING_TERM */
/* #define AUTO_SHIFT_NO_SETUP */

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      4
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    32

#define LED_PIN_ON_STATE 0
#define LED_CAPS_LOCK_PIN D5
