/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** my_console
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/types.h>

#include "pipeto.h"
#include "ansi_colors.h"
#include "utils.h"
#include "history.h"

void print_message(char const *buffer, int nb_sleep)
{
    printf("%s", buffer);
    sleep(nb_sleep);
}

void check_pepito_lib(char *input)
{
    void *dlh = dlopen("libpepito.so", RTLD_LAZY);
    void (*fnc)(void);

    if (dlh == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    fnc = dlsym(dlh, input);
    if (fnc == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    fnc();
}

void process_command(char *line,
    history_t *history, bool *is_admin)
{
    bool command_found = false;

    for (int i = 0; i < COMMAND_COUNT; i++) {
        if (strcmp(line, command_strings[i]) == 0) {
            check_command[i].execute(is_admin, history);
            command_found = true;
            break;
        }
    }
    for (int i = 0; i < COMMAND_COUNT_LIB; i++) {
        if (strcmp(line, command_strings_lib[i]) == 0) {
            check_pepito_lib(line);
            command_found = true;
            break;
        }
    }
    process_history(line, history, is_admin, &command_found);
    if (!command_found && strlen(line) > 0) {
        printf("Unknown command: %s\n", line);
    }
}

static void init_console(history_t *history)
{
    history_init(history);
    load_pipetorc();
}

void loop_console(history_t *history, bool *is_admin)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    while (1) {
        write_color(1, BHRED, "pipeto");
        write(1, "> ", 3);
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;
        if (line[0] == '\n')
            continue;
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) > 0)
            history_add(line, history);
        process_command(line, history, is_admin);
    }
    history_free(history);
    free(line);
}

int my_console(void)
{
    bool is_admin = false;
    history_t history = {0};

    init_console(&history);
    loop_console(&history, &is_admin);
    return 0;
}
