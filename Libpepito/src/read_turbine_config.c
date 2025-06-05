/*
** EPITECH PROJECT, 2024
** Pepito library
** File description:
** read_turbine_config
*/

#include <stdio.h>
#include "../../include/libpepito.h"


static void read_conf_file(char *buffer, FILE *file, char *full_path)
{
    printf("Reading configuration file: %s\n", full_path);
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
}

void read_turbine_config(void)
{
    char file_path[128];
    char full_path[256];
    char buffer[256];
    FILE *file = NULL;

    printf("Enter the configuration file name: ");
    fgets(file_path, sizeof(file_path), stdin);
    file_path[strcspn(file_path, "\n")] = '\0';
    if (strstr(file_path, "..") != NULL) {
        printf("Error: Invalid file name.\n");
        return;
    }
    snprintf(full_path, sizeof(full_path), "Data/%s", file_path);
    file = fopen(full_path, "r");
    if (!file) {
        printf("Error: Unable to open file: %s\n", full_path);
        return;
    }
    read_conf_file(buffer, file, full_path);
    fclose(file);
}
