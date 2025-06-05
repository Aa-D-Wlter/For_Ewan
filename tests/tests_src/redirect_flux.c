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
#include <unistd.h>

#include "pipeto.h"


void send_input(const char *input)
{
    char filename[] = "/tmp/simul_input_XXXXXX";
    int fd = mkstemp(filename);
    cr_assert(fd != -1);
    FILE *f = NULL;

    ftruncate(fileno(stdin), 0); 
    f = fdopen(fd, "w+");
    cr_assert_not_null(f);
    fprintf(f, "%s", input);
    fflush(f);
    rewind(f);
    freopen(filename, "r", stdin);
    fclose(f);
}

void redirect_the_output(FILE **or_output,  FILE **my_sdout)
{
    *or_output = stdout;
    *my_sdout = tmpfile();
    stdout = *my_sdout;
}

void restore_the_ouput(FILE **or_output,  FILE **my_sdout)
{
    stdout = *or_output;
    fclose(*my_sdout);
}

char *get_the_ouput(FILE *my_sdout)
{
    char buffer[1025] = {0};
    size_t read_bytes = 0;

    if (my_sdout == NULL)
        return NULL;

    rewind(my_sdout);
    read_bytes = fread(buffer, 1, 1024, my_sdout);
    buffer[read_bytes] = '\0';
    return strdup(buffer);
}