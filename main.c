#include <stdio.h>
#include "constants.h"
#include "constants.c"
#include "esp_log.h"
#include "pin_assign.h"
#include "config_display_gpio.h"
#include "config_dev.h"
#include "driver/gpio.h"
#include "config_spi.h"
#include "init_ssd1306.h"
#include "clear_screen.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "write_spi_command.h"
#include "write_spi_data.h"
#include "set_page_addr_mode.h"
#include "set_col_addr.h"
#include "set_page_start_addr.h"
#include "ssd1306_send_zoomed.h"
#include "zoom_bitmap.h"
#include "fb_to_ssd1306_pages.h"


// set zoom to int zoom = 4;// can set to 1, 2,3 or 4 on line 78 below

spi_device_handle_t ssd1306_handle = NULL;   // ✅ the one and only definition
static const char *TAG = "gpio num";
void app_main(void)
{
    //uint16_t number_to_display = 1967;
    //uint8_t i;// loop counter

    //assign gpio pins to each SPI pin
   display_pins_t phil; 
   display_pins_t *totnor;
   totnor = &phil;
   pin_assign(&phil); //assign SPI labels to each gpio pin

   ESP_LOGI(TAG, "MOSI = %d\n", totnor->mosi);
   ESP_LOGI(TAG, "SCK = %d\n", totnor->sck);
   ESP_LOGI(TAG, "RES = %d\n", totnor->res);
   ESP_LOGI(TAG, "DC = %d\n", totnor->dc);
   ESP_LOGI(TAG, "CS = %d\n", totnor->cs);
  
   // Your 8x8 bitmap
    uint8_t src[8][8] = {
        {0,0,0,0,1,0,0,0},
        {0,0,0,1,1,0,0,0},
        {0,0,1,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,1,1,1,1,1,0}
    }; 
    
    //config gpio pins cs, dc, res

    config_display_gpio(&phil);
    gpio_set_level(totnor->cs, 1);

    //configure spi bus
    config_spi(&phil);

    //configuration for a SPI slave device (SSD1306)that is 
    //connected to SPI2_HOST bus
    config_dev(&ssd1306_handle, &phil);

    init_ssd1306();
    vTaskDelay(1000/portTICK_PERIOD_MS );

    clear_screen();
    
    //SSD1306
    //set page addressing mode (once only function call)
    //set_page_addr_mode(0x20, 0x02);// set memory addressing mode 0x20, page addressing mode 0x02
   
    int zoom = 3;// can set to 1, 2,3 or 4
    int out  = 8 * zoom;

    uint8_t fb[32 * 32];     // zoomed framebuffer
    uint8_t pages[32 * 32];  // SSD1306 page bytes
    clear_screen();
    // Clear framebuffer
    memset(fb, 0, sizeof(fb));
   //memset(fb, 0, out * out);
   

    // 1. Zoom the bitmap
    zoom_bitmap(src, fb, zoom);

    // 2. Convert to SSD1306 page format
    fb_to_ssd1306_pages(fb, pages, zoom);

    // 3. Send to display using your SPI functions
    ssd1306_send_zoomed(pages, zoom);

    
   
    while(true)
    {
        
       
    }
    
       
}


