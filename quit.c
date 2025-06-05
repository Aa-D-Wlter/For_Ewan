/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** exit
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "history.h"
#include "macro_pipeto.h"

void quit(UNUSED bool *is_admin, UNUSED history_t *history)
{
    printf("Exiting program...\n");
    exit(0);
}
