/*
 * ============================================================================
 *  04_control_flow.c — Control Flow Statements
 * ============================================================================
 *  Topics covered:
 *    - Decision: if, if-else, if-else if-else, switch
 *    - Loops: for, while, do-while
 *    - Jump: break, continue, goto (use sparingly)
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 04_control_flow 04_control_flow.c
 *  Run     : ./04_control_flow
 * ============================================================================
 */

#include <stdio.h>

int main(void)
{
    /* ---- 1. if / if-else / else-if ------------------------------------- */
    int temperature = 28;

    printf("=== Decision Making ===\n");
    printf("Temperature = %d C\n", temperature);

    if (temperature > 35) {
        printf("It's hot!\n");
    } else if (temperature >= 20) {
        printf("It's pleasant.\n");
    } else {
        printf("It's cold.\n");
    }

    /* ---- 2. switch ----------------------------------------------------- */
    int day = 3;
    printf("\n=== switch (day=%d) ===\n", day);
    switch (day) {
        case 1:  printf("Monday\n");    break;
        case 2:  printf("Tuesday\n");   break;
        case 3:  printf("Wednesday\n"); break;
        case 4:  printf("Thursday\n");  break;
        case 5:  printf("Friday\n");    break;
        case 6:  printf("Saturday\n");  break;
        case 7:  printf("Sunday\n");    break;
        default: printf("Invalid day\n"); break;
    }

    /* Fall-through example (intentional) */
    char grade = 'B';
    printf("\nGrade '%c' feedback: ", grade);
    switch (grade) {
        case 'A':
        case 'B':
            printf("Good job!\n");
            break;
        case 'C':
            printf("Fair.\n");
            break;
        default:
            printf("Needs improvement.\n");
            break;
    }

    /* ---- 3. for loop --------------------------------------------------- */
    printf("\n=== for loop (1..5) ===\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    /* ---- 4. while loop ------------------------------------------------- */
    printf("\n=== while loop (countdown) ===\n");
    int count = 3;
    while (count > 0) {
        printf("%d... ", count);
        count--;
    }
    printf("Go!\n");

    /* ---- 5. do-while (runs at least once) ------------------------------ */
    printf("\n=== do-while ===\n");
    int n = 0;
    do {
        printf("Executed once even though n=%d\n", n);
    } while (n > 0);

    /* ---- 6. break and continue ----------------------------------------- */
    printf("\n=== break & continue ===\n");
    printf("Odd numbers under 10 (skip evens with continue):\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0)
            continue;          /* skip rest of this iteration */
        printf("%d ", i);
    }
    printf("\n");

    printf("Stop at 5 with break: ");
    for (int i = 1; i <= 10; i++) {
        if (i == 5)
            break;             /* exit loop entirely */
        printf("%d ", i);
    }
    printf("\n");

    /* ---- 7. goto (discouraged; shown for completeness) ----------------- */
    printf("\n=== goto (avoid in real code) ===\n");
    int val = 1;
    if (val == 1)
        goto label_found;
    printf("This line is skipped.\n");

label_found:
    printf("Landed at label_found.\n");

    /* Nested loop with labeled break pattern (via flag, preferred over goto) */
    printf("\nMultiplication table snippet (1..3):\n");
    for (int r = 1; r <= 3; r++) {
        for (int c = 1; c <= 3; c++) {
            printf("%2d ", r * c);
        }
        printf("\n");
    }

    return 0;
}

/*
 * ============================================================================
 * EXPECTED OUTPUT
 * ============================================================================
 * === Decision Making ===
 * Temperature = 28 C
 * It's pleasant.
 *
 * === switch (day=3) ===
 * Wednesday
 *
 * Grade 'B' feedback: Good job!
 *
 * === for loop (1..5) ===
 * 1 2 3 4 5
 *
 * === while loop (countdown) ===
 * 3... 2... 1... Go!
 *
 * === do-while ===
 * Executed once even though n=0
 *
 * === break & continue ===
 * Odd numbers under 10 (skip evens with continue):
 * 1 3 5 7 9
 * Stop at 5 with break: 1 2 3 4
 *
 * === goto (avoid in real code) ===
 * Landed at label_found.
 *
 * Multiplication table snippet (1..3):
 *  1  2  3
 *  2  4  6
 *  3  6  9
 * ============================================================================
 */
