/* Directly associated header file */
#include "cmd_argument_processing.h"

/* Standard library files */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*--------------------------------Static Global Variables--------------------------------------*/
static command_line_flags_t command_line_flags_flagged;

/*--------------------------------Private Function Prototypes----------------------------------*/
/*
 Initializes the presence of the command line flags to their default state.
 
 Inputs: none
 Outputs: none
 */
static void initialize_default_value_command_line_flags(void);

/*
 Processes the command line flags.
 
 Inputs: argument_count - the number of elements in the argv array
         cmd_line_flags - the argv array
 Outputs: none
 */
static void process_command_line_flags(int argument_count, const char *cmd_line_flags[]);

/*
 This function is called if and only if the first command line flag is found. In
 this case, this function is called to check what the value after the command line
 flag is (should be the value of the flag).
 
 Inputs: flag - the value of the argv array after the command line flag
 Outputs: none
 */
static int process_sample_flag_one(const char *possible_flag_one_value);

/*
 This function is called if and only if the second command line flag is found. In
 this case, this function is called to check what the value after the command line
 flag is (should be the value of the flag).
 
 Inputs: flag - the value of the argv array after the command line flag
 Outputs: none
 */
static int process_sample_flag_two(const char *possible_flag_two_value);

/*--------------------------------Function Definitions-----------------------------------------*/
/*
 Informs the caller as to what command line flags have been entered.
 
 Inputs: argument_count - argc
         cmd_line_flags - argv
 Outputs: command_line_flags struct containing what command line flags have been entered
 */
command_line_flags_t what_flags_are_flagged(int argument_count, const char *cmd_line_flags[])
{
    initialize_default_value_command_line_flags();
    
    process_command_line_flags(argument_count, cmd_line_flags);
    
    return command_line_flags_flagged;
}

/*--------------------------------Private Function Definitions---------------------------------*/
/*
 Initializes the presence of the command line flags to their default state.
 
 Inputs: none
 Outputs: none
 */
static void initialize_default_value_command_line_flags(void)
{
    command_line_flags_flagged.sample_flag_one = 0;
    command_line_flags_flagged.sample_flag_two = 0;
}

/*
 Processes the command line flags.
 
 Inputs: argument_count - the number of elements in the argv array
         cmd_line_flags - the argv array
 Outputs: none
 */
static void process_command_line_flags(int argument_count, const char *cmd_line_flags[])
{
    int argv_array_index;
    for (argv_array_index = 0; argv_array_index < argument_count; ++argv_array_index)
    {
        /* Check if the first sample flag has been entered */
        if (strcmp(cmd_line_flags[argv_array_index], "-n") == 0)
        {
            command_line_flags_flagged.sample_flag_one = process_sample_flag_one(cmd_line_flags[argv_array_index + 1]);
        }
        else
        {
            //Do nothing as the command line flag has not been entered
        }
        
        /* Check if the second sample flag has been entered */
        if (strcmp(cmd_line_flags[argv_array_index], "-m") == 0)
        {
            command_line_flags_flagged.sample_flag_two = process_sample_flag_two(cmd_line_flags[argv_array_index + 1]);
        }
        else
        {
            //Do nothing as the command line flag has not been entered
        }
    }
}

/*
 This function is called if and only if the first command line flag is found. In
 this case, this function is called to check what the value after the command line
 flag is (should be the value of the flag).
 
 Inputs: flag - the value of the argv array after the command line flag
 Outputs: none
 */
static int process_sample_flag_one(const char *possible_flag_one_value)
{
    int flag_value = 0;
    int potential_flag_value = atoi(possible_flag_one_value);
    
    /* Check the validity of the command line flag */
    if ((potential_flag_value == 1) || (potential_flag_value == 2))
    {
        flag_value = potential_flag_value;
    }
    else
    {
        printf("Error. Enter a valid value for sample flag one\n");
        exit(-1);
    }
    
    return flag_value;
}

/*
 This function is called if and only if the second command line flag is found. In
 this case, this function is called to check what the value after the command line
 flag is (should be the value of the flag).
 
 Inputs: flag - the value of the argv array after the command line flag
 Outputs: none
 */
static int process_sample_flag_two(const char *possible_flag_two_value)
{
    int flag_value = 0;
    int potential_flag_value = atoi(possible_flag_two_value);
    
    /* Check the validity of the command line flag */
    if ((potential_flag_value == 3) || (potential_flag_value == 4))
    {
        flag_value = potential_flag_value;
    }
    else
    {
        printf("Error. Enter a valid value for sample flag two\n");
        exit(-1);
    }
    
    return flag_value;
}
