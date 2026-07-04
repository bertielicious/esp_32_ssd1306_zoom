#ifndef FB_TO_SSD1306_PAGES_H
#define FB_TO_SSD1306_PAGES_H
#include <stdint.h>
void fb_to_ssd1306_pages(const uint8_t *fb, uint8_t *pages, int zoom);
#endif