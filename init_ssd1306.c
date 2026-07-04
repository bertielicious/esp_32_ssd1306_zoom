#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "write_spi_command.h"
void init_ssd1306(void)
{
    // Hardware reset (already configured in your code)
    gpio_set_level(18, 0);
    vTaskDelay(pdMS_TO_TICKS(10));
    gpio_set_level(18, 1);

    // --- Fundamental Commands ---
    write_spi_command(0xAE); // Display OFF

    write_spi_command(0xD5); // Set display clock divide ratio
    write_spi_command(0x80); // Suggested value

    write_spi_command(0xA8); // Set multiplex ratio
    write_spi_command(0x3F); // 0x3F = 63 (for 128x64)

    write_spi_command(0xD3); // Set display offset
    write_spi_command(0x00); // No offset

    write_spi_command(0x40); // Set display start line = 0

    // --- Charge Pump ---
    write_spi_command(0x8D); // Charge pump
    write_spi_command(0x14); // Enable charge pump (internal)

    // --- Memory Addressing ---
    write_spi_command(0x20); // Set memory addressing mode
    write_spi_command(0x00); // Horizontal addressing mode

    // --- Segment Remap / COM Scan ---
    write_spi_command(0xA1); // Segment remap (mirror horizontally)
    write_spi_command(0xC8); // COM scan direction (remap vertically)

    // --- COM Pins ---
    write_spi_command(0xDA); // Set COM pins hardware configuration
    write_spi_command(0x12); // Alternative COM pin config, enable left/right remap

    // --- Contrast ---
    write_spi_command(0x81); // Set contrast
    write_spi_command(0x20); // Mid-level contrast

    // --- Pre-charge ---
    write_spi_command(0xD9); // Set pre-charge period
    write_spi_command(0xF1); // Recommended

    // --- VCOMH ---
    write_spi_command(0xDB); // Set VCOMH deselect level
    write_spi_command(0x40); // Default

    // --- Display Mode ---
    write_spi_command(0xA4); // Resume to RAM content
    write_spi_command(0xA6); // Normal display (not inverted)

    // --- Turn ON ---
    write_spi_command(0xAF); // Display ON
}