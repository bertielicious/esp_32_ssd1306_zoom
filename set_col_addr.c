#include "set_col_addr.h"
#include "write_spi_command.h"
void set_col_addr(uint8_t col_addr)
{
   uint8_t low_nib, hi_nib;
   low_nib = col_addr & 0x0f;// lo_nib starts from 0
   hi_nib = (((col_addr & 0xf0) >> 4) | 0x10);  //hi_nib starts from 0x10
    //hi_nib = ((col_addr & (0xf0 + 1)) >> 4);  //hi_nib starts from 0x10 this is incorrect!
   write_spi_command(low_nib);
   write_spi_command(hi_nib);
}