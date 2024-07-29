#include <linux/limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void cd(char* path) {
    char cwd[PATH_MAX];
    if (chdir(path) == -1) {
        perror("cd");
        return;
    }
    if (!strlen(path)) {
        if(chdir(getenv("HOME")) == -1) {
            perror("cd");
            return;
        }
    }
    getcwd(cwd, sizeof(cwd));
    setenv("PWD", cwd, 1);
    return;
}