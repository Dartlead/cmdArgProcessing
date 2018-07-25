/*
 Header file to hold any and all functionality pertaining to processing command
 line arguments
 */
#ifndef cmd_argument_processing_h
#define cmd_argument_processing_h

typedef struct command_line_flags_
{
    int sample_flag_one; //Denoted by the command line flag "-n". Accepted values are 1 or 2.
    int sample_flag_two; //Denoted by the command line flag "-m". Accepted values are 3 or 4.
} command_line_flags_t;

/*
 Informs the caller as to what command line flags have been entered.
 
 Inputs: argument_count - argc
         cmd_line_flags - argv
 Outputs: command_line_flags struct containing what command line flags have been entered
 */
extern command_line_flags_t what_flags_are_flagged(int argument_count, const char *cmd_line_flags[]);

#endif /* cmd_argument_processing_h */
