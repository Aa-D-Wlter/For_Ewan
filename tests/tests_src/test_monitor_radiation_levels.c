/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** monitor_radiation_levels
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "unit_test.h"

Test(monitor_radiation_levels, check_is_not_buffer_overflow)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("1000\n");
    monitor_radiation_levels(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strcmp(res, "Enter radiation levels: Radiation Levels: 1000\n\nFunction Pointer: (nil)\n") == 0, "res error ==> %s", res);
    free(res);
}
