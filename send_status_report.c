/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** send_status_report
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "pipeto.h"

const char *base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static void calculate_array(unsigned char char_array_3[3],
    unsigned char char_array_4[4])
{
    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4)
    + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2)
    + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;
}

static void application_one(unsigned char char_array_3[3],
    unsigned char char_array_4[4], char *output, int *j)
{
    int i = 3;

    calculate_array(char_array_3, char_array_4);
    for (i = 0; i < 4; i++) {
        output[*j] = base64_chars[char_array_4[i]];
        *j += 1;
    }
}

static void application_two(int *i, unsigned char char_array_4[4],
    char *output, int *j)
{
    for (int k = 0; k < *i + 1; k++) {
        output[*j] = base64_chars[char_array_4[k]];
        *j += 1;
    }
    while (*i < 3) {
        output[*j] = '=';
        *j += 1;
        *i += 1;
    }
}

void base64_encode(const char *input, char *output, int i)
{
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (*input) {
        char_array_3[i] = *input;
        i += 1;
        input++;
        if (i == 3) {
            application_one(char_array_3, char_array_4, output, &j);
            i = 0;
        }
    }
    if (i) {
        for (int k = i; k < 3; k++)
            char_array_3[k] = '\0';
        calculate_array(char_array_3, char_array_4);
        application_two(&i, char_array_4, output, &j);
    }
    output[j] = '\0';
}

void send_status_report(UNUSED bool *is_admin, UNUSED history_t *history)
{
    char report[256];
    char encoded_report[512];
    int index = 0;
    FILE *file = fopen("Data/status_report.txt", "w");

    if (!file) {
        printf("%s\n", errors_status_report[0]);
        return;
    }
    snprintf(report, sizeof(report), "Hostname: %s\nIP Address: %s\n%s\n",
    hostname, ip_address, process_info);
    base64_encode(report, encoded_report, index);
    fprintf(file, "Encoded Status Report:\n%s\n", encoded_report);
    fclose(file);
    printf("%s\n", errors_status_report[1]);
}
