#include <iostream>
#include "../lib/conio.h"
#include <cstdlib>
#include <string.h>

// to clear all the screen     printf("\033[2J\033[H");
// to clear one line           printf("[2K");

void bash() {
    char buffer[100];

    printf("bash mode: ");
    
    for(int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = getch();

        if(strcmp(buffer, "exit") == 0) {
            fflush(stdout);
            printf("this isn't you're terminal dummy...");
            sleep(3);
            printf("[2K");
        }
        
        if(buffer[i] == 10) {
            buffer[i] = 0;

            system(buffer);
            bash();
        }
    }
}

int main() {
    char buffer[100];

    printf("\033[2J\033[H");

    for(int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = getch();

        if(buffer[i] == 10) {
            buffer[i] = 0;

            if(strcmp(buffer, "bash") == 0) {
                bash();
            }

            return 0;
        }
    }

    printf("you typed: %s", buffer);

    return 0;
}
