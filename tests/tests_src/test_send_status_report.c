/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** send_status_report
*/

#include <string.h>
#include <stdio.h>
#include <string.h>
#include <criterion/criterion.h>
#include <unistd.h>

#include "pipeto.h"
#include "unit_test.h"


static char *check_line_file(void)
{
    FILE *file_system = NULL;
    char *buffer = NULL;
    size_t len = 0;

    cr_assert(chdir("./Data") != -1);
    file_system = fopen("status_report.txt", "r");
    cr_assert(file_system != NULL);
    while (getline(&buffer, &len, file_system) != -1);
    fclose(file_system);
    return buffer;
}

Test(send_status_report, is_crypted)
{
    FILE *or_stdout = NULL;
    FILE *my_sdout =  NULL;
    char *res = NULL;
    int mdp_crypted = 0;
    char *mdp_str = NULL;
    char *buffer = NULL;

    redirect_the_output(&or_stdout, &my_sdout);
    send_status_report(NULL, NULL);
    res = get_the_ouput(my_sdout);
    restore_the_ouput(&or_stdout, &my_sdout);
    mdp_crypted = hashed_password("Hostname: localhost\nIP Address: 127.0.0.1\nProcess: pipeto (PID: 1234)\n");
    buffer = check_line_file();
    mdp_str = malloc(sizeof(char) * (length_number(mdp_crypted) + 1));
    cr_assert(mdp_str != NULL);
    sprintf(mdp_str, "%d", mdp_crypted);
    cr_assert(strstr(buffer, mdp_str) != NULL, "res error ==> %s", res);
    free(buffer);
    free(mdp_str);
}

Test(simulate_meltdown, check_meltdown)
{
    bool is_admin = false;
    simulate_meltdown(&is_admin, NULL);
}