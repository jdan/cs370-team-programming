#include <cstdio>
#include <iostream>

int main()
{
	int n, k, i, j, q;
	unsigned long long* vals;
	unsigned long long* cost;
	unsigned long long sum = 0;
	unsigned long long min;

	std::cin >> n;
	std::cin >> k;

	vals = new unsigned long long[n];
	cost = new unsigned long long[n];

	//read in input while keeping track of the max sum
	for(i = 0; i < n; i++) 
	{
		std::cin >> vals[i];
		//cost[i] = vals[i];
		sum += vals[i];
	}
	
	//eyyyyyyyyy
	//if k = n you dont gotta do anything ya dig
	if(k >= n)
	{
		std::cout << sum << std::endl;
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
			/*std::cout << "min: " << cost[j] << " @ " << j << " + " << vals[i] << " @ " << i << std::endl << std::endl;
			std::cout << "costs: " << std::endl;
			for(q = 0; q < n; q++)
				std::cout << cost[q] << std::endl;
			std::cout << std::endl;*/
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

	std::cout << sum - min << std::endl;
	delete[] vals;
	delete[] cost;
}



