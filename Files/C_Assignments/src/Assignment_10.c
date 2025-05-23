//
// Created by Joel Malagarriga Duarte on 25.02.25.
//

#include <stdio.h>
#include <stdlib.h>

void read_input(int max_value){
    int input;
    int ch;
    // Keep loop running till break condition is reached
    if(max_value == 0){
        while(1){
            ch = getchar();
            if (ch == '\n') {
                break;
            }
            // Put the character back so scanf can read it.
            ungetc(ch, stdin);

            // Attempt to read an integer.
            if (scanf("%d", &input) == 1) {
                printf("%d\n", input);
            } else {
                printf("Invalid input.\n");
            }
            // Clean line before stopping
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    } else {
        while(1){
            scanf("%d", &input);
            // Breakcondition
            if (input == max_value) {
                break;
            }
            printf("%d\n", input);
        }
    }
}

int main(int argc, char *argv[]){
    int max_value = 0;

    // Check if there's a command line argument
    if (argc == 2) {
        max_value = atoi(argv[1]);  // Use the first argument as the max value
    }
    // If argc == 1 (no parameters), we just proceed with default max_value (INT_MAX)

    read_input(max_value);
    return 0;
}