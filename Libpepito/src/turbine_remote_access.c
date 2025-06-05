/*
** EPITECH PROJECT, 2024
** Pepito library
** File description:
** turbine_remote_access
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "../../include/pipeto.h"

void turbine_remote_access(void)
{
    char temp_file[] = "Data/remote_accessXXXXXX";
    int fd = mkstemp(temp_file);
    char credentials[] = "{ACCESS_GRANTED}";

    if (fd == -1) {
        printf("Error: Unable to create temporary file.\n");
        return;
    }
    printf("Temporary file created: %s\n", temp_file);
    write_in_file(credentials, fd);
    close(fd);
    printf("Enabling remote access...\n");
    sleep(5);
    fd = open(temp_file, O_RDONLY);
    if (fd == -1) {
        printf("Error: Temporary file was tampered with or deleted.\n");
        return;
    }
    unlink(temp_file);
}
