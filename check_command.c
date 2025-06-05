/*
** EPITECH PROJECT, 2025
** handle_string.c
** File description:
** string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "pipeto.h"

void write_in_file(char data[], int fd)
{
    int result = 0;
    char *check = NULL;
    int length = 0;

    result = hashed_password(data);
    length = length_number(result);
    check = malloc(sizeof(char) * length + 1);
    if (check == NULL) {
       return;
    }
    sprintf(check, "%d", result);
    write(fd, check, strlen(check));
    free(check);
}

int word_in_string(char const *str, char const *word)
{
    int count = 0;
    size_t i = 0;

    if (str == NULL || word == NULL)
        return count;
    while (str[i] != '\0') {
        if (strncmp(&str[i], word, strlen(word)) == 0) {
            count = count + 1;
            i += strlen(word);
        } else {
            i += 1;
        }
    }
    return count;
}
