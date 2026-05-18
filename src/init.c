#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define COLOR_RESET   "\x1b[0m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"

char* getUser() {
    char *user = NULL;

    #ifdef _WIN32
        user = getenv("USERNAME");
    #else
        user = getenv("USER");
    #endif

    if (user == NULL) {
        return "user";
    }

    return user;
}

int init_message() {
    printf("[INIT SYSTEM] Starting Niro Console...", COLOR_RESET);
    printf("[INIT SYSTEM] Welcome", getUser, "!");
}

int start() {
    printf("\033[H\033[J");
    init_message();
}