/*
 * ============================================================================
 *  06_arrays_strings.c — Arrays & Strings
 * ============================================================================
 *  Topics covered:
 *    - 1D and 2D arrays, traversal, manipulation
 *    - String literals and character arrays
 *    - string.h: strlen, strcpy, strcat, strcmp
 *    - Manual string handling
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 06_arrays_strings 06_arrays_strings.c
 *  Run     : ./06_arrays_strings
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>   /* strlen, strcpy, strcat, strcmp */

int main(void)
{
    /* ---- 1. One-dimensional arrays ------------------------------------- */
    int scores[5] = {85, 90, 78, 92, 88};
    int sum = 0;

    printf("=== 1D Array ===\n");
    printf("Scores: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", scores[i]);
        sum += scores[i];
    }
    printf("\nSum = %d, Average = %.1f\n", sum, sum / 5.0);

    /* Find max */
    int max = scores[0];
    for (int i = 1; i < 5; i++) {
        if (scores[i] > max)
            max = scores[i];
    }
    printf("Maximum score = %d\n", max);

    /* ---- 2. Two-dimensional arrays ------------------------------------- */
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("\n=== 2D Array (3x3 matrix) ===\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            printf("%d ", matrix[r][c]);
        }
        printf("\n");
    }

    /* Diagonal sum */
    int diag = 0;
    for (int i = 0; i < 3; i++)
        diag += matrix[i][i];
    printf("Main diagonal sum = %d\n", diag);

    /* ---- 3. Strings as char arrays ------------------------------------- */
    char greeting[] = "Hello";          /* auto size includes '\0' */
    char name[32]   = "World";

    printf("\n=== Strings ===\n");
    printf("greeting = \"%s\" (length %zu)\n", greeting, strlen(greeting));
    printf("name     = \"%s\" (length %zu)\n", name, strlen(name));

    /* ---- 4. string.h functions ----------------------------------------- */
    char dest[64];
    char src[] = "C Programming";

    strcpy(dest, src);                  /* copy src → dest */
    printf("\nstrcpy  → dest = \"%s\"\n", dest);

    strcat(dest, " Handbook");          /* append */
    printf("strcat  → dest = \"%s\"\n", dest);

    printf("strlen  → %zu\n", strlen(dest));

    /* strcmp: 0 if equal, <0 if s1<s2, >0 if s1>s2 */
    printf("strcmp(\"apple\",\"apple\") = %d\n", strcmp("apple", "apple"));
    printf("strcmp(\"apple\",\"banana\")= %d\n", strcmp("apple", "banana"));
    printf("strcmp(\"banana\",\"apple\")= %d\n", strcmp("banana", "apple"));

    /* ---- 5. Manual string length (without strlen) ---------------------- */
    const char *msg = "Pointers";
    int len = 0;
    while (msg[len] != '\0')
        len++;
    printf("\nManual length of \"%s\" = %d\n", msg, len);

    /* ---- 6. Character-by-character print ------------------------------- */
    printf("Characters in greeting: ");
    for (int i = 0; greeting[i] != '\0'; i++)
        printf("[%c] ", greeting[i]);
    printf("\n");

    /* ---- 7. Array manipulation: reverse in place ----------------------- */
    int nums[] = {1, 2, 3, 4, 5};
    int n = 5;
    for (int i = 0; i < n / 2; i++) {
        int tmp = nums[i];
        nums[i] = nums[n - 1 - i];
        nums[n - 1 - i] = tmp;
    }
    printf("\nReversed array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}

/*
 * ============================================================================
 * EXPECTED OUTPUT
 * ============================================================================
 * === 1D Array ===
 * Scores: 85 90 78 92 88
 * Sum = 433, Average = 86.6
 * Maximum score = 92
 *
 * === 2D Array (3x3 matrix) ===
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * Main diagonal sum = 15
 *
 * === Strings ===
 * greeting = "Hello" (length 5)
 * name     = "World" (length 5)
 *
 * strcpy  → dest = "C Programming"
 * strcat  → dest = "C Programming Handbook"
 * strlen  → 22
 * strcmp("apple","apple") = 0
 * strcmp("apple","banana")= -1   (exact non-zero may vary; typically negative)
 * strcmp("banana","apple")= 1    (exact non-zero may vary; typically positive)
 *
 * Manual length of "Pointers" = 8
 * Characters in greeting: [H] [e] [l] [l] [o]
 *
 * Reversed array: 5 4 3 2 1
 * ============================================================================
 */
