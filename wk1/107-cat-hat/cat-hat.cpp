/**
 * Problem 107 - The Cat in the Hat
 *
 * Natalie Barillario & Jordan Scales
 * for CS370
 * Jan 27, 2014
 */
#include <iostream>
#include <cmath>
#include <stdio.h>

int main() {
    std::string input;
    int i, initialHeight, workingCats;
    double n;
    double x;
    int totalCats, totalHeight, nonWorkingCats;
    bool shouldBreak;

    while(scanf("%d %d\n", &initialHeight, &workingCats)) {
        if (initialHeight == 0 && workingCats == 0) {
            break;
        }

        /* Handle edge case for 1 1 */
        if (initialHeight == 1 && workingCats == 1) {
            std::cout << 0 << " " << 1 << std::endl;
            continue;
        }

        /**
         * Working cats: n^x
         * Height of first cat: (n+1)^x
         *
         * Find x and n
         */
        for (n = 1; n <= workingCats; n++) {
            shouldBreak = false;
            for (x = 1; pow(n+1, x) <= initialHeight; x++) {
                if (pow(n, x) == workingCats && pow(n+1, x) == initialHeight) {
                    shouldBreak = true;
                    break;
                }
            }

            if (shouldBreak) break;
        }

        /**
         * Compute the non-working cats (totalCats - workingCats)
         *     Total cats: n^0 + n^1 + ... + n^x
         *     Non-working Cats: Total cats - n^x
         *
         * Compute the height of everyone
         *     (n+1)^x * n^0 + (n+1)^(x-1) * n^1 + ... + (n+1)^1 * n^(x-1) + n^x
         */
        totalCats = 0;
        totalHeight = 0;

        for (i = 0; i <= x; i++) {
            totalCats += pow(n, i);
            totalHeight += pow(n+1, x-i) * pow(n, i);
        }
        nonWorkingCats = totalCats - workingCats;

        std::cout << nonWorkingCats << " " << totalHeight << std::endl;
    }
    return 0;
}



