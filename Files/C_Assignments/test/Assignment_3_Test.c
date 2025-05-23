//
// Created by Joel Malagarriga Duarte on 16.02.25.
//
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../src/Assignment_3.c"

int main() {
    int result;
    double d;
    char s1[] = "Hello World";
    char s2[] = "Test123";
    char s3[] = "A";
    char s4[] = "";  // Empty string

    // Test 1: Valid index within range
    result = val(1, &d, s1);  // 'e' -> ASCII 101 -> sqrt(101) -> 10
    assert(result == 10);
    printf("Test 1 passed!\n");

    // Test 2: Valid index at the end of the string
    result = val(10, &d, s1);  // 'd' -> ASCII 100 -> sqrt(100) -> 10
    assert(result == 10);
    printf("Test 2 passed!\n");

    // Test 3: Out of range index (negative)
    result = val(-1, &d, s1);
    assert(result == -1);
    printf("Test 3 passed!\n");

    // Test 4: Out of range index (greater than length)
    result = val(11, &d, s1);
    assert(result == -1);
    printf("Test 4 passed!\n");

    // Test 5: String with numbers
    result = val(4, &d, s2);  // '1' -> ASCII 49 -> sqrt(49) -> 7
    assert(result == 7);
    printf("Test 5 passed!\n");

    // Test 6: Single character string
    result = val(0, &d, s3);  // 'A' -> ASCII 65 -> sqrt(65) -> 8
    assert(result == 8);
    printf("Test 6 passed!\n");

    // Test 7: Empty string
    result = val(0, &d, s4);
    assert(result == -1);
    printf("Test 7 passed!\n");

    // All tests passed
    printf("All tests passed successfully!\n");

    return 0;
}
