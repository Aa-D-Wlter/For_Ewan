/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** header for pipeto
*/

#ifndef PIPETO_H_
    #define PIPETO_H_

    #include <stddef.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include "macro_pipeto.h"
    #include "history.h"

extern bool IS_ADMIN;

int my_console(void);
void init_reactor(UNUSED bool *is_admin, UNUSED history_t *history);
void check_reactor_status(UNUSED bool *is_admin, UNUSED history_t *history);
void activate_emergency_protocols(bool *is_admin, UNUSED history_t *history);
void simulate_meltdown(UNUSED bool *is_admin, UNUSED history_t *history);
void check_cooling_pressure(UNUSED bool *is_admin, UNUSED history_t *history);
void send_status_report(UNUSED bool *is_admin, UNUSED history_t *history);
void monitor_radiation_levels(UNUSED bool *is_admin,
    UNUSED history_t *history);
void set_reactor_power(UNUSED bool *is_admin, UNUSED history_t *history);
void run_diagnostic(UNUSED bool *is_admin, UNUSED history_t *history);
void enable_remote_access(UNUSED bool *is_admin, UNUSED history_t *history);
void check_cooling_pressure(UNUSED bool *is_admin, UNUSED history_t *history);
void quit(UNUSED bool *is_admin, UNUSED history_t *history);
void help(UNUSED bool *is_admin, UNUSED history_t *history);
void load_fuel_rods(UNUSED bool *is_admin, UNUSED history_t *history);
void log_system_event(UNUSED bool *is_admin, UNUSED history_t *history);
void unlock_secret_mode(bool *is_admin, UNUSED history_t *history);
void load_config(UNUSED bool *is_admin, UNUSED history_t *history);
void show_history(UNUSED bool *is_admin, history_t *history);
void configure_cooling_system(UNUSED bool *is_admin,
    UNUSED history_t *history);
void trigger_emergency_shutdown(bool *is_admin, UNUSED history_t *history);
void print_message(char const *buffer, int nb_sleep);
void process_command(char *line,
    history_t *history, bool *is_admin);
void crypt_password(char mdp[], int length, ...);
int hashed_password(char *key);
int word_in_string(char const *str, char const *word);
char *init_cryptage(char *input, char *salt);
void write_in_file(char data[], int fd);
int length_number(int number);

static char const *const not_accessible_command[] = {
    "cat",
    "sudo",
    "chown",
    "echo",
    "rm",
    "chmod",
    "exit",
    "shutdown",
    "python3",
    "gdb",
    "mv",
    "touch",
    "mkdir",
    NULL
};

static char const *const adminPassword = "ThisIsTheBestPassword";

typedef struct all_commands_s {
    int nb_command;
    void (*execute)(bool *is_admin, history_t *history);
}all_commands_t;

enum commands {
    INIT_REACTOR,
    CHECK_REACTOR_STATUS,
    ACTIVATE_EMERGENCY_PROTOCOLS,
    SIMULATE_MELTDOWN,
    CHECK_COOLING_PRESSURE,
    SEND_STATUS_REPORT,
    MONITOR_RADIATION_LEVELS,
    SET_REACTOR_POWER,
    RUN_DIAGNOSTIC,
    ENABLE_REMOTE_ACCESS,
    QUIT,
    HELP,
    LOAD_FUEL_RODS,
    LOG_SYSTEM_EVENT,
    UNLOCK_SECRET_MODE,
    LOAD_CONFIG,
    HISTORY,
    CONFIGURE_COOLING_SYSTEM,
    TRIGGER_EMERGENCY_SHUTDOWN,
    COMMAND_COUNT,
};

static char const *const command_strings[] = {
    "init_reactor",
    "check_reactor_status",
    "activate_emergency_protocols",
    "simulate_meltdown",
    "check_cooling_pressure",
    "send_status_report",
    "monitor_radiation_levels",
    "set_reactor_power",
    "run_diagnostic",
    "enable_remote_access",
    "quit",
    "help",
    "load_fuel_rods",
    "log_system_event",
    "unlock_secret_mode",
    "load_config",
    "history",
    "configure_cooling_system",
    "trigger_emergency_shutdown",
};

static char const *const command_strings_lib[] = {
    "init_steam_turbine",
    "read_turbine_config",
    "turbine_remote_access",
    "turbine_temperature",
    "run_turbine",
};


static const all_commands_t check_command[] = {
    {INIT_REACTOR, init_reactor},
    {CHECK_REACTOR_STATUS, check_reactor_status},
    {ACTIVATE_EMERGENCY_PROTOCOLS, activate_emergency_protocols},
    {SIMULATE_MELTDOWN, simulate_meltdown},
    {CHECK_COOLING_PRESSURE, check_cooling_pressure},
    {SEND_STATUS_REPORT, send_status_report},
    {MONITOR_RADIATION_LEVELS, monitor_radiation_levels},
    {SET_REACTOR_POWER, set_reactor_power},
    {RUN_DIAGNOSTIC, run_diagnostic},
    {ENABLE_REMOTE_ACCESS, enable_remote_access},
    {QUIT, quit},
    {HELP, help},
    {LOAD_FUEL_RODS, load_fuel_rods},
    {LOG_SYSTEM_EVENT, log_system_event},
    {UNLOCK_SECRET_MODE, unlock_secret_mode},
    {LOAD_CONFIG, load_config},
    {HISTORY, show_history},
    {CONFIGURE_COOLING_SYSTEM, configure_cooling_system},
    {TRIGGER_EMERGENCY_SHUTDOWN, trigger_emergency_shutdown},
};

static char const *const dummy_urls[] = {
    "http://example.com/api/enable",
    "http://example.com/api/disable",
    "http://example.com/api/status"
};

static char const *const hostname = "localhost";
static char const *const ip_address = "127.0.0.1";
static char const *const process_info = "Process: pipeto (PID: 1234)";
static char const *const errors_status_report[] = {
    "Error: Unable to create a file in Data/, you must create a Data folder.",
    "Status report sent and saved to 'Data/status_report.txt'."
};

enum commands_lib {
    INIT_STEAM_TURBINE,
    READ_TURBINE_CONFIG,
    TURINE_REMOTE_ACCESS,
    RUN_TURBINE,
    TURBINE_TEMPERATURE,
    COMMAND_COUNT_LIB
};

#endif /* !PIPETO_H_ */
