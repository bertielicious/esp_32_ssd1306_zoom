#include "constants.h"
#include "driver/gpio.h"
void config_display_gpio(display_pins_t *t)
{
    gpio_config_t gpio = 
    {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1LL<<t->dc) | (1LL<<t->res) | (1LL<<t->cs),
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .pull_up_en = GPIO_PULLUP_DISABLE
    };
    gpio_config(&gpio);
   
}