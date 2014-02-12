import java.util.*;

public class Solution
{
	public static void main(String[] args) 
	{
		int i, n, k;;
        long[] candy;
    	Scanner sc;
    	PriorityQueue<Long> candyQueue = new PriorityQueue<Long>();

    	sc = new Scanner(System.in);

        //n is the number of total packets
        //k is the amount of packets to be distributed
    	n = sc.nextInt();
    	k = sc.nextInt();

        //add numbers to priority queue
    	for (i = 0; i < n; i++)
    		candyQueue.add(sc.nextLong());
    	
    	//for(BigInteger c : candyQueue)
    	//	System.out.println(c);

    	candy = new long[n];

        //put sorted numbers into array
    	for (i=0; i<n; i++) {
    		candy[i] = candyQueue.poll();
    	}

    	System.out.println(unfair(candy, n, k));
	}

	//calculate the unfairness
	/*if given numbers a b c d e etc in a set of n numbers, the unfairness would be
	* k = 4 yields 3a + b - c - 3d
	* k = 5 yields 4a + 2b - 0c - 2d - 4e
	* k = 3 yields 2a - 2c
	*/
	public static long unfair(long[] candy, int n, int k)
	{
		//initial coefficient will be k-1
		//other coefficients will just be m-2;
		double min = Double.POSITIVE_INFINITY;
		long unf = 0;
		//BigInteger min = BigInteger.valueOf(999999999);
		//BigInteger unf = BigInteger.valueOf(0);
		//BigInteger mul;
		long m;
		int i, j, r;
		m = k-1;

		for(i = n-1; i > k-2; i--)
		{
			unf = 0;
			for(j = i, m = k-1, r = i-k + 1; j >= r; j--, r++)
			{
				//System.out.println("unf: " + unf);
				//System.out.println("m: " + m);
				//candylong = candy[(int)j].longValue();
				//System.out.println(candylong);
				//mul = BigInteger.valueOf(candylong * m);
				//unf = unf.add(mul);
				//unf += candy[j] * m;

				unf += m * candy[j];
				unf -= m * candy[r];
				m -= 2;
			}

		if(unf < min)
			min = unf;

		}
		//System.out.println("hooray");
		return (long)min;
	}
}