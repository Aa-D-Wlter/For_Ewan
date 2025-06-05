/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** init_reactor
*/

#include <stdio.h>
#include <unistd.h>

#include "pipeto.h"

void init_reactor(UNUSED bool *is_admin, UNUSED history_t *history)
{
    print_message("Start of the reactor initialized\n", 1);
    print_message("Reactor status: OK\n", 2);
    print_message("Reactor core temperature: 25°C\n", 3);
    print_message("Reactor coolant flow rate: 100L/min\n", 2);
    print_message("Reactor radiation levels: Safe\n", 3);
    print_message("Reactor power output: 50MW\n", 1);
    print_message("Reactor diagnostic: All systems operational\n", 2);
    printf("Reactor initialization complete.\n");
}
