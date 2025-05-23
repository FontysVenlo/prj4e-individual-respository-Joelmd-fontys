//
// Created by Joel Malagarriga Duarte on 11.02.25.
//
#include <stdio.h>

// Approach 1 -- Pass the size
int occurrences1(int arr[], int size ,int specific){
    int counter = 0;
    for (int i = 0; i <= size - 1; i++) {
        if (arr[i] == specific) {
            counter++;
        }
    }
    //printf("%d\n", counter);
    return counter;
}

// Approach 2 -- have a distinct final element
int occurrences2(int arr[], int specific){
    int counter = 0;
    int i = 0;
    //set distinct element to -1
    while (arr[i] != -1) {
        if (arr[i] == specific) {
            counter++;
        }
        i++;
    }
    //printf("%d\n", counter);
    return counter;
}

