/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** set_reactor_power
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "unit_test.h"

Test(set_reactor_power, normal_number)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("10\n");
    set_reactor_power(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Reactor power set to: 1010\n") != NULL, "res error ==> %s", res);
    free(res);
}

Test(set_reactor_power, limit_max)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("211111111111111111111\n");
    set_reactor_power(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Limit Max\n") != NULL, "res error ==> %s", res);
    free(res);
}

Test(set_reactor_power, not_number)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("aiden\n");
    set_reactor_power(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Not number\n") != NULL, "res error ==> %s", res);
    free(res);
}

/*Test(set_reactor_power, data_secret)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("2147483647\n");
    set_reactor_power(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    printf("Ici == %s\n", res);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "{12EXPLOSION34}\n") != NULL, "res error ==> %s", res);
    free(res);
}*/

Test(set_reactor_power, number_negatif)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = false;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("-10000\n");
    set_reactor_power(&is_admin, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Reactor core meltdown imminent!\n") != NULL, "res error ==> %s", res);
    free(res);
}
