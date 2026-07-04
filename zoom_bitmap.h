#ifndef ZOOM_BITMAP_H
#define ZOOM_BITMAP_H
#include <stdint.h>
void zoom_bitmap(const uint8_t src[8][8], uint8_t *fb, int zoom);
#endif