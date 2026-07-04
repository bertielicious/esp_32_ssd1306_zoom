#include "write_spi_command.h"
#include "driver/spi_master.h"
#include "config_dev.h"

void write_spi_command(uint8_t cmd)
{
    spi_transaction_t t = 
    {
        .length = 8,
        .tx_buffer = &cmd,
        .user = (void*)0    // 0 = command for your pre_cb
        
    };
    spi_device_polling_transmit(ssd1306_handle, &t);
}