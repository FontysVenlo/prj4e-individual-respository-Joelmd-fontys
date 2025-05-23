//
// Created by Joel Malagarriga Duarte on 16.02.25.
//
#include "../inc/Assignment_3.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

int val(int p1, double * p2, char *p3) {
    // Check if p1 is within the valid range of the string
    if (p1 < 0 || p1 >= strlen(p3)) {
        return -1;  // Return -1 as an error code if p1 is out of range
    }

    // Get the character at position p1
    char character = p3[p1];

    // Get the ASCII value of this character
    int ascii_value = (int)character;

    // Calculate the square root of the ASCII value
    double sqrt_value = sqrt(ascii_value);

    // Convert the double result to an integer
    int result = (int)sqrt_value;

    // Return the integer result
    return result;
}

int main() {

}