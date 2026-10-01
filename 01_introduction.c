/*
 * ============================================================================
 *  01_introduction.c — Introduction to C Programming
 * ============================================================================
 *  Topics covered:
 *    - Structure of a C program
 *    - The main() function
 *    - Header files (#include)
 *    - Basic I/O with printf / scanf
 *    - Comments (single-line and multi-line)
 *    - Compilation overview (mentioned in comments)
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 01_introduction 01_introduction.c
 *  Run     : ./01_introduction   (or 01_introduction.exe on Windows)
 * ============================================================================
 */

#include <stdio.h>   /* Standard Input/Output library — printf, scanf, puts */

/*
 * Every C program needs a main() entry point.
 * Return type int signals an exit status to the OS:
 *   0  → success
 *   non-zero → error
 */
int main(void)
{
    /* ---- 1. Hello, World ----------------------------------------------- */
    printf("Hello, World!\n");
    printf("Welcome to the C Programming Handbook.\n");

    /* ---- 2. Printing different kinds of data --------------------------- */
    int    year   = 1972;          /* C was developed around 1972 by Dennis Ritchie */
    char   grade  = 'A';
    float  pi     = 3.14f;
    double e      = 2.71828;

    printf("\n--- Basic Output Formatting ---\n");
    printf("C language year : %d\n", year);     /* %d  → signed int     */
    printf("Sample grade    : %c\n", grade);    /* %c  → character      */
    printf("Approx. pi      : %.2f\n", pi);     /* %.2f → float, 2 dp   */
    printf("Approx. e       : %.5f\n", e);      /* %.5f → double, 5 dp  */

    /* ---- 3. Reading user input (demo with a fixed value for automation) */
    /*
     * In interactive use you would write:
     *   int age;
     *   printf("Enter your age: ");
     *   scanf("%d", &age);
     *   printf("You are %d years old.\n", age);
     *
     * Below we simulate input so the program runs non-interactively.
     */
    int age = 21;
    printf("\n--- Simulated Input ---\n");
    printf("Assumed age     : %d\n", age);
    printf("You are %d years old.\n", age);

    /* ---- 4. Program structure reminder --------------------------------- */
    puts("\n--- Program Structure ---");
    puts("1. Preprocessor directives  (#include, #define)");
    puts("2. Global declarations      (optional)");
    puts("3. main() function          (required entry point)");
    puts("4. Other functions          (optional helpers)");

    /*
     * Compilation process (high level):
     *   Source (.c) → Preprocessor → Compiler → Assembler → Linker → Executable
     *   Example:  gcc -std=c11 -Wall -o prog prog.c
     */

    return 0;   /* Indicate successful termination */
}

/*
 * ============================================================================
 * EXPECTED OUTPUT
 * ============================================================================
 * Hello, World!
 * Welcome to the C Programming Handbook.
 *
 * --- Basic Output Formatting ---
 * C language year : 1972
 * Sample grade    : A
 * Approx. pi      : 3.14
 * Approx. e       : 2.71828
 *
 * --- Simulated Input ---
 * Assumed age     : 21
 * You are 21 years old.
 *
 * --- Program Structure ---
 * 1. Preprocessor directives  (#include, #define)
 * 2. Global declarations      (optional)
 * 3. main() function          (required entry point)
 * 4. Other functions          (optional helpers)
 * ============================================================================
 */
