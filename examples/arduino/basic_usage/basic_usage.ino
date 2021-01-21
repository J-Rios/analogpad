/**************************************************************************************************/
// File: basic_usage.ino
// Description: ANALOGPAD library basic usage example
// Date: 06 jan. 2021
// Version: 1.0.0
/**************************************************************************************************/

/* Libraries */

// Device Framework libraries
#include <Arduino.h>

// Custom libraries
#include <analogpad.h>

/**************************************************************************************************/

/* Defines, Macros, Constants and Types */

// I/O pins defines
#define IO_I_APAD_BTN 10
#define IO_ADC_APAD_X A0
#define IO_ADC_APAD_Y A1

// Serial Speed
#define SERIAL_BAUDS 115200

/*****************************************************************************/

/* Global Elements */

// Analog Pad
ANALOGPAD ANALOG_PAD(IO_ADC_APAD_X, IO_ADC_APAD_Y, IO_I_APAD_BTN);

/**************************************************************************************************/

/* Setup & Loop */

void setup()
{
    Serial.begin(SERIAL_BAUDS);
    ANALOG_PAD.init();
}

void loop()
{
    uint16_t pad_x = 0;
    uint16_t pad_y = 0;
    bool pad_pressed = false;
    
    pad_x = ANALOG_PAD.axis_x();
    pad_y = ANALOG_PAD.axis_y();
    pad_pressed = ANALOG_PAD.btn_pressed();

    Serial.print("Pad X: "); Serial.println(pad_x);
    Serial.print("Pad Y: "); Serial.println(pad_y);
    if(pad_pressed)
        Serial.println("Pad Button: Pressed");
    else
        Serial.println("Pad Button: Not Pressed");
    Serial.println();

    delay(100);
}
