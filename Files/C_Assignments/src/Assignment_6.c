//
// Created by Joel Malagarriga Duarte on 21.02.25.
//

#include "../inc/Assignment_6.h"
#include <stdio.h>

unsigned char pbcd(int n){
  // Extract the least significant two digits
  int ones = n % 10;          // Last digit
  int tens = (n / 10) % 10;   // Second-last digit

  // Shift the tens place to the left and OR with ones
  return (tens << 4) | ones;
}

int main(){
  int n = 923812;
  unsigned char result = pbcd(n);
  printf("PBCD: 0x%02X\n", result);
  return 0;

}