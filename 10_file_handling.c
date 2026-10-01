/*
 * ============================================================================
 *  10_file_handling.c — File Handling in C
 * ============================================================================
 *  Topics covered:
 *    - fopen / fclose
 *    - fputc / fgetc
 *    - fprintf / fscanf
 *    - fwrite / fread
 *    - Error handling (NULL checks, feof, ferror)
 *
 *  Compile : gcc -std=c11 -Wall -Wextra -o 10_file_handling 10_file_handling.c
 *  Run     : ./10_file_handling
 *
 *  Side effects: creates sample_demo.txt and sample_demo.bin in CWD
 *                (safe to delete; listed in .gitignore)
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *text_path = "sample_demo.txt";
    const char *bin_path  = "sample_demo.bin";

    /* ---- 1. Write text with fprintf ------------------------------------ */
    FILE *fp = fopen(text_path, "w");
    if (fp == NULL) {
        perror("fopen for write");
        return 1;
    }

    fprintf(fp, "Name: %s\n", "Alice");
    fprintf(fp, "Score: %d\n", 95);
    fprintf(fp, "GPA: %.2f\n", 3.85);
    fclose(fp);
    printf("=== Wrote text file: %s ===\n", text_path);

    /* ---- 2. Read text with fscanf / fgetc ------------------------------ */
    fp = fopen(text_path, "r");
    if (fp == NULL) {
        perror("fopen for read");
        return 1;
    }

    char name[32];
    int score;
    float gpa;
    /* Format must match what we wrote (labels + values) */
    if (fscanf(fp, "Name: %31s\nScore: %d\nGPA: %f\n", name, &score, &gpa) == 3) {
        printf("\n=== fscanf results ===\n");
        printf("Name  = %s\n", name);
        printf("Score = %d\n", score);
        printf("GPA   = %.2f\n", gpa);
    } else {
        fprintf(stderr, "fscanf: unexpected format\n");
    }
    fclose(fp);

    /* Character-by-character read */
    fp = fopen(text_path, "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    printf("\n=== fgetc (raw file contents) ===\n");
    int ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    if (ferror(fp))
        fprintf(stderr, "Read error occurred\n");
    fclose(fp);

    /* ---- 3. fputc: write a short message ------------------------------- */
    fp = fopen(text_path, "a");   /* append */
    if (fp == NULL) {
        perror("fopen append");
        return 1;
    }
    const char *extra = "Status: OK\n";
    for (size_t i = 0; extra[i] != '\0'; i++)
        fputc(extra[i], fp);
    fclose(fp);
    printf("\n=== Appended line with fputc ===\n");

    /* ---- 4. Binary fwrite / fread -------------------------------------- */
    int numbers[] = {10, 20, 30, 40, 50};
    int count = 5;

    fp = fopen(bin_path, "wb");
    if (fp == NULL) {
        perror("fopen binary write");
        return 1;
    }
    size_t written = fwrite(numbers, sizeof(int), (size_t)count, fp);
    fclose(fp);
    printf("\n=== fwrite: wrote %zu ints to %s ===\n", written, bin_path);

    int loaded[5] = {0};
    fp = fopen(bin_path, "rb");
    if (fp == NULL) {
        perror("fopen binary read");
        return 1;
    }
    size_t read_n = fread(loaded, sizeof(int), 5, fp);
    fclose(fp);

    printf("=== fread: read %zu ints: ", read_n);
    for (size_t i = 0; i < read_n; i++)
        printf("%d ", loaded[i]);
    printf("\n");

    /* ---- 5. Error handling demo ---------------------------------------- */
    printf("\n=== Error Handling ===\n");
    FILE *missing = fopen("this_file_does_not_exist_xyz.txt", "r");
    if (missing == NULL) {
        perror("Expected failure");
        printf("Handled missing file gracefully.\n");
    } else {
        fclose(missing);
    }

    printf("\nFile I/O demo completed successfully.\n");
    return 0;
}

/*
 * ============================================================================
 * EXPECTED OUTPUT
 * ============================================================================
 * === Wrote text file: sample_demo.txt ===
 *
 * === fscanf results ===
 * Name  = Alice
 * Score = 95
 * GPA   = 3.85
 *
 * === fgetc (raw file contents) ===
 * Name: Alice
 * Score: 95
 * GPA: 3.85
 *
 * === Appended line with fputc ===
 *
 * === fwrite: wrote 5 ints to sample_demo.bin ===
 * === fread: read 5 ints: 10 20 30 40 50
 *
 * === Error Handling ===
 * Expected failure: No such file or directory
 * Handled missing file gracefully.
 *
 * File I/O demo completed successfully.
 *
 * (perror message text may vary slightly by OS)
 * ============================================================================
 */
