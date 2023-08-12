#pragma once

/* Reduce tapdance required taps from 5 to 2 */
#define TAPPING_TOGGLE 2




/**
 * 이하는 https://github.com/manna-harbour/miryoku_qmk/blob/bdb9fd81e8aa2afb3882f7c0f6ae2d3ba448ac93/users/manna-harbour_miryoku/config.h
 * 에서 참고하였음
 * 
 * 
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_mouse_keys.md 
 * 또한 참고
*/
// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64