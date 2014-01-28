/*Problem 107

Sample input

216 125
5764801 1679616
0 0

*/


#include <iostream>
#include <cmath> 
#include <stdio.h> 

int main() {
	std::string input;
	int i,j,k,inHeight,workCats;
	double n;
	double x;
	int nonworkingcats;
	int totalheight;
	while(scanf("%d %d\n", &inHeight, &workCats)) {
		if (inHeight == 0 && workCats == 0) {
			break;
		}

		for (i= 1; i < inHeight; i++) {
			n = pow(inHeight,1.0/i);
			if (workCats == pow(round(--n),i)) {
				break;
			}
		} 
		/*for (i = 2; i<inHeight; i++) {
			k = i;
			for (j = 1; k<inHeight; j++) {
				k = k*i;
			}
			if (k == inHeight)
				break;
		}*/

		totalheight = workCats;
		nonworkingcats = 0;
		for(j=0;j<i;j++) {
			x = pow(n,j);
			nonworkingcats += round(x);
			totalheight += x * (inHeight/pow(n+1,j));
		}
		std::cout<<nonworkingcats<<" "<<totalheight<<std::endl;
	}
	return 0;
}



