import java.io.*;
import java.util.*;

class Main {

    public static void main (String args[]) { // entry point from OS
        Main myWork = new Main();    // create a dinamic instance
        myWork.Begin();                        // the true entry point
    }

    void Begin() {
        Scanner sc;
        int a, b, min, max, num, n, cycle, cyclemax;

        sc = new Scanner(System.in);

        while (sc.hasNext()) {
            a = sc.nextInt();
            b = sc.nextInt();

            if (a < b) {
                min = a;
                max = b;
            } else {
                min = b;
                max = a;
            }

            for (cyclemax = -1, num = min; num <= max; num++) {
                for (n = num, cycle = 1; n != 1; cycle++) {
                    if ((n % 2) != 0) n=3*n+1; else n >>= 1;
                }

                if (cycle > cyclemax) {
                    cyclemax = cycle;
                }
            }

            System.out.println (a + " " + b + " " + cyclemax);
        }
    }

}
