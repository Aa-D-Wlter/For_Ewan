/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** redirect_flux.c
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <sys/stat.h>


#include "pipeto.h"

void send_input_to_file(char const *file_name, char const *input)
{
    FILE *file = NULL;

    cr_assert(file_name != NULL);
    file = fopen(file_name, "w+");
    cr_assert(file != NULL, "file name = %s", file_name);
    fprintf(file, "%s", input);
    fclose(file);
}

char *get_output_file(char const *file_name)
{
    struct stat info = {0};
    char *output = NULL;
    FILE *file = NULL;

    cr_assert(file_name != NULL);
    if (lstat(file_name, &info) == -1)
        return NULL;
    output = calloc(info.st_size, sizeof(char));
    cr_assert(output != NULL);
    file = fopen(file_name, "w+");
    cr_assert(file != NULL);
    fprintf(file, "%s", output);
    fclose(file);
    return output;
}