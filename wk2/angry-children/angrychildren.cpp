#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int main() {

long long min, temp, j, curr, n, k, i, t;
vector<long long> candies;
cin >> n;
cin >> k;

for (i = 0; i < n; i++) {
cin >> temp;
//input[i] = temp;
candies.push_back(temp);
}
sort(candies.begin(), candies.begin()+n);
//for(int c : candies)
//	cout << c << endl;

/*long long* diffs;
diffs = new long long[n-1];

for (i=1; i < n; i++) {
diffs[i-1] = candies[i] - candies[i-1];
//cout << diffs[i-1]<< "=" << candies[i] << "-" << candies[i-1]<<endl;
} */



/*j = 0;
curr = 0;
for (i=0; i <= k-2; i++) {
	temp = diffs[i] * (i+1);
	j += temp;
	curr += j;
}

min = curr;
k-=1;
for (i = k, j=0; i < n-1; i++, j++) {
       curr = curr - (k * diffs[j]);
       curr = curr + (k * diffs[i]);
       if (curr < min) {
       	 min = curr;
       }
} */
min = LLONG_MAX;
for (i = n-1; i > k-2 ; i--) {
	curr = 0;
	
	for (j = i, t = k-1; j > i-k; j--)  {
		curr += t * (candies[j]);
		t -= 2;

	}
	if (curr < min) {
		min = curr;

	}
}

cout << min<<endl;;

return 0;
}