/*
 * ============================================================================
 *  09_dynamic_memory.c — Dynamic Memory Allocation
 * ============================================================================
 *  Topics covered:
 *    - malloc(), calloc(), realloc(), free()
 *    - Checking for allocation failure
 *    - Avoiding memory leaks
 *    - Growing an array dynamically
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 09_dynamic_memory 09_dynamic_memory.c
 *  Run     : ./09_dynamic_memory
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>   /* malloc, calloc, realloc, free */
#include <string.h>

int main(void)
{
    /* ---- 1. malloc: uninitialized block -------------------------------- */
    int n = 5;
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    printf("=== malloc ===\n");
    for (int i = 0; i < n; i++)
        arr[i] = (i + 1) * 10;   /* fill: 10, 20, 30, 40, 50 */

    printf("Allocated %d ints: ", n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    /* ---- 2. calloc: zero-initialized block ----------------------------- */
    int *zeros = (int *)calloc(4, sizeof(int));
    if (zeros == NULL) {
        free(arr);
        fprintf(stderr, "calloc failed\n");
        return 1;
    }

    printf("\n=== calloc (4 ints, zeroed) ===\n");
    for (int i = 0; i < 4; i++)
        printf("%d ", zeros[i]);
    printf("\n");

    /* ---- 3. realloc: grow or shrink ------------------------------------ */
    int new_n = 8;
    int *grown = (int *)realloc(arr, (size_t)new_n * sizeof(int));
    if (grown == NULL) {
        /* Original block still valid if realloc fails */
        free(arr);
        free(zeros);
        fprintf(stderr, "realloc failed\n");
        return 1;
    }
    arr = grown;   /* use the (possibly moved) pointer */

    for (int i = n; i < new_n; i++)
        arr[i] = (i + 1) * 10;   /* fill new slots */

    printf("\n=== realloc (grown to %d) ===\n", new_n);
    for (int i = 0; i < new_n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    /* ---- 4. Dynamic string --------------------------------------------- */
    char *message = (char *)malloc(64);
    if (message == NULL) {
        free(arr);
        free(zeros);
        return 1;
    }
    strcpy(message, "Dynamic");
    strcat(message, " Memory");
    printf("\n=== Dynamic String ===\n");
    printf("message = \"%s\"\n", message);

    /* ---- 5. Memory leak prevention ------------------------------------- */
    /*
     * Rules of thumb:
     *   1. Every successful malloc/calloc/realloc needs a matching free.
     *   2. Set pointer to NULL after free to avoid dangling use.
     *   3. Never free the same pointer twice (double-free = undefined).
     *   4. Do not use a pointer after it has been freed.
     */
    printf("\n=== Cleanup (no leaks) ===\n");
    free(arr);
    arr = NULL;
    free(zeros);
    zeros = NULL;
    free(message);
    message = NULL;
    printf("All heap blocks freed; pointers set to NULL.\n");

    /* Demonstrating that NULL free is safe (no-op) */
    free(NULL);
    printf("free(NULL) is safe (no-op).\n");

    return 0;
}

/*
 * ============================================================================
 * EXPECTED OUTPUT
 * ============================================================================
 * === malloc ===
 * Allocated 5 ints: 10 20 30 40 50
 *
 * === calloc (4 ints, zeroed) ===
 * 0 0 0 0
 *
 * === realloc (grown to 8) ===
 * 10 20 30 40 50 60 70 80
 *
 * === Dynamic String ===
 * message = "Dynamic Memory"
 *
 * === Cleanup (no leaks) ===
 * All heap blocks freed; pointers set to NULL.
 * free(NULL) is safe (no-op).
 * ============================================================================
 */
