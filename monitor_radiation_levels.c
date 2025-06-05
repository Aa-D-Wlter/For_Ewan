/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** monitor_radiation_levels
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "history.h"
#include "macro_pipeto.h"

#include <stdio.h>
static void secret_function(void)
{
    printf("{The stone isn't in the pocket anymore ...}\n");
}

void monitor_radiation_levels(UNUSED bool *is_admin, UNUSED history_t *history)
{
    char buffer[10];
    void (*function_ptr)(void) = NULL;

    printf("Enter radiation levels: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("Radiation Levels: %s\n", buffer);
    if (function_ptr) {
        function_ptr();
    } else {
        printf("Function Pointer: %p\n", (void *) function_ptr);
    }
}
