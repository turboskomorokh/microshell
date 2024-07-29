#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#include "utils/cd.h"
#include "utils/echo.h"
#include "utils/export.h"

#include "parse_input.h"
#include "constants.h"
#include "execute.h"

int main() {
    char input[MAX_INPUT_LENGTH];
    char* args[MAX_ARGS];

    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1)
        exit(EXIT_FAILURE);

    while (1) {
        printf("microsh $ ");
        fgets(input, sizeof(input), stdin);

        parse_input(input, args);

        if (args[0] != NULL) {
            if (!strcmp(args[0], "exit")) {
                break;
            }
            if (!strcmp(args[0], "export")) {
                if(args[1] != NULL)
                    export_env_var(args[1]);
                continue;
            }
            if (!strcmp(args[0], "echo")) {
                if(args[1] != NULL)
                    echo(args+1);
                continue;
            }
            if (!strcmp(args[0], "cd")) {
                if(args[1] != NULL)
                    cd(args[1]);
                continue;
            }
            execute_command(args);
        }
    }

    return 0;
}
