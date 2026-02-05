/*

Ali Baba's Torch

In the folk tale "Ali Baba and the Forty Thieves", a poor woodcutter, Ali Baba, overhears the thieves' captain 
use the words "Open Sesame" to open the mouth of a rock-cut cave where they store their treasure.

Fash an LED on a GPIO pin in a funky way to open stuff.

*/

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"              // config
#include "board.h"					// board to module pin name mapping

#include "freertos/FreeRTOS.h"      // include FreeRTOS.h must appear in source files before include task.h .   
#include "freertos/task.h"          //      vTaskDelay() // portTISK_PERIOD_MS
#include "esp_chip_info.h"          // chip_info stuff
#include "esp_flash.h"              // flash_size stuff
#include "esp_system.h"             // misc system API's incl esp_get_minimum_free_heap_size()

#include "driver/gpio.h"            // GPIO peripheral
#include "esp_log.h"                // Log to the serial port



#define                 BLINK_GPIO    PIN_IO4       // which pin is the LED connected to?
#define                 BLINK_PERIOD  1000          // blink period in ms

static const    char*   TAG         = "example";    // what to tag the log comments with

static          uint8_t s_led_state = 0;            // current led state on|off



static void blink_led (void)
{
    /* Set the GPIO level according to the state (LOW or HIGH)*/
    gpio_set_level(BLINK_GPIO, s_led_state);
}



static void configure_led (void)
{
    ESP_LOGI(TAG, "Example configured to blink GPIO LED!");     // Log the fact that we have configured the pin
                                                                // ...before we have configured the pin
    gpio_reset_pin(BLINK_GPIO);                                 // reset the pin to a known configuration
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);           // Set the pin as a push/pull output
    printf("Configuration is now complete\n");
}



void app_main(void)
{

    /* Configure the peripheral */
    configure_led();

    while (1) {
        ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");       // Log what we are about to do
        blink_led();                                                                    // switch the  led to the current state
        s_led_state = !s_led_state;                                                     // Toggle the LED state
        vTaskDelay(BLINK_PERIOD / portTICK_PERIOD_MS);                                  // wait the desired amount of time
    }
}
