//
// Created by Joel Malagarriga Duarte on 21.02.25.
//

#include "../inc/Assignment_7.h"

#include <stdio.h>

/*
 * Compares two strings character by character.
 * Returns:
 *   0 if both strings are equal.
 *   A negative value if str1 is smaller than str2.
 *   A positive value if str1 is larger than str2.
 */
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

int main() {
    char str1[] = "hello";
    char str2[] = "hello";

    printf("Comparing '%s' and '%s': %d\n", str1, str2, my_strcmp(str1, str2));

    return 0;
}

