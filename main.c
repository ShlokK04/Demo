#include <stdio.h>

#include "temperature.h"

int main(void)
{
    const double samples[] = {0.0, 20.0, 37.0, 100.0};

    printf("%8s %10s\n", "Celsius", "Fahrenheit");
    for (size_t i = 0; i < sizeof samples / sizeof samples[0]; i++) {
        printf("%8.1f %10.1f\n", samples[i], celsius_to_fahrenheit(samples[i]));
    }

    return 0;
}
