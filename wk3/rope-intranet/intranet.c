/**
 * Rope Intranet
 * Google CodeJam Round 1C (201)
 * https://code.google.com/codejam/contest/619102/dashboard#s=p0
 *
 * Jordan Scales <scalesjordan@gmail.com>
 * for CS370
 * 5 Mar 2014
 *
 * This is an improved solution using a modified insertion sort
 */

#include <stdio.h>
#include <stdlib.h>

int intersections(int *, int *, int);
int intersectionsFast(int *, int *, int);

void insert(int *, int, int, int);
int binaryInsert(int *, int, int);
int binaryInsertHelper(int *, int, int, int, int);

int main(int argc, char **argv) {
  int i, j, n;
  int cases, numWires;
  int *wiresL, *wiresR;

  scanf("%d", &cases);

  for (i = 0; i < cases; i++) {
    scanf("%d", &numWires);

    wiresL = (int*)malloc(numWires * sizeof(int));
    wiresR = (int*)malloc(numWires * sizeof(int));

    for (j = 0; j < numWires; j++) {
      // Left point of wire
      scanf("%d", &n);
      wiresL[j] = n;

      // Right point of wire
      scanf("%d", &n);
      wiresR[j] = n;
    }

    //printf("Case #%d: %d\n", i+1, intersectionsFast(wiresL, wiresR, numWires));
    printf("Case #%d: %d\n", i+1, intersections(wiresL, wiresR, numWires));

    free(wiresL);
    free(wiresR);
  }

  return 1;
}


/**
 * Computes the intersctions of wires given in two arrays
 * - A list of positions on the left side
 * - A list of positions on the right side
 */
int intersections(int *left, int *right, int n) {
  int intersections = 0, i, j;

  for (i = 0; i < n; i++) {
    for (j = i+1; j < n; j++) {
      if ((left[i] > left[j] && right[i] < right[j]) ||
          (left[i] < left[j] && right[i] > right[j])) {
        intersections++;
      }
    }
  }

  return intersections;
}


/**
 * Computes intersections using a O(log n) insertion method
 */
int intersectionsFast(int *left, int *right, int n) {
  int i, intersections, leftPos, rightPos;
  int *leftSorted, *rightSorted;

  leftSorted = (int*)malloc(n * sizeof(int));
  rightSorted = (int*)malloc(n * sizeof(int));

  /* Place initial values */
  leftSorted[0] = left[0];
  rightSorted[0] = right[0];

  for (i = 1; i < n; i++) {
    leftPos = binaryInsert(leftSorted, left[i], i);
    rightPos = binaryInsert(rightSorted, right[i], i);

    if (leftPos > rightPos) {
      intersections += leftPos - rightPos;
    } else {
      intersections += rightPos - leftPos;
    }
  }

  free(leftSorted);
  free(rightSorted);

  return intersections;
}


/**
 * Inserts an item into a sorted list after first computing its position
 * using a binary search O(log n).
 *
 * Returns the index the item was inserted at
 */
int binaryInsert(int *arr, int item, int size) {
  return binaryInsertHelper(arr, item, size, 0, size);
}


/**
 * Helper method for binaryInsert that includes two indices
 */
int binaryInsertHelper(int *arr, int item, int size, int a, int b) {
  if (a == b) {
    insert(arr, item, a, size);
    return a;
  } else {
    int m = (a + b) / 2;

    if (item >= arr[m]) {
      return binaryInsertHelper(arr, item, size, m+1, b);
    } else {
      return binaryInsertHelper(arr, item, size, a, m);
    }
  }
}


/**
 * Inserts an item into an array and shifts the remaining items forward
 * Given an array, item, index to insert at, and the size of the list
 */
void insert(int *arr, int item, int i, int size) {
  int j;

  for (j = size-1; j >= i; j--) {
    arr[j+1] = arr[j];
  }

  arr[i] = item;
}

