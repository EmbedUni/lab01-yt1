/********************************
 * Left-right alternating blink
 * 
 * Flashes left LED 5 times, then
 * right LED 5 times. Repeat.
 *******************************/
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS 250

#define LED0_NI DT_ALIAS(led0)
#define LED1_NI DT_ALIAS(led1)
const struct gpio_dt_spec leftLED = GPIO_DT_SPEC_GET(LED0_NI, gpios);
const struct gpio_dt_spec rightLED = GPIO_DT_SPEC_GET(LED1_NI, gpios);

int main(void) {
    int i = 0;
    gpio_pin_configure_dt(&leftLED, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure_dt(&rightLED, GPIO_OUTPUT_INACTIVE);
    while (true) {
        while (i<10) { // Flash the left LED five times
            gpio_pin_toggle_dt(&leftLED);
            k_msleep(SLEEP_TIME_MS);
            i = i + 1;
        }
        while (i>0) { // Flash the right LED five times
            gpio_pin_toggle_dt(&rightLED);
            k_msleep(SLEEP_TIME_MS);
            i = i - 1;
        }
    }
}
