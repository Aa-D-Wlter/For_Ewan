##
## EPITECH PROJECT, 2025
## makefile
## File description:
## Makefile
##

SRC		=	src/init_steam_turbine.c	\
			src/read_turbine_config.c	\
			src/turbine_remote_access.c	\
			src/turbine_temperature.c	\
			src/run_turbine.c 	\

OBJ = $(SRC:.c=.o)

NAME =	libpepito.so

LDFLAGS += -shared

CFLAGS += -Wall -Wextra -fPIC

CPPFLAGS += -iquote ./../include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	mv libpepito.so ./../
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
