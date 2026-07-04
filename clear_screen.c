#include "write_spi_command.h"
#include "write_spi_data.h"
#include <stdint.h>
#include <string.h>
void clear_screen(void)
{
    uint8_t zeros[128];
    memset(zeros, 0, sizeof(zeros));

    // Page addressing mode
    write_spi_command(0x20);
    write_spi_command(0x02);   // page mode

    for (int page = 0; page < 8; page++)
    {
        write_spi_command(0xB0 | page);  // select page
        write_spi_command(0x00);         // lower column
        write_spi_command(0x10);         // upper column

        write_spi_data(zeros, 128);      // send 128 zero bytes
    }
}