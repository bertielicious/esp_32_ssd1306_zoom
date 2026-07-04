#include "fb_to_ssd1306_pages.h"
void fb_to_ssd1306_pages(const uint8_t *fb, uint8_t *pages, int zoom)
{
    int out = 8 * zoom;

    for (int page = 0; page < zoom; page++)
    {
        for (int col = 0; col < out; col++)
        {
            uint8_t b = 0;

            for (int bit = 0; bit < 8; bit++)
            {
                int row = page * 8 + bit;
                int idx = row * out + col;

                if (fb[idx])
                    b |= (1 << bit);
            }

            pages[page * out + col] = b;
        }
    }
}
