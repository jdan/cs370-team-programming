#include <stdio.h>
#include <stdlib.h>

void optimizeBins();
int transferBottles(int**, int, int, int);

int main(int argc, char **argv) {
    int **bins;
    int i;

    bins = (int**)malloc(3 * sizeof(int*));
    for (i = 0; i < 3; i++) {
        bins[i] = (int*)malloc(3 * sizeof(int));
    }

    while (scanf("%d %d %d %d %d %d %d %d %d\n",
        bins[0], bins[0]+1, bins[0]+2,
        bins[1], bins[1]+1, bins[1]+2,
        bins[2], bins[2]+1, bins[2]+2) == 9) {

        optimizeBins(bins);
    }
}

void optimizeBins(int **bins) {
    int minMovements, movements, i;
    char *minRepresentation;

    int permutations[][3] = {
        { 0, 2, 1 },
        { 0, 1, 2 },
        { 2, 0, 1 },
        { 2, 1, 0 },
        { 1, 0, 2 },
        { 1, 2, 0 }
    };

    char representations[][6] = {
        "BCG", "BGC", "CBG", "CGB", "GBC", "GCB"
    };

    minMovements = transferBottles(bins, 0, 2, 1);
    minRepresentation = "BCG";

    for (i = 1; i < 6; i++) {
        movements = transferBottles(
            bins, permutations[i][0], permutations[i][1], permutations[i][2]);

        if (movements < minMovements) {
            minMovements = movements;
            minRepresentation = representations[i];
        }
    }

    printf("%s %d\n", minRepresentation, minMovements);
}

int transferBottles(int **bins, int a, int b, int c) {
    int movements = 0;
    int i, j;

    // Transfer bottles into the first bin
    movements += bins[1][a] + bins[2][a];

    // Transfer bottles into the second bin
    movements += bins[0][b] + bins[2][b];

    // Transfer bottles into the third bin
    movements += bins[0][c] + bins[1][c];

    return movements;
}
