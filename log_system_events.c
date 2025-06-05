/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** log_system_events
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "history.h"
#include "macro_pipeto.h"

void log_system_event(UNUSED bool *is_admin, UNUSED history_t *history)
{
    char command[100];
    char input[100];
    FILE *log = fopen("Data/system.log", "a");
    char secret_key[32] = "{SECRET_LOG_12PIERRE34}";

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%99s", command);
    if (!log) {
        printf("Error: Unable to open log file 'Data/system.log'.\n");
        return;
    }
    printf("Logging event: %s\n", input);
    fprintf(log, "EVENT: %s\n", input);
    if (strstr(input, "leak")) {
        fprintf(log, "SECRET_KEY_LEAKED: %s\n", secret_key);
    }
    fclose(log);
}
