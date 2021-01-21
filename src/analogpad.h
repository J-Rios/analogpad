
/**
 * @file    analogpad.h
 * @author  Jose Miguel Rios Rubio <jrios.github@gmail.com>
 * @date    06-01-2021
 * @version 1.0.0
 *
 * @section DESCRIPTION
 *
 * ANALOGPAD ease control class.
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

/* Include Guard */

#ifndef ANALOGPAD_H_
#define ANALOGPAD_H_

/*****************************************************************************/

/* Libraries */

// Standard C/C++ libraries
#include <stdint.h>
#include <stdbool.h>

/*****************************************************************************/

class ANALOGPAD
{
    public:
        ANALOGPAD(const uint32_t pin_x, const uint32_t pin_y,
                const uint32_t pin_btn);

        void setup(void);

        uint16_t axis_x(void);
        uint16_t axis_y(void);
        bool btn_pressed(void);

    private:
        uint32_t pin_x, pin_y, pin_btn;
        uint8_t gpios_initialized;

        bool gpios_are_not_initialized(void);

        void hal_gpio_as_digital_input(const uint32_t gpio);
        void hal_gpio_as_adc(const uint32_t gpio);
        uint8_t hal_gpio_read_digital(const uint32_t gpio);
        uint16_t hal_gpio_read_adc(const uint32_t gpio);
};

/*****************************************************************************/

#endif /* ANALOGPAD_H_ */
