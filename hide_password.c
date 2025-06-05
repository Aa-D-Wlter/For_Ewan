/*
** EPITECH PROJECT, 2025
** hide_password.c
** File description:
** Password
*/

#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>


int length_number(int number)
{
    int i = 0;

    for (i = 0; number <= 1; i++) {
       number /= 10;
    }
   return i;
}

char *init_cryptage(char *input, char *salt)
{
    char *encrypted = NULL;
    struct crypt_data data;

    data.initialized = 0;
    encrypted = crypt_r(input, salt, &data);
    return encrypted;
}

int hashed_password(char *key)
{
    int length = strlen(key);
    int result = 0;

    for (int i = 0; i < length; ++i) {
        result += key[i];
        result += (result << 3);
        result ^= (result >> 11);
    }
    result += (result << 10);
    result ^= (result >> 6);
    result += (result << 15);
    if (result < 0) {
        result *= -1;
    }
    return result;
}

void crypt_password(char mdp[], int length, ...)
{
    char arg;
    int i = 0;
    char here[1];
    va_list args;

    va_start(args, length);
    arg = va_arg(args, int);
    while (i < length) {
        here[0] = arg;
        strcat(mdp, here);
        arg = va_arg(args, int);
        i += 1;
    }
    va_end(args);
    return;
}