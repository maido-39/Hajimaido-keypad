#include "quantum.h"

#include <stdio.h>

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);    
}

/**
 * Define Layer 부분
*/
#define _BASE    0
#define _MODS    1
#define _OBSIDIAN_MACRO    2 
#define _QMK_MGMT    3 
#define _MangaDL 4

// OLED
bool oled_task_user(void) {
    render_logo();
    //oled_scroll_right(); 이부분은 주석끄면 로고가 스크롤됩니다 안꺼도 config.h에서 준 시간 이후 스크롤됩니다
    oled_write_P(PSTR("Layer: "), false);
    uint32_t curr_layer = get_highest_layer(layer_state);
            switch (curr_layer) {
                case 0:
                    oled_write_ln_P(PSTR("_BASE"), false);
                    break;
                case 1:
                    oled_write_ln_P(PSTR("_MODS"), false);
                    break;
                case 2:
                    oled_write_ln_P(PSTR("_OBS_MACRO"), false);
                    break;  
                case 3:
                    oled_write_ln_P(PSTR("_QMK_MGMT"), false);
                    break;  
                case 4:
                    oled_write_ln_P(PSTR("_MangaDL"), false);
                    break;  
                case 5:
                    oled_write_ln_P(PSTR("_Mouse"), false);
                    break;  
                    
                                    // 추가적인 레이어가 있다면 여기에 추가합니다.
                default:
                    oled_write_ln_P(PSTR("ETC"), false);
                    break;
            }
    return false;
}