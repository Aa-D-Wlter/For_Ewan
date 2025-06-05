/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** trigger_emergency_shutdown
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


Test(configure_cooling_system, CHECK_IF_COMMAND_NOT_EXCUTED)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    cr_assert(chdir("./tests") != -1);
    cr_assert(mkdir("Data", 0777) != -1);
    redirect_the_output(&or_stdout, &my_sdout);
    send_input_to_file("Data/cooling_config.txt", "ls -l\n");
    configure_cooling_system(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    remove("Data/cooling_config.txt");
    rmdir("./Data");
    cr_assert(strstr(res, "Applying configuration") != NULL, "res error ==> %s", res);
    free(res);
}

Test(configure_cooling_system, CHECK_IF_COMMAND_PROHIBITED)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    redirect_the_output(&or_stdout, &my_sdout);
    send_input_to_file("Data/cooling_config.txt", "ls -l; python3\n");
    configure_cooling_system(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    remove("Data/cooling_config.txt");
    rmdir("./Data");
    cr_assert(strstr(res, "Command prohibited !\n") != NULL, "res error ==> %s", res);
    free(res);
}

Test(configure_cooling_system, CHECK_WHEN_FILE_NOT_EXIST)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;

    cr_assert(chdir("./tests") != -1);
    remove("Data/cooling_config.txt");
    redirect_the_output(&or_stdout, &my_sdout);
    configure_cooling_system(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    cr_assert(strstr(res, "Error: Unable to open configuration file: ") != NULL, "res error ==> %s", res);
    free(res);
}