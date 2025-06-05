/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** log_system_event
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <criterion/criterion.h>

#include "pipeto.h"
#include "unit_test.h"

Test(log_system_event, write_secret_key)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    FILE *file_system = NULL;
    char *res = NULL;
    char *buffer = NULL;
    size_t len = 0;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input("leak\n");
    log_system_event(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(chdir("./Data") != -1);
    file_system = fopen("system.log", "r");
    cr_assert(file_system != NULL);
    while (getline(&buffer, &len, file_system) != -1);
    cr_assert(strstr(buffer, "{SECRET_LOG_12PIERRE34}") != NULL, "res error ==> %s\n", res);
    fclose(file_system);
    free(buffer);
}
