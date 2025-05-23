//
// Created by Joel Malagarriga Duarte on 12.02.25.
//

#include <assert.h>
#include "../src/Assignment_2.c"

#include <stdio.h>

void test_summation(){
  int arr1[] = {1, 2, 3, 4, 5, 6};
  int arr2[] = {7, 8, 9, 10, 11, 12};
  int arr3[] = {-1, -2, -3, -4, -5, -6};
  int sum1 = 0;
  int sum2 = 0;
  int sum3 = 0;
  int size = *(&arr1 + 1) - arr1;
  sumOfElements(arr1, size, &sum1);
  assert(sum1 == 21);
  sumOfElements(arr2, size, &sum2);
  assert(sum2 == 57);
  sumOfElements(arr3, size, &sum3);
  assert(sum3 == -21);
}

int main(){
  test_summation();
}

