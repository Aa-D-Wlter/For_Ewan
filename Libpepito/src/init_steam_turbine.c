/*
** EPITECH PROJECT, 2024
** Pepito library
** File description:
** init_steam_turbine
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

static void init_steam_turbine2(void)
{
    sleep(1);
    printf("Steam turbine rotor status: OK\n");
    sleep(1);
    printf("Steam turbine rotor current speed: 1000 r/min\n");
    sleep(1);
    printf("Reactor initialization complete.\n");
    sleep(1);
}

void init_steam_turbine(void)
{
    srand(time(NULL));
    printf("Start of the steam turbine initialized\n");
    sleep(1);
    printf("Steam turbine status: OK\n");
    sleep(2);
    printf("Steam valves status: OPEN\n");
    sleep(1);
    printf("Pressurized water tank: OK\n");
    sleep(1);
    printf("Pressurized water valves: READY\n");
    sleep(1);
    printf("Steam turbine rotor status: OK\n");
    sleep(2);
    printf("Starting steam turbine rotor...\n");
    init_steam_turbine2();
}
