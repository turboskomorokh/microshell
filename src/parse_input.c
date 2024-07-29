#include <string.h>
#include <stdlib.h>

#include "constants.h"

void parse_input(char* input, char** args) {
    char* token = strtok(input, " \n");
    int arg_count = 0;
    while (token != NULL && arg_count < MAX_ARGS - 1) {
        args[arg_count++] = token;
        token = strtok(NULL, " \n");
    }
    args[arg_count] = NULL;
}
