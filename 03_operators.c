/*
 * ============================================================================
 *  03_operators.c — Operators & Expressions
 * ============================================================================
 *  Topics covered:
 *    - Arithmetic, Relational, Logical
 *    - Bitwise, Assignment
 *    - Increment / Decrement (++ / --)
 *    - Ternary (?:)
 *    - sizeof and miscellaneous operators
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 03_operators 03_operators.c
 *  Run     : ./03_operators
 * ============================================================================
 */

#include <stdio.h>

int main(void)
{
    int x = 10, y = 3;

    /* ---- 1. Arithmetic operators --------------------------------------- */
    printf("=== Arithmetic (x=%d, y=%d) ===\n", x, y);
    printf("x + y  = %d\n", x + y);
    printf("x - y  = %d\n", x - y);
    printf("x * y  = %d\n", x * y);
    printf("x / y  = %d    /* integer division */\n", x / y);
    printf("x %% y  = %d    /* remainder */\n", x % y);

    /* ---- 2. Relational operators (result is 1=true, 0=false) ----------- */
    printf("\n=== Relational ===\n");
    printf("x == y : %d\n", x == y);
    printf("x != y : %d\n", x != y);
    printf("x >  y : %d\n", x > y);
    printf("x <  y : %d\n", x < y);
    printf("x >= y : %d\n", x >= y);
    printf("x <= y : %d\n", x <= y);

    /* ---- 3. Logical operators ------------------------------------------ */
    int a = 1, b = 0;
    printf("\n=== Logical (a=%d, b=%d) ===\n", a, b);
    printf("a && b : %d   /* AND */\n", a && b);
    printf("a || b : %d   /* OR  */\n", a || b);
    printf("!a     : %d   /* NOT */\n", !a);
    printf("!b     : %d\n", !b);

    /* ---- 4. Bitwise operators ------------------------------------------ */
    unsigned int p = 0x0C;   /* 12 decimal — binary 00001100 */
    unsigned int q = 0x0A;   /* 10 decimal — binary 00001010 */

    printf("\n=== Bitwise (p=%u, q=%u) ===\n", p, q);
    printf("p & q  = %u   /* AND  */\n", p & q);   /* 0b00001000 = 8  */
    printf("p | q  = %u   /* OR   */\n", p | q);   /* 0b00001110 = 14 */
    printf("p ^ q  = %u   /* XOR  */\n", p ^ q);   /* 0b00000110 = 6  */
    printf("~p     = %u   /* NOT (shown as unsigned) */\n", ~p);
    printf("p << 1 = %u   /* left shift  */\n", p << 1);  /* 24 */
    printf("p >> 1 = %u   /* right shift */\n", p >> 1);  /* 6  */

    /* ---- 5. Assignment operators --------------------------------------- */
    int n = 5;
    printf("\n=== Assignment (start n=%d) ===\n", n);
    n += 3;  printf("n += 3  → %d\n", n);   /* 8  */
    n -= 2;  printf("n -= 2  → %d\n", n);   /* 6  */
    n *= 4;  printf("n *= 4  → %d\n", n);   /* 24 */
    n /= 6;  printf("n /= 6  → %d\n", n);   /* 4  */
    n %= 3;  printf("n %%= 3  → %d\n", n);  /* 1  */

    /* ---- 6. Increment / Decrement -------------------------------------- */
    /* Use separate statements — modifying and reading i in the same
     * printf argument list is undefined behavior in C. */
    int i = 5;
    int yielded;
    printf("\n=== Increment / Decrement (start i=%d) ===\n", i);
    yielded = i++;
    printf("i++  (post) returns %d, i is now %d\n", yielded, i);  /* 5, then 6 */
    yielded = ++i;
    printf("++i  (pre)  returns %d, i is now %d\n", yielded, i);  /* 7, then 7 */
    yielded = i--;
    printf("i--  (post) returns %d, i is now %d\n", yielded, i);  /* 7, then 6 */
    yielded = --i;
    printf("--i  (pre)  returns %d, i is now %d\n", yielded, i);  /* 5, then 5 */

    /* ---- 7. Ternary operator ------------------------------------------- */
    int score = 75;
    const char *status = (score >= 60) ? "Pass" : "Fail";
    printf("\n=== Ternary ===\n");
    printf("score=%d → %s\n", score, status);

    int max = (x > y) ? x : y;
    printf("max(%d, %d) = %d\n", x, y, max);

    /* ---- 8. Miscellaneous: sizeof, comma, address-of ------------------- */
    printf("\n=== Miscellaneous ===\n");
    printf("sizeof(int)  = %zu bytes\n", sizeof(int));
    printf("sizeof(x)    = %zu bytes\n", sizeof(x));
    printf("&x (address) = %p\n", (void *)&x);

    /* Comma operator: evaluates left-to-right, yields rightmost value */
    int c;
    c = (x = 1, y = 2, x + y);   /* x=1, y=2, c=3 */
    printf("comma expr   = %d  (x=%d, y=%d)\n", c, x, y);

    return 0;
}

/*
 * ============================================================================
 * EXPECTED OUTPUT
 * ============================================================================
 * === Arithmetic (x=10, y=3) ===
 * x + y  = 13
 * x - y  = 7
 * x * y  = 30
 * x / y  = 3    (integer division)
 * x % y  = 1    (remainder)
 *
 * === Relational ===
 * x == y : 0
 * x != y : 1
 * x >  y : 1
 * x <  y : 0
 * x >= y : 1
 * x <= y : 0
 *
 * === Logical (a=1, b=0) ===
 * a && b : 0   (AND)
 * a || b : 1   (OR)
 * !a     : 0   (NOT)
 * !b     : 1
 *
 * === Bitwise (p=12, q=10) ===
 * p & q  = 8   (AND)
 * p | q  = 14  (OR)
 * p ^ q  = 6   (XOR)
 * ~p     = 4294967283   (NOT as unsigned; depends on width)
 * p << 1 = 24  (left shift)
 * p >> 1 = 6   (right shift)
 *
 * === Assignment (start n=5) ===
 * n += 3  -> 8
 * n -= 2  -> 6
 * n *= 4  -> 24
 * n /= 6  -> 4
 * n %= 3  -> 1
 *
 * === Increment / Decrement (start i=5) ===
 * i++  (post) returns 5, i is now 6
 * ++i  (pre)  returns 7, i is now 7
 * i--  (post) returns 7, i is now 6
 * --i  (pre)  returns 5, i is now 5
 *
 * === Ternary ===
 * score=75 -> Pass
 * max(10, 3) = 10
 *
 * === Miscellaneous ===
 * sizeof(int)  = 4 bytes
 * sizeof(x)    = 4 bytes
 * &x (address) = 0x........   (varies each run)
 * comma expr   = 3  (x=1, y=2)
 * ============================================================================
 */
