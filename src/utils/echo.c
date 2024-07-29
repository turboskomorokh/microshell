#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void echo(char** args) {
    for (int i = 0; args[i] != NULL; i++) {
        if (args[i][0] == '$') {
            char* env_var = getenv(args[i] + 1);
            if (env_var == NULL) {
                printf(" ");
            }
            else {
                printf("%s ", env_var);
            }
            continue;
        }
        printf("%s ", args[i]);
    }
    printf("\n");
    return;
}