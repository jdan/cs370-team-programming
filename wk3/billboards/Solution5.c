#include "stdio.h"
#include <stdlib.h>

int main()
{
	int n, k, i, j;
	unsigned long long* vals;
	unsigned long long* cost;
	unsigned long long sum = 0;
	unsigned long long q;
	unsigned long long min;

	scanf("%d", &n);
	scanf("%d", &k);

	//printf("%d", n);

	vals = (unsigned long long*)malloc(sizeof(unsigned long long)*n);
	cost = (unsigned long long*)malloc(sizeof(unsigned long long)*n);

	//read in input while keeping track of the max sum
	for(i = 0; i < n; i++) 
	{
		scanf("%llu", &q);
		vals[i] = q;
		sum += vals[i];
	}
	
	//eyyyyyyyyy
	//if k = n you dont gotta do anything ya dig
	if(k >= n)
	{
		printf("%llu", sum);
		return 0;
	}

	//initialize cost
	for(i = 0; i <= k && i < n; i++)
		cost[i] = vals[i];

	//does.................something
	//cost after k will add pairs of numbers that are k apart
	//min is vals + cost
	//value of cost should always be minimized
	for(i = k+1; i < n; i++)
	{
		//std::cout << "i: " << i << std::endl;
		//std::cout << "cost[i]: " << cost[i-k-1] << " @ " << i-k-1 << " + " << vals[i] << " @ " << i << std::endl;
		//adds numbers that are k apart in order find the minimum value of a potential group of k nums
		cost[i] = cost[i-k-1] + vals[i];
		for(j = i-k; j <= i; j++)
		{

			//min makes sure that the potential group of k would indeed provide the minimum
			min = cost[j] + vals[i];
			if(min < cost[i])
			{
				cost[i] = min;
				//std::cout << "ayyyy" << std::endl << std::endl;
			}
		}
	}
	//this is where the min(ish) subtracted loss is stored
	min = cost[n-1];

	for(i = n-2; i >= n-k-1 && i >= 0; i--)
		if(cost[i] < min)
			min = cost[i];

	printf("%llu", sum - min);
	//free(vals);
	//free(cost);
}



