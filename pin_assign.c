#include "constants.h"
void pin_assign(display_pins_t *p)
{
    p->sck  = 19;
    p->mosi = 23;
    p->res  = 18;
    p->dc   = 21;
    p->cs   = 22;
}