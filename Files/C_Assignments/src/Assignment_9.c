//
// Created by Joel Malagarriga Duarte on 25.02.25.
//

#include <stdio.h>
#include <stdlib.h>

//Use HOME as the env for testing

int main(int argc, char *argv[]){
    if (argc != 2) { // Check if the user provided one argument
        printf("Usage: %s <ENV_VARIABLE>\n", argv[0]);
        return 1;
    }

    char *value = getenv(argv[1]); // Get the value of the environment variable

    if (value) { // If the variable exists, print its value
        printf("%s\n", value);
    } else { // If it does not exist, print an error message
        printf("Environment variable '%s' not found.\n", argv[1]);
    }

    return 0;
}