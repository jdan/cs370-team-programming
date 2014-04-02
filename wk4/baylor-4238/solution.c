/**
 * Baylor 4238 Solution
 * see README.md
 *
 * Natalie Barillaro, Jordan Scales
 * for CS370 (Spring 2014)
 * 30 Mar 2014
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int i, j, k, nPoints, cases, sArea;
    int x, y, z;
    int badBlockIndex, goodBlockFound;
 
    /* Read in the number of cases */
    scanf("%d", &cases);

    for (i = 0; i < cases; i++) {
      /* Read in the number of points */
      scanf("%d", &nPoints);

      /* Allocate space for the array:
         Size of Number of Points  */
      int ***points;
      points = (int***)malloc(nPoints * sizeof(int**));
      for (j = 0; j < nPoints; j++) {
        points[j] = (int**)malloc(nPoints * sizeof(int*));
        for (k = 0; k < nPoints; k++) {
          points[j][k] = (int*)malloc(nPoints * sizeof(int));
        }
      }

      /* The surface area of one block is 6 */
      sArea = 6;

      /* Index to keep track of a block that doesn't
         share a face with another block */
      badBlockIndex = 2;

      /* Store first point */
      scanf("%d,%d,%d", &x, &y, &z);
      points[x][y][z] = 1;

      /* Load the points */
      for (j = 1; j < nPoints; j++) {
        scanf("%d,%d,%d", &x, &y, &z);
        points[x][y][z] = 1;

        sArea += 6;

        goodBlockFound = 0;

        /* Check for neighbors - is there a better way to do this?
           Subtract 2 to surface area for every neighbor */
        if (points[x+1][y][z] == 1) {
          goodBlockFound = 1;
          sArea -= 2;
        }
        if (points[x-1][y][z] == 1) {
          goodBlockFound = 1;
          sArea -= 2;
        }
        if (points[x][y+1][z] == 1) {
          goodBlockFound = 1;
          sArea -= 2;
        }
        if (points[x][y-1][z] == 1) {
          goodBlockFound = 1;
          sArea -= 2;
        }
        if (points[x][y][z+1] == 1) {
          goodBlockFound = 1;
          sArea -= 2;
        }
        if (points[x][y][z-1] == 1) {
          goodBlockFound = 1;
          sArea -= 2;
        }
        if (!goodBlockFound)
          break;

        /* Increase badBlockIndex */
        badBlockIndex++;
      }

      if (goodBlockFound) {
        printf("%d %d", i+1, sArea);
      }

      else {
        printf("%d NO %d", i+1, badBlockIndex);
      }

      printf("\n");

    }

    /* free points (and each point) */
}