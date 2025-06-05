/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** load_pipetorc
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "utils.h"
#include "unit_test.h"

Test(load_pipetorc, check_command_is_prohibit)
{
    const char *filename = ".pipetorc";
    FILE *f = fopen(filename, "w+");
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    cr_assert_not_null(f);
    fprintf(f, "rm\n");
    fflush(f);
    redirect_the_output(&or_stdout, &my_sdout);
    load_pipetorc();
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    for (size_t i = 0; not_accessible_command[i] != NULL; i++) {
        cr_assert(strcmp(res, not_accessible_command[i]), "Unexpected forbidden command: %s", not_accessible_command[i]);
    }
    free(res);
    fclose(f);
    remove(filename);
}
