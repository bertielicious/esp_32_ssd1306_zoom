#include "zoom_bitmap.h"
#include <string.h>
void zoom_bitmap(const uint8_t src[8][8], uint8_t *fb, int zoom)
{
int out = 8 * zoom;

    memset(fb, 0, out * out);

    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            uint8_t pixel = src[y][x];

            for (int dy = 0; dy < zoom; dy++)
            {
                for (int dx = 0; dx < zoom; dx++)
                {
                    fb[(y * zoom + dy) * out + (x * zoom + dx)] = pixel;
                }
            }
        }
    }
}