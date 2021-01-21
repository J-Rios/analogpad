/**
 * @file    analogpad.h
 * @author  Jose Miguel Rios Rubio <jrios.github@gmail.com>
 * @date    21-01-2021
 * @version 1.0.0
 *
 * @section DESCRIPTION
 *
 * ANALOGPAD library basic usage example.
 *
 * @section LICENSE
 *
 * Copyright (c) 2020 Jose Miguel Rios Rubio. All right reserved.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

/*****************************************************************************/

/* Libraries */

// Device Framework libraries
#include <Arduino.h>

// Custom libraries
#include <analogpad.h>

/*****************************************************************************/

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

/*****************************************************************************/

/* Setup & Loop */

void setup()
{
    Serial.begin(SERIAL_BAUDS);
    ANALOG_PAD.setup();
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
