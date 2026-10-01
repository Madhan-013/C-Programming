/*
 * ============================================================================
 *  05_functions.c — Functions in C
 * ============================================================================
 *  Topics covered:
 *    - Declaration, definition, parameters, return values
 *    - Call by value vs call by reference
 *    - Recursion
 *    - Inline functions (C99)
 *    - Builtin-style helpers (static utility functions)
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 05_functions 05_functions.c
 *  Run     : ./05_functions
 * ============================================================================
 */

#include <stdio.h>

/* ---- Function declarations (prototypes) -------------------------------- */
int  add(int a, int b);
void swap_by_value(int a, int b);
void swap_by_reference(int *a, int *b);
int  factorial(int n);
int  fibonacci(int n);
static inline int square(int x);   /* inline hint — C99 */

/* Simple "builtin-style" helper: absolute value */
static int my_abs(int x)
{
    return (x < 0) ? -x : x;
}

/* ---- Definitions ------------------------------------------------------- */

/* Returns the sum of two integers */
int add(int a, int b)
{
    return a + b;
}

/* Call by value: copies are modified; originals unchanged */
void swap_by_value(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    printf("  Inside swap_by_value : a=%d, b=%d\n", a, b);
}

/* Call by reference: swap via pointers; originals change */
void swap_by_reference(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("  Inside swap_by_ref   : *a=%d, *b=%d\n", *a, *b);
}

/* Recursive factorial: n! = n * (n-1)! */
int factorial(int n)
{
    if (n <= 1)
        return 1;                 /* base case */
    return n * factorial(n - 1);  /* recursive case */
}

/* Recursive Fibonacci: F(n) = F(n-1) + F(n-2) */
int fibonacci(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/* Inline function — compiler may substitute body at call site */
static inline int square(int x)
{
    return x * x;
}

/* ---- main -------------------------------------------------------------- */
int main(void)
{
    printf("=== Function Call & Return ===\n");
    printf("add(7, 5) = %d\n", add(7, 5));

    printf("\n=== Call by Value ===\n");
    int x = 10, y = 20;
    printf("Before: x=%d, y=%d\n", x, y);
    swap_by_value(x, y);
    printf("After : x=%d, y=%d  (unchanged)\n", x, y);

    printf("\n=== Call by Reference ===\n");
    printf("Before: x=%d, y=%d\n", x, y);
    swap_by_reference(&x, &y);
    printf("After : x=%d, y=%d  (swapped)\n", x, y);

    printf("\n=== Recursion ===\n");
    printf("factorial(5) = %d\n", factorial(5));
    printf("fibonacci(7) = %d\n", fibonacci(7));
    printf("Fibonacci sequence (0..7): ");
    for (int i = 0; i <= 7; i++)
        printf("%d ", fibonacci(i));
    printf("\n");

    printf("\n=== Inline & Helper ===\n");
    printf("square(6) = %d\n", square(6));
    printf("my_abs(-42) = %d\n", my_abs(-42));

    /* Function with no parameters / void return already shown via swaps */
    return 0;
}

/*
 * ============================================================================
 * EXPECTED OUTPUT
 * ============================================================================
 * === Function Call & Return ===
 * add(7, 5) = 12
 *
 * === Call by Value ===
 * Before: x=10, y=20
 *   Inside swap_by_value : a=20, b=10
 * After : x=10, y=20  (unchanged)
 *
 * === Call by Reference ===
 * Before: x=10, y=20
 *   Inside swap_by_ref   : *a=20, *b=10
 * After : x=20, y=10  (swapped)
 *
 * === Recursion ===
 * factorial(5) = 120
 * fibonacci(7) = 13
 * Fibonacci sequence (0..7): 0 1 1 2 3 5 8 13
 *
 * === Inline & Helper ===
 * square(6) = 36
 * my_abs(-42) = 42
 * ============================================================================
 */
