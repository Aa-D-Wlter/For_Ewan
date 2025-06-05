/*
** EPITECH PROJECT, 2025
** Pipeto
** File description:
** history.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "history.h"
#include "macro_pipeto.h"


void history_add(const char *command, history_t *history)
{
    FILE *file = NULL;

    if (!command || strlen(command) == 0 || (history->history_count > 0 &&
    strcmp(history->array[history->history_count - 1], command) == 0))
        return;
    if (history->history_count == history->history_size) {
        free(history->array[0]);
        for (int i = 0; i < history->history_count - 1; i++)
            history->array[i] = history->array[i + 1];
        history->history_count--;
    }
    history->array[history->history_count] = strdup(command);
    if (history->array[history->history_count])
        history->history_count++;
    file = fopen(HISTORY_FILE, "w");
    if (file) {
        for (int i = 0; i < history->history_count; i++)
            fprintf(file, "%s\n", history->array[i]);
        fclose(file);
    }
}

void history_clear(history_t *history)
{
    FILE *file = NULL;

    for (int i = 0; i < history->history_count; i++)
        free(history->array[i]);
    history->history_count = 0;
    file = fopen(HISTORY_FILE, "w");
    if (file)
        fclose(file);
}

void history_free(history_t *history)
{
    for (int i = 0; i < history->history_count - 1; i++)
        free(history->array[i]);
    history->history_count = 0;
    history->history_size = 0;
    history = NULL;
}

char *history_get(int index, history_t *history)
{
    if (index < 0 || index >= history->history_count)
        return NULL;
    return history->array[index];
}

int history_count_get(history_t *history)
{
    return history->history_count;
}
