/*
** EPITECH PROJECT, 2022
** Pepito library
** File description:
** run_turbine
*/

#include <stdio.h>
#include "../../include/libpepito.h"


static void loop_while(int rotations)
{
    unsigned int i = 0;

    while (i != (unsigned int)rotations) {
        if (i > 15) {
            printf("{ERR0R TURB1NE CAN'T ST0P}\n");
        }
        printf("Turbine is running... %d/%d\n", i + 1, rotations);
        sleep(rand() % 3 + 1);
        i++;
    }
}

void run_turbine(void)
{
    char input[128];
    int rotations = 0;

    printf("Enter the number of rotation ");
    printf("that the turbine will do (between 0 and 15): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    rotations = atoi(input);
    if (rotations <= 0) {
        printf("Invalid number.\n");
        return;
    }
    if (rotations != 0 && rotations > 15) {
        printf("Invalid number of rotations.\n");
        return;
    }
    loop_while(rotations);
    printf("Turbine has stopped.\n");
}
