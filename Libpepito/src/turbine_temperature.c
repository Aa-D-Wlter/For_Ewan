/*
** EPITECH PROJECT, 2024
** Pepito library
** File description:
** turbine_temperature
*/

#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool check_error(long long int degrees)
{
    if (degrees >= INT_MAX || degrees <= INT_MIN) {
        printf("Limit temperature\n");
        return false;
    }
    return true;
}

void turbine_temperature(void)
{
    char input[128];
    long long int degrees = 0;

    printf("Enter the number of degrees ");
    printf("you want to increase or decrease the turbine temperature : ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    degrees = strtoll(input, NULL, 10);
    if (check_error(degrees) == false)
        return;
    printf("Turbine temperature is %d degrees.\n", 20);
    if (degrees < 0) {
        printf("Turbine temperature is decreasing : %lld\n", (20 + degrees));
        return;
    } else if (degrees > 0) {
        printf("Turbine temperature is increasing : %lld\n", (20 + degrees));
        return;
    }
}
