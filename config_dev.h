#ifndef CONFIG_DEV_H
#define CONFIG_DEV_H
#include "constants.h"
#include "driver/spi_master.h"
extern spi_device_handle_t ssd1306_handle;
void config_dev(spi_device_handle_t *handle, display_pins_t *dev);

#endif