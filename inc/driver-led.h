#include <stdint.h>

uint16_t reg_leds = 0x0;

typedef enum {
    LED_OFF = 0,
    LED_ON = 1, 
} led_state_e;

typedef enum {
    LED1 = 0,
    LED2 = 1,
    LED3 = 2,
    LED4 = 3,
    LED5 = 4,
    LED6 = 5,
    LED7 = 6,
    LED8 = 7,
    LED9 = 8,
    LED10 = 9,
    LED11 = 10,
    LED12 = 11,
    LED13 = 12,
    LED14 = 13,
    LED15 = 14,
    LED16 = 15,
} led_id_e;

void setLed(led_id_e id, led_state_e state);
void setAllLeds(led_state_e state);
led_state_e queryLed(led_id_e id);
