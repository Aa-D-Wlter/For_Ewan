/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** activate_emergency_protocols
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "unit_test.h"

Test(activate_emergency_protocols, not_mdp)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("\n");
    activate_emergency_protocols(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strcmp(res, "Enter emergency password: No password entered, emergency protocols not activated.\n") == 0, "res error ==> %s", res);
    free(res);
}

Test(activate_emergency_protocols, is_not_admin_check)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("Peter126\n");
    activate_emergency_protocols(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strcmp(res, "Enter emergency password: ") == 0, "res error ==> %s", res);
    free(res);
}

Test(activate_emergency_protocols, is_admin_check)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("admin123\n");
    activate_emergency_protocols(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strcmp(res, "Enter emergency password: {Emergency protocols activated, you are now admin !}\n") == 0, "res error ==> %s", res);
    free(res);
}