/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** load_fuel_rods
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "unit_test.h"

Test(load_fuel_rods, is_number_between_max_min)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("10\n");
    load_fuel_rods(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Fuel rod 10 loaded.\n") != NULL, "res error ==> %s", res);
    free(res);
}

Test(load_fuel_rods, is_not_number)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("aaron\n");
    load_fuel_rods(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "error in input\n") != NULL, "res error ==> %s", res);
    free(res);
}

Test(load_fuel_rods, case_superior_to_fuel_rods)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("20\n");
    load_fuel_rods(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Too many fuel rods") != NULL, "res error ==> %s", res);
    free(res);
}

Test(load_fuel_rods, is_admin)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = true;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("10\n");
    load_fuel_rods(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Secret Key: {The secret stone is here !}\n") != NULL, "res error ==> %s", res);
    free(res);
}