//import java.io.*;
import java.util.*;

public class Solution
{
	public static void main(String[] args)
	{
		int n, k, i, j, q;
		long[] vals;
		long[] cost;
		long sum = 0;
		long min;
		Scanner sc = new Scanner(System.in);

		n = sc.nextInt();
		k = sc.nextInt();

		vals = new long[n];
		cost = new long[n];

		//read in input while keeping track of the max sum
		for(i = 0; i < n; i++) 
		{
			vals[i] = sc.nextLong();
			sum += vals[i];
		}
		
		//eyyyyyyyyy
		if(k >= n)
			System.out.println(sum);
		

		//initialize cost
		for(i = 0; i <= k && i < n; i++)
			cost[i] = vals[i];

		//cost after k will add pairs of numbers that are k apart
		//min is vals + cost
		//value of cost should always be minimized
		for(i = k+1; i < n; i++)
		{
			//adds numbers that are k apart in order find the minimum value of a potential group of k nums
			cost[i] = cost[i-k-1] + vals[i];
			for(j = i-k; j <= i; j++)
			{
				//min makes sure that the potential group of k would indeed provide the minimum
				min = cost[j] + vals[i];
				if(min < cost[i])
				{
					cost[i] = min;
				}
			}
		}
		//this is where the min(ish) subtracted loss is stored
		min = cost[n-1];

		for(i = n-2; i >= n-k-1 && i >= 0; i--)
			if(cost[i] < min)
				min = cost[i];

		System.out.println(sum - min);
	}
}



