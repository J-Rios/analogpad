
/**
 * @file    analogpad.cpp
 * @author  Jose Miguel Rios Rubio <jrios.github@gmail.com>
 * @date    06-01-2021
 * @version 1.0.0
 *
 * @section DESCRIPTION
 *
 * Analog Pad ease control class.
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

// Header Interface
#include "analogpad.h"

// Device/Framework Libraries
#if defined(ARDUINO)
    #include <Arduino.h>
#elif defined(ESP_IDF)
    // Unimplemented
#elif defined(SAM_ASF)
    // Unimplemented
#elif defined(__AVR__)
    // Unimplemented
#endif

/*****************************************************************************/

/* Constructor */

/**
  * @brief  Constructor, get GPIO pins numbers to be used for the Pad.
  * @param  pin_x GPIO pin number for Pad Analog Axis X.
  * @param  pin_y GPIO pin number for Pad Analog Axis Y.
  * @param  pin_btn GPIO pin number for Pad Button.
  */
ANALOGPAD::ANALOGPAD(const uint32_t pin_x, const uint32_t pin_y,
        const uint32_t pin_btn)
{
    this->pin_x = pin_x;
    this->pin_y = pin_y;
    this->pin_btn = pin_btn;
    this->gpios_initialized = 0;
}

/*****************************************************************************/

/* Public Methods */

/**
  * @brief  Initialize Analog Pad GPIOs.
  */
void ANALOGPAD::init(void)
{
    hal_gpio_as_adc(this->pin_x);
    hal_gpio_as_adc(this->pin_y);
    hal_gpio_as_digital_input(this->pin_btn);
}

/**
  * @brief  Get current value of analog pad axis X.
  * @return ADC value read from analog pad axis X.
  */
uint16_t ANALOGPAD::axis_x(void)
{
    return (hal_gpio_read_adc(this->pin_x));
}

/**
  * @brief  Get current value of analog pad axis Y.
  * @return ADC value read from analog pad axis Y.
  */
uint16_t ANALOGPAD::axis_y(void)
{
    return (hal_gpio_read_adc(this->pin_y));
}

/**
  * @brief  Check if the analog pad button is pressed.
  * @return Button press status (true or false).
  */
bool ANALOGPAD::btn_pressed(void)
{
    return (hal_gpio_read_digital(this->pin_btn) == 0);
}

/*****************************************************************************/

/* Private Methods */

/**
  * @brief  Check if needed GPIOs are initialized.
  * @return If all needed GPIOs are initialized (true or false).
  */
bool ANALOGPAD::gpios_are_not_initialized(void)
{
    return (this->gpios_initialized < 3);
}

/*****************************************************************************/

/* Specific Device/Framework HAL functions */

/**
  * @brief  Set the provided GPIO as Digital Input with internall pullup.
  * @param  gpio GPIO pin number to setup.
  */
void ANALOGPAD::hal_gpio_as_digital_input(const uint32_t gpio)
{
    #if defined(ARDUINO)
        pinMode(gpio, INPUT_PULLUP);
    #elif defined(ESP_IDF)
        // Unimplemented
    #elif defined(SAM_ASF)
        // Unimplemented
    #elif defined(__AVR__)
        // Unimplemented
    #endif

    this->gpios_initialized = this->gpios_initialized + 1;
}

/**
  * @brief  Set the provided GPIO to use the ADC.
  * @param  gpio GPIO pin number to setup.
  */
void ANALOGPAD::hal_gpio_as_adc(const uint32_t gpio)
{
    // Set LED GPIOs logic levels for this color
    #if defined(ARDUINO)
        // Nothing to be done
    #elif defined(ESP_IDF)
        // Unimplemented
    #elif defined(SAM_ASF)
        // Unimplemented
    #elif defined(__AVR__)
        // Unimplemented
    #endif

    this->gpios_initialized = this->gpios_initialized + 1;
}

/**
  * @brief  Read the digital logic level of an digital input GPIO.
  * @param  gpio GPIO pin number to read.
  * @return Digital logic level read from pin (0 or 1).
  */
uint8_t ANALOGPAD::hal_gpio_read_digital(const uint32_t gpio)
{
    // Do nothing if GPIOS has not been initialized
    if(gpios_are_not_initialized())
        return 1;

    #if defined(ARDUINO)
        return digitalRead(gpio);
    #elif defined(ESP_IDF)
        // Unimplemented
    #elif defined(SAM_ASF)
        // Unimplemented
    #elif defined(__AVR__)
        // Unimplemented
    #endif
}

/**
  * @brief  Read the analog value from the a GPIO ADC.
  * @param  gpio GPIO pin number to read.
  * @return ADC value from pin analog read (0 to ADC_MAX_VAL).
  */
uint16_t ANALOGPAD::hal_gpio_read_adc(const uint32_t gpio)
{
    // Do nothing if GPIOS has not been initialized
    if(gpios_are_not_initialized())
        return 0;

    #if defined(ARDUINO)
        return analogRead(gpio);
    #elif defined(ESP_IDF)
        // Unimplemented
    #elif defined(SAM_ASF)
        // Unimplemented
    #elif defined(__AVR__)
        // Unimplemented
    #endif
}
