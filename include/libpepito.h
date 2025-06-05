/*
** EPITECH PROJECT, 2024
** Pepito library
** File description:
** pepito.h
*/


#ifndef LIBPEPITO_H_
    #define LIBPEPITO_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <limits.h>
    #include <time.h>
    #include <fcntl.h>
    #include <unistd.h>

void init_steam_turbine(void);
void read_turbine_config(void);
void turbine_remote_access(void);
void turbine_temperature(void);
void run_turbine(void);

#endif /* LIBPEPITO_H_ */
