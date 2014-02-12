#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	
	unsigned long temp, min, sub;
    unsigned int n, k, i;
	min = 999999999;
    sub = 0;
	vector<unsigned long> candies(n);
	cin >> n;
	cin >> k;
	for (i = 0; i < n; i++) {
		cin >> temp;
		//input[i] = temp;
		candies.push_back(temp);
	}
	sort(candies.begin(), candies.begin()+n);
	//for(long c : candies)
	//	cout << c << endl;

    //calculate initial unfairness
    //first loop keeps track of first number in subtraction
    //second loop keeps track of number being subtracted
    for(i = 0; i+(k-1) < n; i++)
    {
        sub = candies[i+(k-1)] - candies[i];
        if(sub < min)
        	min = sub;      
    }    

    cout << min << endl;
    return 0;   
}