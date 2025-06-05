/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** check_cooling_pressure
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "pipeto.h"

static void load_data(char *data)
{
    strcpy(data, "Pressure OK");
}

static void log_pressure_status(const char *status)
{
    printf("Cooling pressure status: %s\n", status);
}

static void simulate_sensor_reading(void)
{
    printf("Simulating sensor reading...\n");
    sleep(1);
    printf("Sensor reading complete.\n");
}

void check_cooling_pressure(UNUSED bool *is_admin, UNUSED history_t *history)
{
    char *data = (char *)malloc(16);
    char temp_buffer[32];
    char sensitive_info[32] = "{Sensitive Data}";

    load_data(data);
    print_message("Cooling pressure check in progress...\n", 2);
    simulate_sensor_reading();
    print_message("Checking cooling pressure...\n", 1);
    log_pressure_status(data);
    free(data);
    sleep(3);
    if (strcmp(data, "Pressure OK")) {
        printf("Sensitive Info: %s\n", sensitive_info);
    }
    snprintf(temp_buffer, sizeof(temp_buffer),
    "Temporary data: %d", rand() % 100);
    printf("Temporary buffer: %s\n", temp_buffer);
    simulate_sensor_reading();
    printf("Cooling pressure check complete.\n");
}
