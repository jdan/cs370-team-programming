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

#define SIZE 100

int main(int argc, char **argv) {
    int i, j, k, nPoints, cases, totalArea, area;
    int x, y, z;
    int u, v, w;
    int badBlockIndex;

    /* Read in the number of cases */
    scanf("%d", &cases);

    /* Allocate space for the array:
       Size of Number of Points  */
    int ***points;
    points = (int***)malloc(SIZE * sizeof(int**));
    for (j = 0; j < SIZE; j++) {
      points[j] = (int**)malloc(SIZE * sizeof(int*));
      for (k = 0; k < SIZE; k++) {
        points[j][k] = (int*)malloc(SIZE * sizeof(int));
      }
    }

    for (i = 0; i < cases; i++) {
      /* Read in the number of points */
      scanf("%d", &nPoints);

      /* Zero out points */
      for (u = 0; u < SIZE; u++) {
        for (v = 0; v < SIZE; v++) {
          for (w = 0; w < SIZE; w++) {
            points[u][v][w] = 0;
          }
        }
      }

      /* The surface area of one block is 6 */
      totalArea = 6;

      /* Index to keep track of a block that doesn't
         share a face with another block */
      badBlockIndex = 0;

      /* Store first point */
      scanf("%d,%d,%d", &x, &y, &z);
      points[x][y][z] = 1;

      /* Load the points */
      for (j = 1; j < nPoints; j++) {
        scanf("%d,%d,%d", &x, &y, &z);
        points[x][y][z] = 1;

        area = 6;

        /* Check for neighbors - is there a better way to do this?
           Subtract 2 to surface area for every neighbor */
        if (x < 99 && points[x+1][y][z] == 1) {
          area -= 2;
        }
        if (x > 0 && points[x-1][y][z] == 1) {
          area -= 2;
        }
        if (y < 99 && points[x][y+1][z] == 1) {
          area -= 2;
        }
        if (y > 0 && points[x][y-1][z] == 1) {
          area -= 2;
        }
        if (z < 99 && points[x][y][z+1] == 1) {
          area -= 2;
        }
        if (z > 0 && points[x][y][z-1] == 1) {
          area -= 2;
        }

        /**
         * If our surface area is still 6, we didn't find a match
         * Also make sure we haven't set badBlockIndex yet
         */
        if (area == 6 && badBlockIndex == 0) {
          badBlockIndex = j;
        }

        //printf("%d\n", area);
        totalArea += area;
      }

      if (!badBlockIndex) {
        printf("%d %d\n", i+1, totalArea);
      } else {
        printf("%d NO %d\n", i+1, badBlockIndex);
      }
    }

    /* free points (and each point) */
}
