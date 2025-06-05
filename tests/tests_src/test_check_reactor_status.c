/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** check_reactor_status
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "unit_test.h"


Test(check_reactor_status, is_crypted)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    int mdp_crypted = 0;
    char *mdp_str = NULL;

    redirect_the_output(&or_stdout, &my_sdout);
    check_reactor_status(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    mdp_crypted = hashed_password("ReactorStatusOK");
    mdp_str = malloc(sizeof(char) * (length_number(mdp_crypted) + 1));
    sprintf(mdp_str, "%d", mdp_crypted);
    cr_assert(strstr(res, mdp_str) != NULL, "res error ==> %s", res);
    free(res);
    free(mdp_str);
}
