//
// Created by Joel Malagarriga Duarte on 12.02.25.
//

#include "../inc/Assignment_2.h"

#include <stdio.h>

// *sum means it passes not the value but the entire pointer so its the same variable as outside of the function
void sumOfElements(int arr[], int size, int *sum){
  for(int i = 0; i <= size - 1; i++){
     *sum += arr[i];
  }
}
