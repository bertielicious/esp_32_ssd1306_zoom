#include "set_page_addr_mode.h"
#include "write_spi_command.h"
void set_page_addr_mode(uint8_t mem_addr_mode, uint8_t page_addr_mode)
{
    write_spi_command(mem_addr_mode);//set memory addressing mode
    write_spi_command(page_addr_mode);//page addressing mode
}