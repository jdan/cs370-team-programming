/**
 * UVa Problem 111
 * Natalie Barillaro and Jordan Scales
 * 4 Mar 2014
 */

#include <cstdio>
#include <iostream>

using namespace std;

int longestIncreasingSubsequence(int*, int);

int main() {
  int n, i, x;
  int *order, *submission;

  /* Read n first! */
  cin >> n;

  order = new int[n+1];
  submission = new int[n+1];

  /* Establish an "order" array */
  for (i = 1; i < n+1; i++) {
    cin >> x;
    order[i] = x;
  }

  /* Loop to read individual lines */
  while (cin >> x) {

    /* Determine if we read an EOF, otherwise set the first position */
    if (cin.eof()) break;
    submission[x] = order[1];

    /**
     * Loop i from 1 to n (including)
     * Read in the next number `x`
     * The `x` slot of `submission` corresponds to the value in the `i` slot
     *   of our original `order` array
     */
    for(i = 2; i < n+1; i++) {
      cin >> x;
      submission[x] = order[i];
    }

    /* Compute the LIS and print */
    cout << longestIncreasingSubsequence(submission+1, n) << endl;
  }
}

/**
 * Computes the LIS of a given array of integers
 * Pass this an array and a length
 */
int longestIncreasingSubsequence(int* arr, int n) {
  /* This is what we will use DP on */
  int *lis = new int[n];

  /* Counters and a max */
  int i, j, max;

  /* Initialize LIS values - each index starts with 1! */
  for (i = 0; i < n; i++) {
    lis[i] = 1;
  }

  /**
   * Bottoms up
   * Give ourselves two counters, i and j (j < i) and traverse thru lis[]
   * If we satisfy both of the following conditions
   * - arr[i] > arr[j]      (i -> j is increasing)
   * - lis[j] + 1 > lis[i]  (the LIS value at i should reflect j's (+ 1))
   * Then we set the value of lis[i] to lis[j] + 1, since at this point
   *   lis[i] should be a step up from lis[j]
   */
  for (i = 1; i < n; i++) {
    for (j = 0; j < i; j++) {
      if (arr[i] > arr[j] && lis[j] + 1 > lis[i]) {
        lis[i] = lis[j] + 1;
      }
    }
  }

  /**
   * Find the max in lis[], which will be the length of our LIS
   */
  for (i = 0, max = 0; i < n; i++) {
    if (max < lis[i]) {
      max = lis[i];
    }
  }

  return max;
}
