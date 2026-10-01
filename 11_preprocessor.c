/*
 * ============================================================================
 *  11_preprocessor.c — Preprocessor Directives
 * ============================================================================
 *  Topics covered:
 *    - #define macros (object-like and function-like)
 *    - #include
 *    - Conditional compilation: #ifdef, #ifndef, #if, #elif, #else, #endif
 *    - #undef
 *    - Stringification and token pasting (brief)
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 11_preprocessor 11_preprocessor.c
 *  Optional: gcc -DDEBUG_MODE -std=c11 -Wall -o 11_preprocessor 11_preprocessor.c
 *  Run     : ./11_preprocessor
 * ============================================================================
 */

#include <stdio.h>    /* #include pulls in declarations from a header */

/* ---- Object-like macros ------------------------------------------------ */
#define PI          3.14159
#define APP_NAME    "C Handbook"
#define MAX(a, b)   ((a) > (b) ? (a) : (b))   /* always parenthesize! */
#define SQUARE(x)   ((x) * (x))

/* ---- Conditional compilation ------------------------------------------- */
/* Define DEBUG_MODE here for demo; or pass -DDEBUG_MODE on the command line */
#define DEBUG_MODE

#ifdef DEBUG_MODE
    #define LOG(msg)  printf("[DEBUG] %s\n", msg)
#else
    #define LOG(msg)  ((void)0)   /* no-op when not debugging */
#endif

#ifndef VERSION
    #define VERSION "1.0.0"
#endif

#if defined(DEBUG_MODE) && !defined(NDEBUG)
    #define BUILD_TYPE "Debug"
#else
    #define BUILD_TYPE "Release"
#endif

/* Feature toggle example */
#define FEATURE_EXPERIMENTAL 0

#if FEATURE_EXPERIMENTAL
    static void experimental(void) { printf("Experimental feature ON\n"); }
#else
    static void experimental(void) { printf("Experimental feature OFF\n"); }
#endif

/* Token pasting & stringification (advanced macros) */
#define STR(x)   #x                 /* turns token into string literal */
#define CONCAT(a, b)  a##b          /* glues tokens together */

int main(void)
{
    printf("=== Preprocessor Demo ===\n");
    printf("App     : %s\n", APP_NAME);
    printf("Version : %s\n", VERSION);
    printf("Build   : %s\n", BUILD_TYPE);
    printf("PI      : %f\n", PI);

    printf("\n=== Function-like Macros ===\n");
    printf("MAX(10, 25)  = %d\n", MAX(10, 25));
    printf("SQUARE(5)    = %d\n", SQUARE(5));
    printf("SQUARE(2+1)  = %d  /* safe due to parentheses */\n", SQUARE(2 + 1));

    printf("\n=== Conditional LOG ===\n");
    LOG("Program started");
    LOG("Computing values");

    printf("\n=== Feature Toggle ===\n");
    experimental();

    printf("\n=== Stringification ===\n");
    printf("STR(Hello) → %s\n", STR(Hello));

    int CONCAT(var, 1) = 42;   /* creates identifier var1 */
    printf("CONCAT(var,1) as var1 = %d\n", var1);

    /* #undef removes a macro definition */
#undef PI
    /* After #undef, PI is no longer a macro; we can use a variable named PI */
    const double PI = 3.1415926535;
    printf("\nAfter #undef, variable PI = %.10f\n", PI);

    printf("\nPreprocessor demo complete.\n");
    return 0;
}

/*
 * ============================================================================
 * EXPECTED OUTPUT
 * ============================================================================
 * === Preprocessor Demo ===
 * App     : C Handbook
 * Version : 1.0.0
 * Build   : Debug
 * PI      : 3.141590
 *
 * === Function-like Macros ===
 * MAX(10, 25)  = 25
 * SQUARE(5)    = 25
 * SQUARE(2+1)  = 9  (safe due to parentheses)
 *
 * === Conditional LOG ===
 * [DEBUG] Program started
 * [DEBUG] Computing values
 *
 * === Feature Toggle ===
 * Experimental feature OFF
 *
 * === Stringification ===
 * STR(Hello) -> Hello
 * CONCAT(var,1) as var1 = 42
 *
 * After undef, variable PI = 3.1415926535
 *
 * Preprocessor demo complete.
 * ============================================================================
 */
