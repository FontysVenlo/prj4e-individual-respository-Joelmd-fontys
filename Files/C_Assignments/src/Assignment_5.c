//
// Created by Joel Malagarriga Duarte on 20.02.25.
//

#include <stdio.h>
#include "../inc/Assignment_5.h"



unsigned long int date_encode(int year, int month, int day) {

  // - Day takes up 5 bits
  // - Month is shifted 5 bits to the left
  // - Year is shifted 4 + 5 bits to the left
  unsigned long int encodedDate = day | (month << 5 | year << 9);
  return encodedDate;
}

void date_decode(unsigned long int encoded_date, int *year, int *month, int *day) {
    *day = encoded_date & 31;
    *month = (encoded_date >> 5) & 15;
    *year = (encoded_date >> 9) & 4095;
}



int main(){
  int year = 2025, month = 2, day = 12;
  unsigned long int encoded_date;

  encoded_date = date_encode(year, month, day);
  printf("Encoded Date: %lu\n", encoded_date);

  int decoded_year, decoded_month, decoded_day;

  date_decode(encoded_date, &decoded_year, &decoded_month, &decoded_day);
  printf("Decoded Date: Year = %d, Month = %d, Day = %d\n", decoded_year, decoded_month, decoded_day);

  return 0;
}