#include "ssd1306_send_zoomed.h"
#include "set_page_addr_mode.h"
#include "write_spi_command.h"
#include "set_col_addr.h"
#include "write_spi_data.h"
void ssd1306_send_zoomed(const uint8_t *pages, int zoom)
{
    int out = 8 * zoom;   // width of zoomed bitmap

    // SSD1306 uses page addressing mode
   // set_page_addr_mode(0x20, 0x02);   // 0x20 = memory mode, 0x02 = page addressing

    for (int page = 0; page < zoom; page++)
    {
        // Set page address (0xB0 | page)
        write_spi_command(0xB0 | page);

        // Set column address to 0
        set_col_addr(0);

        // Send one full page of bytes
        write_spi_data(&pages[page * out], out);
    }
}
