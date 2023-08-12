#include QMK_KEYBOARD_H

// void matrix_init_kb(void) {
//   debug_enable = true;
//   debug_matrix = true;
//   debug_mouse  = true;
// }

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Each layer gets a name for readability.
// The underscores don't mean anything - you can
// have a layer called STUFF or any other name.
// Layer names don't all need to be of the same
// length, and you can also skip them entirely
// and just use numbers.

/**
 * Define Layer 부분
*/
#define _BASE    0
#define _MODS    1
#define _OBSIDIAN_MACRO    2 
#define _QMK_MGMT    3 
#define _MangaDL 4
#define _Mouse 5

#define _MAXLAYER 5
// Define the keycode, `QK_USER` avoids collisions with existing keycodes
enum keycodes {
  KC_CYCLE_LAYERS = QK_USER,
  MOUSE_RIGHT_CLICK_L,
  SPACE_CTRL_TAB,
  SS_PYTHON_CODEBLOCK,
  OBSIDIAN_OPEN_CHATGPTTEMP,
  TabToggle_Toggle, // 탭전환 기능을 쓰기 위해 전역변수에서 toggle변수를 TF 전환
};

//SET Keycodes
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// { K00,   K01,   K02,   K03 }
// { K10,   K11,   K12,   K13 } 
// { KC_NO, KC_NO, KC_NO, K23 }  

       /* LAYER 0
        BASE LAYER
    /---------------------------------------`
    |    00   |    01   |    02   |    03   |
    |---------|---------|---------|---------|--------------`
    |    E    |    F    |    G    |    H    |  NextLayer   |
    \---------------------------------------'--------------'
    */

	[_BASE] = LAYOUT(
		KC_0, KC_1, KC_2, KC_3, 
		KC_4, KC_5, KC_6, KC_7, 
		                        KC_CYCLE_LAYERS),

       /* LAYER 1
        SUB LAYER
    /---------------------------------------`
    |    A    |    B    |    C    |    D    |
    |---------|---------|---------|---------|--------------`
    |    E    |    F    |    G    |    H    |  NextLayer   |
    \---------------------------------------'--------------'
    */

	[_MODS] = LAYOUT(
	     KC_A,    KC_B,    KC_C,    KC_D, 
	     KC_E,    KC_F,    KC_G,    KC_H, 
		                                    KC_CYCLE_LAYERS),

       /* LAYER 2
        Third Layer-Encoder test and boot
        Encoder Layer?  
    /---------------------------------------`
    |    A    |    B    |    C    |    D    |
    |---------|---------|---------|---------|--------------`
    |    E    | chatgpt |py cdblk |    H    |  NextLayer   |
    \---------------------------------------'--------------'
    */
	[_OBSIDIAN_MACRO] = LAYOUT(
		KC_X   , _______, KC_LALT, _______, 
		_______, OBSIDIAN_OPEN_CHATGPTTEMP, SS_PYTHON_CODEBLOCK, _______, 
                                            KC_CYCLE_LAYERS),

           /* LAYER 3
        FOurth Layer-Encoder test and boot 
    /---------------------------------------`
    |    Y    |    B    |    C    |    D    |
    |---------|---------|---------|---------|--------------`
    | progrm  |    F    |    G    |    H    |  NextLayer   |
    \---------------------------------------'--------------'
    */

	[_QMK_MGMT] = LAYOUT(
		KC_Y, _______, _______, _______, 
		QK_BOOTLOADER, _______, _______, _______, 
		                                    KC_CYCLE_LAYERS),
                                        
           /* LAYER 4
        FOurth Layer-Encoder test and boot 
    /--------------------------------------- --------------`
    |TT(mouse)|    B    | NextTab | CPY LNK |              |
    |---------|---------|---------|---------|--------------`
    | MS_MID  |    F    |    G    | DLnNxtT |  NextLayer   |
    \---------------------------------------'--------------'
    */

	[_MangaDL] = LAYOUT(
		TT(_Mouse), _______, TabToggle_Toggle, MOUSE_RIGHT_CLICK_L, 
		KC_MS_BTN3, _______, _______,          SPACE_CTRL_TAB, 
		                                    KC_CYCLE_LAYERS),
           /* LAYER 4
        FOurth Layer-Encoder test and boot 
    /--------------------------------------- --------------`
    |    A    |   LMB   |  MS_up  |   RMB   |              |
    |---------|---------|---------|---------|--------------`
    |  MS_L   | MS_down |  MS_R   |   MMB   |   MS_Wheel   |
    \---------------------------------------'--------------'
    */

	[_Mouse] = LAYOUT(
		TabToggle_Toggle,      KC_BTN1,  KC_MS_U,   KC_BTN2, 
		KC_BTN3 ,  KC_MS_L,  KC_MS_D,   KC_MS_R,   
		                                         KC_CYCLE_LAYERS)
};

