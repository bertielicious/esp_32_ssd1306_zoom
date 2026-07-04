
#include "config_spi.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "esp_log.h"
static const char *TAG = "config_spi";

// PRE-CALLBACK (local to this module)
// ---------------------------------------------------------
void IRAM_ATTR pre_cb(spi_transaction_t *t)
{
    int dc = (int)t->user;   // 0 = command, 1 = data
    gpio_set_level(21, dc);
}
// ---------------------------------------------------------
// SPI BUS INITIALISATION
// ---------------------------------------------------------

void config_spi(display_pins_t *spi)
{
    spi_bus_config_t config_spi_bus =
    {
        .mosi_io_num = spi->mosi,
        .sclk_io_num = spi->sck,
        .max_transfer_sz = 4096,
        .miso_io_num = -1,
        .quadhd_io_num = -1,
        .quadwp_io_num = -1 
    };
    spi_bus_initialize(SPI2_HOST, &config_spi_bus, SPI_DMA_CH_AUTO);

    // ---------------------------------------------------------

}