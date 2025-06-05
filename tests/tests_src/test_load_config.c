/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** load_config
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pipeto.h"
#include "unit_test.h"

Test(load_config, check_printf)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("20\n");
    load_config(NULL, NULL);
    res = get_the_ouput(my_sdout);
    cr_assert_not_null(res);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strcmp(res, "failure!\n") == 0, "res error ==> %s", res);
    free(res);
}

/*Test(load_config, check_when_no_file)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    bool is_admin = true;

    cr_assert(chdir("./tests") != -1);
    remove("config.ini");
    redirect_the_output(&or_stdout, &my_sdout);
    load_config(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "File is not exist.\n") != NULL, "res error ==> %s", res);
    //cr_assert(strcmp(res, "\0") == 0, "res error ==> %s", res);
    free(res);
}*/

Test(load_config, check_normal_case)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    cr_assert(chdir("./tests") != -1);
    remove("config.ini");
    redirect_the_output(&or_stdout, &my_sdout);
    send_input_to_file("./config.ini", "AAA");
    load_config(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    remove("config.ini");
    cr_assert(strcmp(res, "failure!\n") == 0, "res error ==> %s", res);
    free(res);
}

Test(load_config, check_try_buffer_overflow)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    cr_assert(chdir("./tests") != -1);
    redirect_the_output(&or_stdout, &my_sdout);
    send_input_to_file("./config.ini", "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    load_config(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    remove("config.ini");
    cr_assert(strcmp(res, "failure!\n") == 0, "res error ==> %s", res);
    free(res);
}
