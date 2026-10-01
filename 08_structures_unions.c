/*
 * ============================================================================
 *  08_structures_unions.c — Structures, Unions & Bit Fields
 * ============================================================================
 *  Topics covered:
 *    - struct syntax and member access
 *    - Nested structures
 *    - Array of structures
 *    - union (shared memory)
 *    - Bit fields
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 08_structures_unions 08_structures_unions.c
 *  Run     : ./08_structures_unions
 * ============================================================================
 */

#include <stdio.h>
#include <string.h>

/* ---- Simple structure -------------------------------------------------- */
struct Point {
    int x;
    int y;
};

/* ---- Nested structures ------------------------------------------------- */
struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    int id;
    char name[32];
    float salary;
    struct Date joined;   /* nested struct */
};

/* ---- Union: all members share the same memory -------------------------- */
union Data {
    int   i;
    float f;
    char  c;
};

/* ---- Bit fields: pack flags into fewer bits ---------------------------- */
struct StatusFlags {
    unsigned int is_active   : 1;   /* 1 bit  */
    unsigned int is_admin    : 1;   /* 1 bit  */
    unsigned int access_level: 3;   /* 3 bits (0–7) */
    unsigned int reserved    : 3;   /* padding/reserve */
};

int main(void)
{
    /* ---- 1. Basic struct ----------------------------------------------- */
    struct Point p1 = {10, 20};
    struct Point p2;
    p2.x = 5;
    p2.y = 15;

    printf("=== Structures ===\n");
    printf("p1 = (%d, %d)\n", p1.x, p1.y);
    printf("p2 = (%d, %d)\n", p2.x, p2.y);
    printf("sizeof(struct Point) = %zu bytes\n", sizeof(struct Point));

    /* Pointer to struct: use -> operator */
    struct Point *pp = &p1;
    printf("Via pointer: pp->x=%d, pp->y=%d\n", pp->x, pp->y);

    /* ---- 2. Nested structures ------------------------------------------ */
    struct Employee emp;
    emp.id = 101;
    strcpy(emp.name, "Ada Lovelace");
    emp.salary = 95000.0f;
    emp.joined.day = 10;
    emp.joined.month = 12;
    emp.joined.year = 1815;

    printf("\n=== Nested Structure ===\n");
    printf("Employee: %s (ID %d)\n", emp.name, emp.id);
    printf("Salary  : %.2f\n", emp.salary);
    printf("Joined  : %02d/%02d/%04d\n",
           emp.joined.day, emp.joined.month, emp.joined.year);

    /* ---- 3. Array of structures ---------------------------------------- */
    struct Point path[3] = {
        {0, 0},
        {1, 2},
        {3, 4}
    };

    printf("\n=== Array of Structures ===\n");
    for (int i = 0; i < 3; i++)
        printf("path[%d] = (%d, %d)\n", i, path[i].x, path[i].y);

    /* ---- 4. Union ------------------------------------------------------ */
    union Data d;
    printf("\n=== Union (sizeof=%zu) ===\n", sizeof(union Data));

    d.i = 65;
    printf("As int   : %d\n", d.i);
    printf("As char  : %c  (same memory, reinterpreted)\n", d.c);

    d.f = 3.14f;
    printf("As float : %.2f  (overwrites previous bits)\n", d.f);
    /* Reading d.i now is undefined in meaning — bits of the float */

    /* ---- 5. Bit fields ------------------------------------------------- */
    struct StatusFlags flags = {0};
    flags.is_active    = 1;
    flags.is_admin     = 0;
    flags.access_level = 5;

    printf("\n=== Bit Fields ===\n");
    printf("is_active    = %u\n", flags.is_active);
    printf("is_admin     = %u\n", flags.is_admin);
    printf("access_level = %u\n", flags.access_level);
    printf("sizeof(StatusFlags) = %zu bytes\n", sizeof(struct StatusFlags));

    return 0;
}

/*
 * ============================================================================
 * EXPECTED OUTPUT
 * ============================================================================
 * === Structures ===
 * p1 = (10, 20)
 * p2 = (5, 15)
 * sizeof(struct Point) = 8 bytes
 * Via pointer: pp->x=10, pp->y=20
 *
 * === Nested Structure ===
 * Employee: Ada Lovelace (ID 101)
 * Salary  : 95000.00
 * Joined  : 10/12/1815
 *
 * === Array of Structures ===
 * path[0] = (0, 0)
 * path[1] = (1, 2)
 * path[2] = (3, 4)
 *
 * === Union (sizeof=4) ===
 * As int   : 65
 * As char  : A  (same memory, reinterpreted)
 * As float : 3.14  (overwrites previous bits)
 *
 * === Bit Fields ===
 * is_active    = 1
 * is_admin     = 0
 * access_level = 5
 * sizeof(StatusFlags) = 4 bytes   (exact size may vary by ABI)
 * ============================================================================
 */
