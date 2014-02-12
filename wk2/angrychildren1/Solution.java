
import java.util.*;

public class Solution {

    public static void main(String[] args) {
    	int n, k, i;
        long[] candy;
    	Scanner sc;
    	PriorityQueue<Long> candyQueue = new PriorityQueue<Long>();

    	sc = new Scanner(System.in);

        //n is the number of total packets
        //k is the amount of packets to be distributed
    	n = sc.nextInt();
    	k = sc.nextInt();

        //add numbers to priority queue
    	for (i = 0; i< n; i++) {
    		candyQueue.add(sc.nextLong());
    	}

    	candy = new long[n];

        //put sorted numbers into array - is this necessary?
    	for (i=0; i<n; i++) {
    		candy[i] = candyQueue.poll();
    	}

    	/*for (i=0; i<n; i++) {
    		System.out.println(candy[i]);
    	}*/

        System.out.println(unfair(candy, n, k));
    }

    //calculates the min "unfairness" of each group of k
    public static long unfair(long[] candy, int n, int k)
    {
        int i;
        double min = Double.POSITIVE_INFINITY;
        long sub = 0;
        //calculate initial unfairness
        //first loop keeps track of first number in subtraction
        //second loop keeps track of number being subtracted
        for(i = 0; i+(k-1) < n; i++)
        {
            //System.out.println("sub: " + sub);
            sub = Math.abs(candy[i] - candy[i+(k-1)]);
            if(sub < (int)min)
                min = sub;                  
        }     

        return (long)min;

    }
}