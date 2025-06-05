/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** unlock_secret_mode
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pipeto.h"

void unlock_secret_mode(bool *is_admin, UNUSED history_t *history)
{
    if (*is_admin == true) {
        printf("Secret mode unlocked! Welcome, admin.\n");
        printf("{ADMIN4242}\n");
    } else {
        printf("Access denied. You do not have the required privileges.\n");
    }
}
