#include "set_page_start_addr.h"
#include "write_spi_command.h"
void set_page_start_addr(uint8_t page)
{
    write_spi_command(0xb0|page);
}