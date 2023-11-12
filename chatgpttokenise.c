#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TOKENS 64

int main() {
    char *input = NULL;
    char *tokens[MAX_TOKENS];
    ssize_t reading;
    size_t len = 0;
    int status;
    pid_t process;

    while (1) {
        printf("$ ");
        reading = getline(&input, &len, stdin);

        if (reading == -1) {
            perror("Error: Getline failed");
            /* continue; */
        }

        if (input[reading - 1] == '\n') {
            input[reading - 1] = '\0';
        }

        char *token = strtok(input, " ");
        int i = 0;
        while (token != NULL && i < MAX_TOKENS - 1) {
            tokens[i++] = token;
            token = strtok(NULL, " ");
        }
        tokens[i] = NULL;

        process = fork();
        if (process == -1) {
            perror("Error: Fork failed!");
            exit(EXIT_FAILURE);
        } else if (process == 0) {
            execve(tokens[0], tokens, NULL);
            perror("Error: Command does not exist");
            exit(EXIT_FAILURE);
        } else {
            waitpid(process, &status, 0);
        }
    }

    free(input); // Free allocated memory
    return 0;
}

