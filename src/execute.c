#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>

pid_t child_pid;
int status;

void sigint_handler(int signum) {
    exit(EXIT_SUCCESS);
}

int execute_command(char** args) {
    child_pid = fork();
    if (child_pid < 0) {
        perror("Can't fork subprocess");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0) {
        // Child process
        struct sigaction child_sa;
        child_sa.sa_handler = sigint_handler;
        child_sa.sa_flags = 0;
        sigemptyset(&child_sa.sa_mask);
        
        if (sigaction(SIGINT, &child_sa, NULL) == -1)
            exit(EXIT_FAILURE);

        if (execvp(args[0], args) == -1) {
            perror("Can't execute");
            exit(EXIT_FAILURE);
        }
    }
    else {
        // Parent process
        waitpid(child_pid, &status, 0);
        return status;
    }
}
