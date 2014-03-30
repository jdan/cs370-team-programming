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

typedef struct point_s {
  int x;
  int y;
  int z;
} t_point;

t_point *new_point(int x, int y, int z) {
  t_point* point = (t_point*)malloc(sizeof(t_point));

  point->x = x;
  point->y = y;
  point->z = z;

  return point;
}

int main(int argc, char **argv) {
    int i, j, k, nPoints, cases;
    int x, y, z;
    t_point** points;

    /* Read in the number of cases */
    scanf("%d", &cases);

    for (i = 0; i < cases; i++) {
      /* Read in the number of points */
      scanf("%d", &nPoints);

      points = (t_point**)malloc(nPoints * sizeof(t_point*));

      /* Load the points */
      for (j = 0; j < nPoints; j++) {
        scanf("%d,%d,%d", &x, &y, &z);
        points[j] = new_point(x, y, z);
      }

      for (j = 0; j < nPoints; j++) {
        printf("%d-%d-%d ", points[j]->x, points[j]->y, points[j]->z);
      }
      printf("\n");
    }

    /* free points (and each point) */
}