bool is_tabtoggle_ON; // TabToggle_Toggle 키코드가 사용하는 변수, TabToggle_Toggle 키가 눌리면 True로 바뀐다. 떼지면 False 로 바뀐다. 

bool encoder_update_user(uint8_t index, bool clockwise) {
    // 현재 활성화된 레이어를 가져옵니다.
    uint32_t layer =  get_highest_layer(layer_state);

    // 레이어에 따라 다른 동작을 수행합니다.
    switch (layer) {
        case 0: // 0th layer
            /*clockwise 값을 확인한 뒤 
            (참일때 실행될 내용) :        (거짓일때 실행될 내용) */
            clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            break;

        case 1: // 1th layer
            // LAYER4에서 엔코더 동작을 정의합니다.
            if (clockwise) {
                // 시계 방향 동작
                register_code(KC_LCTL);
                tap_code(KC_TAB);
                unregister_code(KC_LCTL);
            } else {
                // 반시계 방향 동작
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            break;

        case 2: // 2th layer
            // LAYER1에서 엔코더 동작을 정의합니다.
            if (clockwise) {
                // 시계 방향 동작
                tap_code(KC_TAB);
            } else {
                // 반시계 방향 동작
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            break;

        case 3: // 1th layer
            clockwise ? tap_code(KC_MS_DOWN) : tap_code(KC_MS_UP);
            break;

        case _MangaDL: // 1th layer
            if (is_tabtoggle_ON == true){ // 탭토글 키가 눌렸으면? - 탭전환을 사용한다. 
              if (clockwise) {
                // 시계 방향 동작
                register_code(KC_LCTL);
                tap_code(KC_TAB);
                unregister_code(KC_LCTL);
              } else {
                // 반시계 방향 동작
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_TAB);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
              }
            }
            else{ // 아무것도 없이 엔코더 돌린경우 
              clockwise ? tap_code(KC_MS_DOWN) : tap_code(KC_MS_UP);
            }
            break;
        case _Mouse: // 1th layer
            clockwise ? tap_code(KC_MS_DOWN) : tap_code(KC_MS_UP);
            break;
          
        default:
            // 기본 동작
            // TODO: 동작 정의
            break;

    } // switch (layer) END
    return false;
};

/**
 * Define Layer 부분을 참고해서 넘버링을 넣자 
*/

// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END   _MAXLAYER // 현재 5인 상태 

// Add the behaviour of this new keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_CYCLE_LAYERS: // 레이어 교환키였을 경우
      // Our logic will happen on presses, nothing is done on releases
      if (!record->event.pressed) { 
        // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
        return false;
      }

      uint8_t current_layer = get_highest_layer(layer_state);

      // Check if we are within the range, if not quit
      if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
        return false;
      }

      uint8_t next_layer = current_layer + 1;
      if (next_layer > LAYER_CYCLE_END) {
          next_layer = LAYER_CYCLE_START;
      }
      layer_move(next_layer);
      return false;

    case MOUSE_RIGHT_CLICK_L: // 우클릭후 l 누르는 
      if (record->event.pressed) {
        // 마우스 우클릭 이벤트를 실행하는 코드 작성
        tap_code(KC_MS_BTN2);
      } else {
        // 'L' 키를 누르는 코드 작성
        tap_code(KC_L);
      }
      return false;

    case SPACE_CTRL_TAB: // 우클릭후 l 누르는 
      if (record->event.pressed) {
        // 스페이스바를 누르고
        tap_code(KC_SPACE);
      } else {
        // 컨트롤탭으로 다음탭으로 이동
        register_code(KC_LCTL);
        tap_code(KC_TAB);
        unregister_code(KC_LCTL);
      }
      return false;

    case SS_PYTHON_CODEBLOCK: // 파이썬 코드블럭 던지는 코드
      if (record->event.pressed) {
        SEND_STRING("``` python\n");      
        // SEND_STRING("``` python\n\n```");      
      }
      return false;
      
    case OBSIDIAN_OPEN_CHATGPTTEMP: // chatgpt temp 탭을 새창에 여는 코드
      if (record->event.pressed) {
        register_code(KC_LCTL);
        tap_code(KC_O);
        unregister_code(KC_LCTL);
        SEND_STRING("chatgpt-temp");  
      }
      else{
        register_code(KC_LCTL);
        tap_code(KC_ENTER);
        unregister_code(KC_LCTL);
      }
      return false;

    case TabToggle_Toggle: // 컨트롤탭을 쓸지 안쓸지 변수를 업데이트하기만 하는 코드
      if (record->event.pressed) {
          is_tabtoggle_ON = true; // 변수의 bool 값 true로 변경
      } 
      else {
          is_tabtoggle_ON = false; // 변수의 bool 값 false로 변경
      }
      return false;
    
    // Process other keycodes normally
    default:
      return true;
  }
}

// Place `KC_CYCLE_LAYERS` as a keycode in your keymap