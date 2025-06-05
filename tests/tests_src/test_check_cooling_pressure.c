/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** trigger_emergency_shutdown
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "unit_test.h"

Test(check_cooling_pressure, CHECK_IF_SENSITIVE_DATA_EXPOSED)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    redirect_the_output(&or_stdout, &my_sdout);
    check_cooling_pressure(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "{Sensitive Data}") == NULL, "res error ==> %s", res);
    free(res);
}
