#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include <driver-led.h>

static void test_setLed_onOff(void **state) {
    for(led_id_e index = LED1; index <= LED16; index++) {
        reg_leds = 0xFFFF;
        setLed(index, LED_OFF);
        uint16_t expected = 0xFFFF & ~(1 << index);
        assert_int_equal(reg_leds, expected);
    }
}

static void test_setLed_onOn(void **state) {
    for(led_id_e index = LED1; index <= LED16; index++) {
        reg_leds = 0x0;
        setLed(index, LED_ON);
        uint16_t expected = (1 << index);
        assert_int_equal(reg_leds, expected);
    }
}

static void test_setAllLeds_onOff(void **state) {
    reg_leds = 0xFFFF;
    setAllLeds(LED_OFF);
    assert_int_equal(reg_leds, 0x0);
}

static void test_setAllLeds_onOn(void **state) {
    reg_leds = 0x0;
    setAllLeds(LED_ON);
    assert_int_equal(reg_leds, 0xFFFF);
}

static void test_queryLed_onOff(void **state) {
    reg_leds = 0x0;
    for(led_id_e index = LED1; index <= LED16; index++) {
        assert_int_equal(queryLed(index), LED_OFF);
    }
}

static void test_queryLed_onOn(void **state) {
    reg_leds = 0xFFFF;
    for(led_id_e index = LED1; index <= LED16; index++) {
        assert_int_equal(queryLed(index), LED_ON);
    }
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_setLed_onOff),
        cmocka_unit_test(test_setLed_onOn),
        cmocka_unit_test(test_setAllLeds_onOff),
        cmocka_unit_test(test_setAllLeds_onOn),
        cmocka_unit_test(test_queryLed_onOff),
        cmocka_unit_test(test_queryLed_onOn),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}