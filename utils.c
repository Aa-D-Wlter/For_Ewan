/*
** EPITECH PROJECT, 2025
** ref-G-SEC-210-project
** File description:
** load_config
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <unistd.h>
#include "ansi_colors.h"

void write_color(int fd,
    const char *color, const char *str)
{
    if (fd < 0 || !color || !str)
        return;
    dprintf(fd, "%s%s%s", color, str, CRESET);
}

static void execute_line(char line[], FILE *rc_file)
{
    char cmd[1100];

    while (fgets(line, sizeof(line), rc_file)) {
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }
        line[strcspn(line, "\n")] = '\0';
        if (strncmp(line, "exec ", 5) == 0) {
            snprintf(cmd, sizeof(cmd), "%s", line + 5);
            system(cmd);
        } else {
            printf("Pipeto command: ");
            printf(line);
            printf("\n");
        }
    }
}

void load_pipetorc(void)
{
    FILE *rc_file;
    char line[1024];
    char home_rc[1024];
    char *home = NULL;

    rc_file = fopen(".pipetorc", "r");
    if (!rc_file) {
        home = getenv("HOME");
        if (home) {
            snprintf(home_rc, sizeof(home_rc), "%s/.pipetorc", home);
            rc_file = fopen(home_rc, "r");
        }
    }
    if (!rc_file) {
        return;
    }
    execute_line(line, rc_file);
    fclose(rc_file);
}
