#include <cstdio>
#include <iostream>


 
unsigned long long myMax(unsigned long long* vals, int k)
{
	int i;
	unsigned long long max = vals[0];
	for(i = 0; i < k; i++)
		if(vals[i] > max)
			max = vals[i];

	return max;
}

//adds totals of every k and then returns the max
unsigned long long billboard(unsigned long long* vals, int n, int k)
{
	int i, j;
	unsigned long long sums[k];

	for(i = 0; i < k; i++)
		sums[i] = 0;

	//for(i = 0; i < k; i++)
	//	std::cout << "sums: " << sums[i] << std::endl;

	for(i = 0; i < n; i++)
		for(j = 0; j < k; j++)
			{
				if(!(i%k == j))
					{
						//std::cout << "adding: " << sums[j] << " + " << vals[i] << std::endl << std::endl;
						sums[j] += vals[i];
					}
				/*std::cout << "i: " << i << std::endl;
				std::cout << "j: " << i << std::endl;
				std::cout << "if: " << (i%k == j) << std::endl << std::endl;*/
			}
				

	for(i = 0; i < k; i++)
		std::cout << "sums: " << sums[i] << std::endl;

	return myMax(sums, k);

}

int main() 
{

	int n, k, i, temp;
	unsigned long long* vals;

	std::cin >> n;
	std::cin >> k;

	k++;

	vals = new unsigned long long[n];

	for (i = 0; i < n; i++) 
	{
		std::cin >> temp;
		vals[i] = temp;
	}

	std::cout << billboard(vals, n, k) << std::endl;

	delete[] vals;
}