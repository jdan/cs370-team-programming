/*
* Jack Farzan & Natalie Barillaro & Jordan Scales
* problem 195 in c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD_SZ 10

/**
 * The following two methods are based off of the code provided here:
 * http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
 */

/* Function to swap values at two pointers */
void swap (char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes five parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string.
   4. Pointer to array to populate with permutations
   5. Pointer to index for permutations array */
void permute(char *a, int i, int n, char **permutations, int *index) {
    int j, k;

    if (i == n) {
        /* Check if it's unique */
        for (k = 0; k < *index; k++) {
            if (strcmp(a, permutations[k]) == 0) {
                return;
            }
        }

        permutations[*index] = strdup(a);
        *index += 1;
    } else {
        for (j = i; j <= n; j++) {
            swap((a+i), (a+j));
            permute(a, i+1, n, permutations, index);
            swap((a+i), (a+j)); /** backtrack */
        }
    }
}

/**
 * Computes the factorial of a given n
 */
int factorial(int n) {
    int i, result = 1;

    for (i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int compfunc(const void *a, const void *b) {
    return strcmp (*(const char **) a, *(const char **)b);
}

int main(int argc, char **argv) {
    char *word;
    char **permutations;
    int n, i, j, index;

    word = (char*)malloc(WORD_SZ * sizeof(char));

    /* Read first number */
    scanf("%d\n", &n);

    for (i = 0; i < n; i++) {
        scanf("%s\n", word);

        permutations = (char**)malloc(factorial(strlen(word)) * sizeof(char*));
        index = 0;

        permute(word, 0, strlen(word) - 1, permutations, &index);

        /* sort and unique */
        qsort(permutations, index, sizeof(char*), compfunc);

        for (j = 0; j < index; j++) {
            printf("%s\n", permutations[j]);
        }
    }
}

