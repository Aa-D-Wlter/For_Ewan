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
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pipeto.h"
#include "unit_test.h"

Test(process_history, case_negatif_input)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    cr_assert(chdir("./tests") != -1);
    send_input_to_file(HISTORY_FILE, "\0");
    redirect_the_output(&or_stdout, &my_sdout);
    send_input("!-1\n");
    my_console();
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    remove(HISTORY_FILE);
    cr_assert(strstr(res, "Invalid history index") != NULL, "res error ==> %s", res);
    free(res);
}

Test(process_history, case_too_big_input)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    cr_assert(chdir("./tests") != -1);
    send_input_to_file(HISTORY_FILE, "\0");
    redirect_the_output(&or_stdout, &my_sdout);
    send_input("!10\n");
    my_console();
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    remove(HISTORY_FILE);
    cr_assert(strstr(res, "Invalid history index") != NULL, "res error ==> %s", res);
    free(res);
}

Test(show_history, display_history)
{
    char *buffer = NULL;
    history_t history = {0};
    history.history_size = MAX_HISTORY_SIZE;
    history.history_count = 0;
    history.array = malloc(sizeof(char *) * MAX_HISTORY_SIZE);
    history.array[0] = strdup("ls");
    history.history_count++;
    history.array[1] = strdup("init_steam_turbine");
    history.history_count++;
    history_count_get(&history);
    buffer = history_get(1, &history);
    show_history(NULL, &history);
    history_free(&history);
    free(buffer);
}

Test(process_history, case_n_plus_1_input)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    cr_assert(chdir("./tests") != -1);
    send_input_to_file(HISTORY_FILE, "\0");
    redirect_the_output(&or_stdout, &my_sdout);
    send_input("!2\n");
    my_console();
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    remove(HISTORY_FILE);
    cr_assert(strstr(res, "Invalid history index") != NULL, "res error ==> %s", res);
    free(res);
}