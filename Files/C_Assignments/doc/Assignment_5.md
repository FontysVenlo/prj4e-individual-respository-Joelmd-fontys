# <u> Assignment 5 </u>
Write a function which is declared as follows:
```c
unsigned long int date_encode(int year, int month, int day);
```

The purpose of this function is to code the given date in the 21 right most bits of an unsigned int and
to return this unsigned int. <br>
The remaining left bits retain there value 0, from left to right these 21 bits are:

- 12 bits for the year ( <=4096)
- 4 bits for the month (<=12)
- 5 bits for the day (<=31)

Write a function ... date_decode( ... ) that decodes the encoded date. <br>
Write a main() to test your functions, use different test scenarios.
