/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** load_fuel_rods
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "history.h"
#include "macro_pipeto.h"

static void check_input(int i, char secret_key[], int fuel_rods[])
{
    if (i < 10 && i > 0) {
        for (int j = 0; j < i; j++) {
            fuel_rods[j] = j + 1;
            printf("Fuel rod %d loaded.\n", fuel_rods[j]);
            sleep(1);
        }
        return;
    }
    if (strcmp(secret_key, "{The secret stone is here !}")) {
        printf("\nSensitive Data:\n");
        printf("Secret Key: %s\n", secret_key);
    }
}

void load_fuel_rods(UNUSED bool *is_admin, UNUSED history_t *history)
{
    int i = 0;
    int fuel_rods[10];
    char input[100];
    char secret_key[28] = "{The secret stone is here !}";

    printf("Loading fuel rods...\n");
    printf("Enter the number of fuel rods to load (max 10): ");
    fgets(input, 100, stdin);
    sscanf(input, "%d", &i);
    if (i > 10) {
        printf("Error: Too many fuel rods!\n");
        return;
    }
    check_input(i, secret_key, fuel_rods);
}
