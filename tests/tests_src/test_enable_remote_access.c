/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** enable_remote_access
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "unit_test.h"

Test(enable_remote_access, message_enable_remote_access)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    redirect_the_output(&or_stdout, &my_sdout);
    enable_remote_access(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Initializing remote access procedure...\n\n") != NULL, "res error ==> %s", res);
    free(res);
}