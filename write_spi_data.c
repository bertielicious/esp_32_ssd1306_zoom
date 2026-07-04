#include "write_spi_data.h"
#include "driver/spi_master.h"
#include "config_dev.h"
void write_spi_data(const uint8_t *data, uint8_t len)
{
    spi_transaction_t t =
    {
       .length = len * 8,
       .tx_buffer = data,
       .user = (void*)1 
    };
    spi_device_polling_transmit(ssd1306_handle, &t);
}