# AnalogPad

A C++ library to ease Analog Pad usage with HAL emphasis to be used in different kind of devices and frameworks.

## Supported Devices & Frameworks

Currently, just Arduino devices are compatible, however is simply to add support to other devices and frameworks.

## Adding new Device Support

To add a new device or framework support to library, yo just need to write the low level functionalities to control and interface with the Analog Pad through the **hal_*()** private methods (hal_gpio_as_digital_input(), hal_gpio_as_adc(), hal_gpio_read_digital(), hal_gpio_read_adc(), etc):

```cpp

// ...

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

// ...

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

// ...

```

## Donation

[![paypal](https://www.paypal.com/en_US/i/btn/btn_donateCC_LG.gif)](https://paypal.me/josrios)

Do you like this project?

Please, considere making a donation.
