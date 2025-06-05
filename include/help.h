/*
** EPITECH PROJECT, 2025
** pipeto
** File description:
** header for history
*/

#ifndef HELP
    #define HELP

static char const *const commands[] = {
    "- init_reactor: Initialize the reactor for operation.\n",
    "- check_reactor_status: Check the current status of the reactor.\n",
    "- activate_emergency_protocols: Activate emergency protocols",
    " (requires admin).\n"
    "- simulate_meltdown: Simulate a reactor meltdown for testing purposes.\n",
    "- check_cooling_pressure: Check the pressure in the cooling system.\n",
    "- send_status_report: Send a status report to the control center.\n",
    "- monitor_radiation_levels: Monitor radiation levels in the reactor.\n",
    "- set_reactor_power: Adjust the reactor's power output.\n",
    "- run_diagnostic: Run a full diagnostic on the reactor systems.\n",
    "- enable_remote_access: Enable or disable remote access ",
    "to the reactor.\n"
    "- quit: Exit the console.\n",
    "- help: Display this help message.\n",
    "- load_fuel_rods: Load fuel rods into the reactor.\n",
    "- log_system_event: Log a system event.\n",
    "- history: Display command history.\n",
    "- !n: Execute command number n from history.\n"
    "- load_config: Load configuration from a file.\n",
    "- configure_cooling_system: Configure the cooling system.\n",
    "---- External libraries ----\n",
    "- init_steam_turbine: Initialize the turbine.\n",
    "- read_turbine_config: Read the turbine configuration.\n",
    "- run_turbine: Run the turbine.\n",
    "- turbine_temperature: Change the turbine temperature.\n",
    "- turbine_remote_access: Remote access to the turbine.\n",
};
#endif
