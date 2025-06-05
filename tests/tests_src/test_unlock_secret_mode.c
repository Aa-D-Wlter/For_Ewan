/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** unlock_secret_mode
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "unit_test.h"

Test(unlock_secret_mode, check_is_admin_valid)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = true;

    redirect_the_output(&or_stdout, &my_sdout);
    unlock_secret_mode(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strcmp(res, "Secret mode unlocked! Welcome, admin.\n{ADMIN4242}\n") == 0, "res error ==> %s", res);
    free(res);
}

Test(unlock_secret_mode, check_is_admin_not_valid)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    unlock_secret_mode(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strcmp(res, "Access denied. You do not have the required privileges.\n") == 0, "res error ==> %s", res);
    free(res);
}