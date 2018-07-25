/* Standard Header Files */
#include <stdio.h>

/* Project Header Files */
#include "cmd_argument_processing.h"

int main(int argc, const char * argv[]) {
    
    command_line_flags_t flags_flagged = what_flags_are_flagged(argc, argv);
    
    while (1)
    {
        //Do whatever you want!
    }
    
    return 0;
}
