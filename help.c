/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** help
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "help.h"
#include "history.h"
#include "macro_pipeto.h"

void help(UNUSED bool *is_admin, UNUSED history_t *history)
{
    int command_count = sizeof(commands) / sizeof(commands[0]);

    printf("Available commands :\n");
    for (int i = 0; i < command_count; i++) {
        printf("%s", commands[i]);
    }
    printf("\n");
    printf("Configuration:\n");
    printf("- .pipetorc: Create this file in your ");
    printf("home directory or current directory\n");
    printf("  to automatically execute commands at startup.\n");
    printf("  Use 'exec <command>' to execute shell commands.\n");
    printf("\n");
}
