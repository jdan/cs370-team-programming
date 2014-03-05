#include <cstdio>
#include <iostream>
#include <cstdlib>

typedef struct
{
	unsigned long long val;
	int pos;
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
void billboard(svalue* vals, short* used, int n, int k)
{
	int m, i, j, group;
	group = 0;
	m = getMaxIndex(vals, n);
	if(n != 0)
	{	
		//locate the left edge of the group
		for(i = m-1; used[i] || i == 0; i--)
		{
			if(used[i] && m == j-1)
				group+=1;
			//reset i and quit if i tries to go below 0
			if(i < 0)
				{
					i = 0;
					break;
				}
		}
		//locate the right edge of the group
		for(j = m+1; used[j] || j == n; j++)
		{
			if(used[j] && m == j+1)
			//	group+=1;
			//reset j and quit if j tries to go above n
			if(j > n)
				{
					j = n;
					break;
				}
		}
		std::cout << "group: " << group << std::endl;
		if(j > n)
			j = n;
		if(i < 0)
			i = 0;
		//group is the size of the current group
		std::cout << "i: " << i << std::endl;
		std::cout << "j: " << j << std::endl;
		group += j - i - 1;
		std::cout << "group: " << group << std::endl << std::endl;
		if(group < k)
		{
			used[m] = 1;
			std::cout << "USED" << std::endl << std::endl;
		}		
		if(m >= 0 && m < n)	
		{
			//for(i = 0; i < n; i++)
			//	std::cout << used[i] << std::endl;
			billboard(vals, used, m, k);
			billboard(&vals[m+1], used, n-m-1, k);
		}

			
	}
}

unsigned long long sum(svalue* vals, short* used, int n)
{
	int i, sum;
	sum = 0;
	for(i = 0; i < n; i++)
		if(used[i])
			sum += vals[i].val;
	return sum;
}

int main()
{
	int n, k, i;
	unsigned long long temp;
	svalue* svals;
	short* used;

	std::cin >> n;
	std::cin >> k;

	svals = (svalue*)malloc(n*sizeof(svalue));
	used = new short[n];

	for(i = 0; i < n; i++) 
	{
		std::cin >> temp;
		svals[i].val = temp;
		svals[i].pos = i;
	}

	billboard(svals, used, n, k);
	std::cout << sum(svals, used, n) << std::endl;
	for(i = 0; i < n; i++)
		std::cout << used[i] << std::endl;
	delete[] used;
}



