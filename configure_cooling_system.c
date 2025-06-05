/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** configure_cooling_system
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "history.h"
#include "macro_pipeto.h"

static void execute_cooling_system(char command[])
{
    int result = 0;

    result = system(command);
    if (result == 0) {
        printf("Configuration applied successfully.\n");
        return;
    }
    printf("Failed to apply configuration. Command returned: %d\n", result);
}

void configure_cooling_system(UNUSED bool *is_admin, UNUSED history_t *history)
{
    char *config_file = "Data/cooling_config.txt";
    char buffer[64];
    FILE *file = fopen(config_file, "r");

    if (!file) {
        printf("Error: Unable to open configuration file: %s\n", config_file);
        return;
    }
    printf("Reading configuration file: %s\n", config_file);
    fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[sizeof(buffer) - 1] = '\0';
    fclose(file);
    printf("Applying configuration: %s\n", buffer);
    execute_cooling_system(buffer);
}
