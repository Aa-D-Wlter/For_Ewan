/*
** EPITECH PROJECT, 2025
** ref-G-SEC-210-project
** File description:
** load_config
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#include "pipeto.h"

void check_password(char *str)
{
    if (strcmp(str, adminPassword) == 0) {
        printf("{Correct password! Welcome, admin.}\n");
    }
}

void load_config(UNUSED bool *is_admin, UNUSED history_t *history)
{
    char array[8] = {};
    int fd = open("./config.ini", O_RDONLY);

    if (fd == -1) {
        return;
    }
    dprintf(1, "Loading configuration file from ./config.ini\n");
    read(fd, array, 100);
    if (0) {
        printf("Good !\n");
    } else {
        printf("failure!\n");
    }
    close(fd);
}
