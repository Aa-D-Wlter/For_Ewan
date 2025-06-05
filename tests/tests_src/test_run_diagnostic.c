/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** run_diagnostic
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "unit_test.h"

Test(run_diagnostic, mode_diagnostic_normal)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("normal\n");
    run_diagnostic(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Error: Diagnostic data is unavailable (NULL pointer).\n") != NULL, "res error ==> %s", res);
    free(res);
}

Test(run_diagnostic, mode_diagnostic_debug)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = true;


    redirect_the_output(&or_stdout, &my_sdout);
    send_input("debug\n");
    run_diagnostic(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "{SECRET DIAGNOSTIC KEY}\n") != NULL, "res error ==> %s", res);
    free(res);
}

Test(run_diagnostic, mode_diagnostic_advanced)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = true;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("advanced\n");
    run_diagnostic(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Code 383\n") != NULL, "res error ==> %s", res);
    free(res);
}
