/*
 * ============================================================================
 *  02_variables_datatypes.c — Variables, Data Types & Type Casting
 * ============================================================================
 *  Topics covered:
 *    - Basic types: int, float, char, double, void
 *    - Type modifiers: short, long, signed, unsigned
 *    - sizeof operator for type sizes
 *    - Implicit and explicit type casting
 *    - Constants (const, #define)
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 02_variables_datatypes 02_variables_datatypes.c
 *  Run     : ./02_variables_datatypes
 * ============================================================================
 */

#include <stdio.h>
#include <limits.h>   /* INT_MAX, INT_MIN, etc. */
#include <float.h>    /* FLT_MAX, DBL_MAX, etc. */

int main(void)
{
    /* ---- 1. Basic data types ------------------------------------------- */
    int    count   = 42;
    float  price   = 19.99f;
    double precise = 3.141592653589793;
    char   letter  = 'C';
    char   name[]  = "C Handbook";   /* null-terminated string */

    printf("=== Basic Data Types ===\n");
    printf("int    count   = %d\n", count);
    printf("float  price   = %.2f\n", price);
    printf("double precise = %.15f\n", precise);
    printf("char   letter  = %c\n", letter);
    printf("string name    = %s\n", name);

    /* ---- 2. Type sizes (platform-dependent; typical 64-bit shown) ------ */
    printf("\n=== sizeof Results (bytes) ===\n");
    printf("sizeof(char)   = %zu\n", sizeof(char));
    printf("sizeof(short)  = %zu\n", sizeof(short));
    printf("sizeof(int)    = %zu\n", sizeof(int));
    printf("sizeof(long)   = %zu\n", sizeof(long));
    printf("sizeof(float)  = %zu\n", sizeof(float));
    printf("sizeof(double) = %zu\n", sizeof(double));
    printf("sizeof(void *) = %zu\n", sizeof(void *));

    /* ---- 3. Type modifiers --------------------------------------------- */
    short          s  = 32000;
    long           l  = 1000000L;
    long long      ll = 9000000000LL;
    unsigned int   u  = 4000000000U;
    signed char    sc = -100;
    unsigned char  uc = 200;

    printf("\n=== Type Modifiers ===\n");
    printf("short         = %d\n", s);
    printf("long          = %ld\n", l);
    printf("long long     = %lld\n", ll);
    printf("unsigned int  = %u\n", u);
    printf("signed char   = %d\n", sc);
    printf("unsigned char = %u\n", uc);

    /* ---- 4. Limits ----------------------------------------------------- */
    printf("\n=== Type Limits ===\n");
    printf("INT_MIN  = %d\n", INT_MIN);
    printf("INT_MAX  = %d\n", INT_MAX);
    printf("UINT_MAX = %u\n", UINT_MAX);
    printf("FLT_MAX  = %e\n", FLT_MAX);

    /* ---- 5. Constants -------------------------------------------------- */
    const int DAYS_IN_WEEK = 7;          /* read-only variable */
    #define PI_APPROX 3.14159            /* preprocessor constant */

    printf("\n=== Constants ===\n");
    printf("DAYS_IN_WEEK = %d\n", DAYS_IN_WEEK);
    printf("PI_APPROX    = %f\n", PI_APPROX);

    /* ---- 6. Type casting ----------------------------------------------- */
    int    a = 7;
    int    b = 2;
    double result_implicit;
    double result_explicit;

    /* Implicit: integer division first, then promotion (truncates!) */
    result_implicit = a / b;             /* 7/2 → 3  (int), then → 3.0 */

    /* Explicit: cast before division to get floating-point result */
    result_explicit = (double)a / b;     /* 7.0/2 → 3.5 */

    printf("\n=== Type Casting ===\n");
    printf("Implicit  (a/b)        = %.1f   /* WRONG for real division */\n",
           result_implicit);
    printf("Explicit  ((double)a/b)= %.1f   /* correct */\n",
           result_explicit);

    /* Narrowing cast (possible data loss) */
    double big = 123.987;
    int    truncated = (int)big;         /* fractional part discarded */
    printf("Cast (int)123.987      = %d\n", truncated);

    /* void is used as return type when a function returns nothing,
     * and as void * for generic pointers — demonstrated elsewhere. */
    printf("\n(void type: used for functions with no return value)\n");

    return 0;
}

/*
 * ============================================================================
 * EXPECTED OUTPUT  (sizes may vary by platform; typical 64-bit Linux/Windows)
 * ============================================================================
 * === Basic Data Types ===
 * int    count   = 42
 * float  price   = 19.99
 * double precise = 3.141592653589793
 * char   letter  = C
 * string name    = C Handbook
 *
 * === sizeof Results (bytes) ===
 * sizeof(char)   = 1
 * sizeof(short)  = 2
 * sizeof(int)    = 4
 * sizeof(long)   = 4   (or 8 on many 64-bit Unix systems)
 * sizeof(float)  = 4
 * sizeof(double) = 8
 * sizeof(void *) = 8
 *
 * === Type Modifiers ===
 * short         = 32000
 * long          = 1000000
 * long long     = 9000000000
 * unsigned int  = 4000000000
 * signed char   = -100
 * unsigned char = 200
 *
 * === Type Limits ===
 * INT_MIN  = -2147483648
 * INT_MAX  = 2147483647
 * UINT_MAX = 4294967295
 * FLT_MAX  = 3.402823e+38
 *
 * === Constants ===
 * DAYS_IN_WEEK = 7
 * PI_APPROX    = 3.141590
 *
 * === Type Casting ===
 * Implicit  (a/b)        = 3.0   (WRONG for real division)
 * Explicit  ((double)a/b)= 3.5   (correct)
 * Cast (int)123.987      = 123
 *
 * (void type: used for functions with no return value)
 * ============================================================================
 */
