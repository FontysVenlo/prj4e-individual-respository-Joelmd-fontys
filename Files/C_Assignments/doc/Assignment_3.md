# <u> Assignment 3 </u>
A function is given by the following declaration:

```c
int val(int p1, double * p2, char *p3);
```

The square root of the ascii value of the `p1`th character of the string `*p3` should be returned.
Your program has the following start of `main()`:

```c
int main() {
    int r, a; double d; char s[32];
    /* your test code */
}

int val(int p1, double * p2, char *p3) {
    /* your code */
}
```

Determine which of the following statements should be in the main():

- `&r = val(&a, d, s);` //a
- `r = val(a, &d, s);` //b
- `r = val(a, &d, &s);` //c
- `r = val(a, &d, &s[0]);` //d

Use different test scenarios to test your function.
