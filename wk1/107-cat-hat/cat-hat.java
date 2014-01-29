import java.io.*;
import java.util.*;
import java.lang.Math.*;

class Main
{
	void Begin()
	{
		Scanner sc;
	    int i, initialHeight, workingCats;
        double n;
        double x = 0;
        int totalCats, totalHeight, nonWorkingCats;
        boolean shouldBreak;

        sc = new Scanner(System.in);
        while (sc.hasNext()){
            initialHeight = sc.nextInt();
            workingCats = sc.nextInt();

            if (initialHeight == 0 && workingCats == 0) {
                break;
            }

            if (initialHeight == 1 && workingCats == 1) {
                System.out.println( 0 + " " + 1 );
                continue;
            }

            for (n= 1; n<=workingCats; n++) {
        	    shouldBreak = false;
                for (x=1; Math.pow(n+1,x) <= initialHeight; x++) {
                    if (Math.pow(n, x) == workingCats && Math.pow(n+1, x) == initialHeight) {
                        shouldBreak = true;
                        break;
    			    }
    		    }
                if (shouldBreak) break;
            }

            totalCats = 0;
            totalHeight = 0;

            for (i = 0; i <= x; i++) {
    	        totalCats += Math.pow(n, i);
    	        totalHeight += Math.pow(n+1, x-i) * Math.pow(n,i);
            }
            nonWorkingCats = totalCats - workingCats;
 
            System.out.println( nonWorkingCats + " " + totalHeight);
        }
    }
    
    public static void main (String args[])  // entry point from OS
    {
        Main myWork = new Main();  // create a dinamic instance
        myWork.Begin();            // the true entry point
    }
}