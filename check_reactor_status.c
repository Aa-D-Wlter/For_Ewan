/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** check_reactor_status
*/

#include <stdio.h>
#include <unistd.h>

#include "pipeto.h"

void encrypt_message(const char *input, char *output, int shift)
{
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A' + shift) % 26) + 'A';
            continue;
        }
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a' + shift) % 26) + 'a';
        } else {
            output[i] = input[i];
        }
    }
}

void check_reactor_status(UNUSED bool *is_admin, UNUSED history_t *history)
{
    const char *message = "ReactorStatusOK";
    char encrypted_message[50] = {0};

    print_message("Starting reactor status check...\n", 1);
    print_message("Checking core temperature...\n", 1);
    print_message("Core temperature: Normal\n", 1);
    print_message("Checking coolant flow rate...\n", 1);
    print_message("Coolant flow rate: Stable\n", 1);
    print_message("Checking radiation levels...\n", 2);
    printf("Radiation levels: Safe\n\n");
    printf("Encrypting critical reactor data...\n");
    encrypt_message(message, encrypted_message, 3);
    sleep(1);
    printf("Encrypted message: %s\n\n", encrypted_message);
    printf("Reactor status: OK\n");
    printf("Reactor status check complete.\n\n");
}
