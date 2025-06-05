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

Test(trigger_emergency_shutdown, check_is_admin_not_valid_step_two)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = true;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("3912\n");
    trigger_emergency_shutdown(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strcmp(res, "STEP 1: GOOD\nPlease enter the second password: ") == 0, "res error ==> %s", res);
    free(res);
}

Test(trigger_emergency_shutdown, check_is_admin_valid)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = true;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("3939a257017821a\n");
    trigger_emergency_shutdown(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strcmp(res, "{SHUTDOWN}\n") == 0, "res error ==> %s", res);
    free(res);
}


Test(trigger_emergency_shutdown, check_is_admin_not_valid)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    trigger_emergency_shutdown(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strcmp(res, "You are not authorized to trigger an emergency shutdown.\n") == 0, "res error ==> %s", res);
    free(res);
}