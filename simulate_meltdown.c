/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** simulate_meltdown
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#include "history.h"
#include "macro_pipeto.h"

static void check_random_number_superior(int random_number,
    char reactor_status[])
{
    if (random_number < 50) {
        printf("Alert: Reactor core temperature stable.\n");
        strcpy(reactor_status, "Reactor Stable");
    } else {
        printf("Reactor core temperature normal.\n");
        strcpy(reactor_status, "Reactor Normal");
    }
}

static void check_random_number(int random_number,
    char reactor_status[], char secret_code[])
{
    if (random_number < 10) {
        printf("Meltdown simulated! Reactor core is overheating.\n");
        strcpy(reactor_status, "Reactor Overheating");
        if (random_number < 5) {
            printf("Critical Error: Secret Code Leaked: %s\n", secret_code);
            return;
        }
    } else if (random_number < 20) {
        printf("Warning: Reactor core temperature rising.\n");
        strcpy(reactor_status, "Reactor Warning");
        return;
    }
    check_random_number_superior(random_number, reactor_status);
    printf("Reactor core temperature: %d\n", random_number);
    printf("Reactor core status: %s\n", reactor_status);
}

void simulate_meltdown(UNUSED bool *is_admin, UNUSED history_t *history)
{
    char reactor_status[32] = "Reactor Stable";
    int random_number = rand() % 100;
    char secret_code[16] = "{MELTDOWN1234}";

    printf("Generated random number: %d\n", random_number);
    check_random_number(random_number, reactor_status, secret_code);
}
