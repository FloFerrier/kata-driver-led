#include "driver-led.h"

void setLed(led_id_e id, led_state_e state) {
    switch (state)
    {
    case LED_OFF:
        reg_leds &= ~(1 << id);
        break;
    case LED_ON:
        reg_leds |= (1 << id);
        break;
    default:
        break;
    }
}

void setAllLeds(led_state_e state) {
    for(led_id_e id = LED1; id <= LED16; id++) {
        setLed(id, state);
    }
}

led_state_e queryLed(led_id_e id) {
    led_state_e state = (reg_leds & (1 << id)) >> id;
    return state;
}
