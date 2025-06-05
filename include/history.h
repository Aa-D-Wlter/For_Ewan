/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** header for history
*/

#ifndef HISTORY_H
    #define HISTORY_H
    #define MAX_COMMAND_LENGTH 256

    #include <stdbool.h>

typedef struct history_s {
    char **array;
    int history_count;
    int history_size;
}history_t;

void history_init(history_t *history);
void history_add(const char *command, history_t *history);
void history_clear(history_t *history);
void history_free(history_t *history);
void history_show(history_t *history);
char *history_get(int index, history_t *history);
int history_count_get(history_t *history);
void process_history(char *line,
    history_t *history, bool *is_admin, bool *command_found);

#endif /* HISTORY_H */
