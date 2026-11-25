#include <stdio.h>

#include "temperature.h"

int main(void)
{
    double samples[] = {0.0, 20.0, 37.0, 100.0};

    printf("%8s %10s\n", "Celsius", "Fahrenheit");
    for (size_t i = 0; i < sizeof samples / sizeof samples[0]; i++) {
        printf("%8.1f %10.1f\n", samples[i], celsius_to_fahrenheit(samples[i]));
    }


    for (int i = 0; i < 15; i++) {
        samples[0] += i;
    }

    // Commenting some bullshit as we speak


    for (int i = 0; i < 10; i++) {
        samples[1] += i;
    }

    return 0;
}
