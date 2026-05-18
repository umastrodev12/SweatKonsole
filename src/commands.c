#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int restart() {
    printf("You want to restart Niro Konsole? (s/n):");
    char resp;
    scanf(" %c", &resp);

    if (resp == 's' || resp == 'S') {
        printf("Restarting System...");
        return 0;
    }

    return 0;
}

int execCommand(char **args) {
    if (strcmp(args[0], "exit") == 0) {
        printf("👋 Goodbye! Shutting Down...");
        return 0; // shut down niro console
    }
}