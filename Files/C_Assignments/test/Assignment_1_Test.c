//
// Created by Joel Malagarriga Duarte on 11.02.25.
//

#include <assert.h>
#include "../src/Assignment_1.c"

void test_occurrences() {
    int arr1[] = {1, 2, 3, 4, 3, 5};
    int size = *(&arr1 + 1) - arr1;
    int arr2[] = {1, 2, 3, 4, 3, 5, -1};
    printf("Testing occurrences1\n");
    assert(occurrences1(arr1, size, 3) == 2);
    assert(occurrences1(arr1, size, 1) == 1);
    assert(occurrences1(arr1, size, 6) == 0);

    printf("Testing occurrences2\n");
    assert(occurrences2(arr2, 3) == 2);
    assert(occurrences2(arr2, 1) == 1);
    assert(occurrences2(arr2, 6) == 0);

    printf("All tests passed!\n");
}

int main() {
    test_occurrences();
}