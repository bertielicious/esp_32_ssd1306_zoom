#include "config_dev.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_log.h"

// Bring pre_cb into this file
extern void IRAM_ATTR pre_cb(spi_transaction_t *t);

void config_dev(spi_device_handle_t *handle, display_pins_t *dev)

{
    spi_device_interface_config_t ssd1306 =
    {
        .clock_source = SPI_CLK_SRC_DEFAULT,
        .clock_speed_hz = 4 * 1000 * 1000, //4MHz
        .spics_io_num = dev->cs,
        .queue_size = 4,
        .cs_ena_posttrans = 0,
        .mode = 0,
        .command_bits = 0,
        .address_bits = 0,
        .dummy_bits = 0,
        .duty_cycle_pos = 128,
        .cs_ena_pretrans = 0,
        .input_delay_ns = 0,
        .flags = 0,
        .pre_cb = pre_cb  //Callback to be called before a transmission is started
    };
    spi_bus_add_device(SPI2_HOST, &ssd1306, &ssd1306_handle);

}