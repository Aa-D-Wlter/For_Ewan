/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** header for history
*/

#ifndef UNIT_TEST_H
    #define UNIT_TEST_H

    #include <stdio.h>

char *get_the_ouput(FILE *my_sdout);
void send_input(const char *input);
void redirect_the_output(FILE **or_output,  FILE **my_sdout);
void restore_the_ouput(FILE **or_output,  FILE **my_sdout);
FILE *send_input_to_file(char const *file_name, char const *input);
char *get_output_file(char const *file_name);

#endif /* UNIT_TEST_H */