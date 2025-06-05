##
## EPITECH PROJECT, 2025
## pipeto
## File description:
## header for ansi_colors
##

CC 	?= gcc

RM 	?= rm -f

CP	?= cp -r

NAME =	pipeto

SRC 	=	src/my_console.c \
			src/utils.c \
			src/check_command.c \
			$(addprefix src/commands/, $(COMMANDS_SRC)) \
			$(addprefix src/history/, $(HISTORY_SRC)) \

COMMANDS_SRC	=	activate_emergency_protocols.c \
		hide_password.c \
		check_cooling_pressure.c	\
		check_reactor_status.c	\
		configure_cooling_system.c	\
		enable_remote_access.c	\
		help.c	\
		init_reactor.c	\
		load_fuel_rods.c	\
		log_system_events.c	\
		monitor_radiation_levels.c \
		run_diagnostic.c	\
		send_status_report.c	\
		set_reactor_power.c	\
		simulate_meltdown.c	\
		quit.c	\
		unlock_secret_mode.c	\
		load_config.c	\
		history.c 	\
		trigger_emergency_shutdown.c \

HISTORY_SRC		=	display_history.c \
		history_init.c \
		process_history.c \

MAIN_SRC	=	src/main.c

OBJ	= $(SRC:.c=.o)

MAIN = $(MAIN_SRC:.c=.o)

UNIT_TESTS = manage_file_depend_test.c\
		redirect_flux.c \
		test_load_fuel_rods.c \
		test_activate_emergency_protocols.c \
		test_unlock_secret_mode.c \
		test_trigger_emergency_shutdown.c \
		test_monitor_radiation_levels.c \
		test_load_config.c \
		test_history.c\
		test_log_system_event.c \
		test_utils.c \
		test_run_diagnostic.c \
		test_configure_cooling_system.c \
		test_check_cooling_pressure.c \
		test_check_reactor_status.c \
		test_help.c \
		test_init_reactor.c \
		test_quit.c \
		test_send_status_report.c \
		test_set_reactor_power.c \
		test_enable_remote_access.c \

LIBPEPITO_SRC	=	$(addprefix Libpepito/src/, \
			init_steam_turbine.c	\
			read_turbine_config.c	\
			turbine_remote_access.c	\
			turbine_temperature.c	\
			run_turbine.c)


UT_SRC = $(addprefix tests/tests_src/, $(UNIT_TESTS))

LDLIBS =  -ldl -rdynamic

CFLAGS += -Wall -Wextra -fPIC

INCLUDE_FLAGS	= -lcrypt

CRITERION = -lcriterion

CPPFLAGS += -iquote ./include

all: $(NAME)

$(OBJ): CFLAGS += -g3 -ggdb

$(NAME): libpepito_run $(OBJ) $(MAIN)
	$(CC) -o $(NAME) $(CFLAGS) $(CPPFLAGS) $(MAIN) $(OBJ) $(LDLIBS) $(INCLUDE_FLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) *.gc*
	$(RM) unit_tests
	$(RM) $(NAME)
	$(MAKE) -C Libpepito fclean
	$(RM) libpepito.so

libpepito_run:
	$(MAKE) -C Libpepito

re: fclean all

unit_tests: LDLIBS += $(CRITERION)
unit_tests: fclean
	$(CC) -o unit_tests $(SRC) $(UT_SRC) \
	$(CPPFLAGS) $(CFLAGS) $(LDLIBS) $(LDFLAGS) --coverage $(INCLUDE_FLAGS)

tests_run: unit_tests
	./unit_tests
	gcovr --exclude tests/
	gcovr --txt-metric branch --exclude tests/
	$(MAKE) fclean

apply_patches:
	@for patch in $(wildcard *.c.patch); do \
	git apply "$$patch"; \
	done
restore_patched_files:
	@echo "Restore patched files in progress..."

.PHONY: all clean fclean re unit_tests tests_run
