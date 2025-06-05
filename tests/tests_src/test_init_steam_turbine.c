/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** init_steam_turbine
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "libpepito.h"
#include "unit_test.h"

Test(init_steam_turbine, message_init_steam_turbine)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    redirect_the_output(&or_stdout, &my_sdout);
    init_steam_turbine();
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    printf("Ici == %s\n", res);
    cr_assert(strstr(res, "Reactor initialization complete.\n") != NULL, "res error ==> %s", res);
    free(res);
}