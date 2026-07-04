#ifndef CONSTANTS_H
#define CONSTANTS_H
/*A header file is meant for declarations, not definitions.
A declaration tells the compiler what something is (its name and type). 
A definition tells the compiler how to make it (creating the actual storage or code).
The Main DifferencesDeclaration: Announces a name and type. It does not allocate memory. 
You can declare the same thing many times.
Definition: Allocates memory or writes out the code instructions. 
You can only define something exactly once in your entire program.
Variables
For variables, a declaration just says "this variable exists somewhere". 
A definition actually sets aside the memory to store the variable.
Declaration Example: 
extern int score;(This tells the compiler score is a whole number, but its real memory is defined somewhere else.)
Definition Example: int score; or int score = 10;(This tells the compiler score is a whole number and allocates the needed 4 bytes in memory.)*/

/*
SSD1306 pins          GPIO pins
MOSI------------------ 23
SCK------------------- 19
RES------------------- 18
DC-------------------- 21
CS-------------------- 22
*/


#include <stdint.h>
enum{LO, HI};

extern uint16_t *num;


typedef struct {
    uint8_t sck;
    uint8_t mosi;
    uint8_t cs;
    uint8_t dc;
    uint8_t res;
} display_pins_t;

typedef struct
{
    uint8_t zoomedByte0;
    uint8_t zoomedByte1;

}zoomPix_t;

extern zoomPix_t xonk;

static const uint8_t A[8] = {0x00, 0xfc, 0x12, 0x11, 0x11, 0x12, 0xfc, 0x00};
static const uint8_t zero[8] = {0x00,0x00,0x7C,0x82,0x82,0x82,0x7C,0x00};

static const uint8_t one[8] = {0x00, 0x00, 0x84,0x82,0xFF,0x80,0x80,0x00};
static const uint8_t two[8] = {0x00,0x00,0xE4,0x92,0x92,0x8C,0x00,0x00};
static const uint8_t three[8] = {0x00,0x00,0x44,0x92,0x92,0x6C,0x00,0x00};



#endif

/*
OR

static const int MOSI_PIN = 23;
static const int SCK_PIN  = 19;
static const int CS_PIN   = 22;
static const int DC_PIN   = 21;
static const int RST_PIN  = 18;
 
spi_bus_config_t buscfg = {
    .mosi_io_num = MOSI_PIN,
    .sclk_io_num = SCK_PIN,
    .miso_io_num = -1,
};
 
OR

enum DisplayPins {
    PIN_SCK  = 19,
    PIN_MOSI = 23,
    PIN_CS   = 22,
    PIN_DC   = 21,
    PIN_RST  = 18
};
*/