#include <string.h>
#include <stdlib.h>

void export_env_var(char* input) {
    char* var_name = strtok(input, "=");
    char* var_value = strtok(NULL, "=");
    if (var_value != NULL) {
        setenv(var_name, var_value, 1);
        return;
    }
    setenv(var_name, "", 1);
    return;
}
