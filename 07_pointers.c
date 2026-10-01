/*
 * ============================================================================
 *  07_pointers.c — Pointers
 * ============================================================================
 *  Topics covered:
 *    - Pointer basics & dereferencing
 *    - Pointer arithmetic
 *    - Double pointers
 *    - Pointers with arrays
 *    - Pointers with functions (callbacks / pass-by-pointer)
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 07_pointers 07_pointers.c
 *  Run     : ./07_pointers
 * ============================================================================
 */

#include <stdio.h>

/* Function that takes a pointer and doubles the value */
void double_value(int *p)
{
    *p = (*p) * 2;
}

/* Callback-style: apply an operation via function pointer */
int apply(int a, int b, int (*op)(int, int))
{
    return op(a, b);
}

int multiply(int a, int b) { return a * b; }
int subtract(int a, int b) { return a - b; }

int main(void)
{
    /* ---- 1. Pointer basics --------------------------------------------- */
    int num = 42;
    int *ptr = &num;     /* ptr stores the address of num */

    printf("=== Pointer Basics ===\n");
    printf("num        = %d\n", num);
    printf("&num       = %p\n", (void *)&num);
    printf("ptr        = %p  (same as &num)\n", (void *)ptr);
    printf("*ptr       = %d  (dereference)\n", *ptr);

    *ptr = 100;          /* modify num through the pointer */
    printf("After *ptr = 100 → num = %d\n", num);

    /* ---- 2. Pointer arithmetic ----------------------------------------- */
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;        /* points to first element */

    printf("\n=== Pointer Arithmetic ===\n");
    printf("*(p+0)=%d  *(p+1)=%d  *(p+2)=%d\n", *(p + 0), *(p + 1), *(p + 2));

    printf("Walking with p++: ");
    p = arr;
    for (int i = 0; i < 5; i++) {
        printf("%d ", *p);
        p++;             /* advance by sizeof(int) bytes */
    }
    printf("\n");

    /* ---- 3. Pointers and arrays ---------------------------------------- */
    printf("\n=== Pointers with Arrays ===\n");
    printf("arr[i] vs *(arr+i):\n");
    for (int i = 0; i < 5; i++)
        printf("  arr[%d]=%d  *(arr+%d)=%d\n", i, arr[i], i, *(arr + i));

    /* ---- 4. Double pointers -------------------------------------------- */
    int value = 7;
    int *single = &value;
    int **double_ptr = &single;   /* pointer to pointer */

    printf("\n=== Double Pointers ===\n");
    printf("value         = %d\n", value);
    printf("*single       = %d\n", *single);
    printf("**double_ptr  = %d\n", **double_ptr);

    **double_ptr = 99;
    printf("After **double_ptr=99 → value = %d\n", value);

    /* ---- 5. Pointers with functions ------------------------------------ */
    printf("\n=== Pointers with Functions ===\n");
    int x = 15;
    printf("Before double_value: x=%d\n", x);
    double_value(&x);
    printf("After  double_value: x=%d\n", x);

    printf("apply(6, 7, multiply) = %d\n", apply(6, 7, multiply));
    printf("apply(6, 7, subtract) = %d\n", apply(6, 7, subtract));

    /* ---- 6. NULL pointer safety ---------------------------------------- */
    int *null_ptr = NULL;
    printf("\n=== NULL Check ===\n");
    if (null_ptr == NULL)
        printf("null_ptr is NULL — safe to skip dereference.\n");

    return 0;
}

/*
 * ============================================================================
 * EXPECTED OUTPUT  (addresses will vary)
 * ============================================================================
 * === Pointer Basics ===
 * num        = 42
 * &num       = 0x...
 * ptr        = 0x...  (same as &num)
 * *ptr       = 42  (dereference)
 * After *ptr = 100 → num = 100
 *
 * === Pointer Arithmetic ===
 * *(p+0)=10  *(p+1)=20  *(p+2)=30
 * Walking with p++: 10 20 30 40 50
 *
 * === Pointers with Arrays ===
 * arr[i] vs *(arr+i):
 *   arr[0]=10  *(arr+0)=10
 *   arr[1]=20  *(arr+1)=20
 *   arr[2]=30  *(arr+2)=30
 *   arr[3]=40  *(arr+3)=40
 *   arr[4]=50  *(arr+4)=50
 *
 * === Double Pointers ===
 * value         = 7
 * *single       = 7
 * **double_ptr  = 7
 * After **double_ptr=99 → value = 99
 *
 * === Pointers with Functions ===
 * Before double_value: x=15
 * After  double_value: x=30
 * apply(6, 7, multiply) = 42
 * apply(6, 7, subtract) = -1
 *
 * === NULL Check ===
 * null_ptr is NULL — safe to skip dereference.
 * ============================================================================
 */
