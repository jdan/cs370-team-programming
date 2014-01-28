import java.io.*;
import java.util.*;

class Main {

    public static void main (String args[]) {
        Main app = new Main();
        app.go();
    }

    public void go () {
        Scanner sc;
        int[][] bins;
        int i, j;

        sc = new Scanner(System.in);
        // BROWN, GREEN, CLEAR
        bins = new int[3][3];

        while (sc.hasNext()) {
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    bins[i][j] = sc.nextInt();
                }
            }

            optimizeBins(bins);
        }
    }

    private void optimizeBins(int[][] bins) {
        /** BROWN, GREEN, CLEAR */
        // BCG, BGC, CBG, CGB, GBC, GCB
        int minMovements, movements, i;
        String minRepresentation;
        int[][] permutations = new int[][]{
            { 0, 2, 1 },
            { 0, 1, 2 },
            { 2, 0, 1 },
            { 2, 1, 0 },
            { 1, 0, 2 },
            { 1, 2, 0 }
        };

        String[] representations = new String[]{
            "BCG", "BGC", "CBG", "CGB", "GBC", "GCB"
        };

        minMovements = transferBottles(bins, 0, 2, 1);
        minRepresentation = "BCG";

        for (i = 1; i < permutations.length; i++) {
            movements = transferBottles(
                bins, permutations[i][0], permutations[i][1], permutations[i][2]);

            if (movements < minMovements) {
                minMovements = movements;
                minRepresentation = representations[i];
            }
        }

        System.out.println(minRepresentation + " " + minMovements);
    }

    /**
     * Takes three integers representing the color to be placed in each bin
     *
     * For example: (..., 2, 0, 1) means the first bin is clear, the second
     *   bin in brown, and the third is green
     * The result is the amount of bottles that need to move in order to make
     *   this arrangement happen
     */
    private int transferBottles(int[][] bins, int a, int b, int c) {
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

}
