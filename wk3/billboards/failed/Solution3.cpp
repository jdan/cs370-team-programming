#include <cstdio>
#include <iostream>
#include <cstdlib>

typedef struct
{
	unsigned long long val;
	int count;
	//short isUsed;
} svalue;

int getMaxIndex(svalue* vals, int n)
{
	int i; 
	int p = 0;
	unsigned long long max = vals[0].val;
	
	for(i = 0; i < n; i++)
	{	
		if(vals[i].val > max)
		{
			max = vals[i].val;
			p = i;
		}
	}
	return p;
}

//makes a partition at the index of the max
//then does the same on the partitions
//ensuring that it doesnt use more than a k group of maxes
void billboard(svalue* vals, int n, int k)
{
	int m, i, j, sub;
	sub = 0;
	m = getMaxIndex(vals, n);
	//std::cout << "first m: " << m << std::endl;
	//std::cout << "count at vals[i]: " << vals[0].count << std::endl << std::endl;
	if(n != 0)
	{	
		//std::cout << "m: " << m << std::endl;
		//std::cout << "count at vals[m-1]: " << vals[m-1].count << std::endl << std::endl;
		//locate the left edge of the group
		//std::cout << "i: " << i << std::endl << std::endl << std::endl;
		for(i = m-1; vals[i].count != 0 || i == 0; i--)
		{
			//std::cout << "i: " << i << std::endl << std::endl << std::endl;
			//reset i and quit if i tries to go below 0
			if(i < 0)
				{
					i = 0;
					break;
				}
			//std::cout << "i: " << i << std::endl << std::endl << std::endl;
			//std::cout << "count at vals[i]: " << vals[i].count << std::endl << std::endl;
		}
		//locate the right edge of the group
		//std::cout << "i1: " << i << std::endl << std::endl << std::endl;
		//std::cout << "j1: " << j << std::endl << std::endl << std::endl;
		for(j = m+1; vals[j].count != 0 || j == n; j++)
		{
			//reset j and quit if j tries to go above n
			if(j > n)
				{
					j = n;
					break;
				}
		}
		//std::cout << "i2: " << i << std::endl;
		//std::cout << "j2: " << j << std::endl;
		//sub is the size of the current group
		sub = j - i - 1;
		std::cout << "sub: " << sub << std::endl << std::endl;
		if(sub <= k)
		{
			for(i = i+1; i < j; i++)
				vals[i].count = sub;
		}		
		if(m >= 0 && m < n)	
			{
				billboard(vals, m, k);
				billboard(&vals[m+1], n-m-1, k);
			}

			
	}
}

unsigned long long sum(svalue* vals, int n)
{
	int i, sum;
	sum = 0;
	for(i = 0; i < n; i++)
		if(vals[i].count > 0)
			sum += vals[i].val;
	return sum;
}

int main()
{
	int n, k, i;
	unsigned long long temp;
	//unsigned long long* vals;
	svalue* svals;

	std::cin >> n;
	std::cin >> k;

	//vals = new unsigned long long[n];
	//svals = new value[n];
	svals = (svalue*)malloc(n*sizeof(svalue));

	for(i = 0; i < n; i++) 
	{
		std::cin >> temp;
		//vals[i] = temp;
		svals[i].val = temp;
		svals[i].count = 0;
	}

	billboard(svals, n, k);
	std::cout << sum(svals, n) << std::endl;
	for(i = 0; i < n; i++)
		std::cout << svals[i].count << std::endl;
	//delete[] vals;
	//delete[] svals;
	//free(svals);
}



