#include <cstdio>
#include <iostream>

using namespace std;

/*For some strange reason things go differently when I get rid of the print statements...why is that? */


void printArray(int* arr, int s) {
	cout << "[ ";
	for(int i = 0; i < s; i++)
		cout << arr[i] << " ";
	cout << "]" << endl;
}

int main() {
	int i, j, max, greaterMax, n, x;
	int* order;
	int* submission;
	int* records;
	order = new int[n];
	submission = new int[n];
	records = new int[n];
	cin >> n;

	//Setting the order of the numbers. 
	for (i= 0; i < n; i++) {
		cin >> x;
		x--;
		order[x] = i;

	}

	//do this for many things
	while (!cin.eof()) {
		for(i=0; i < n; i++) {
			cin >> submission[i];
		}
	

		//cout << "Submission: "; 
		//printArray(submission,n);
		

		records[0] = 1;
		greaterMax = 1;

		for (i = 1; i < n; i++) {
			cout << "i: " << i << endl;
			cout << "Number:" << submission[i] << endl;
			max = 1;
			for (j = i-1; j >= 0; j--) {

				cout << "    Number Read: " << submission[j] << endl;
				cout << "    order of i: " << order[submission[i]-1] << "order of j: "<< order[submission[j]-1]<<endl;
				if (order[submission[i]-1] > order[submission[j]-1]) {
					if ( 1 + records[j] > max) {
						max = records[j] + 1;
					}
					
				}
				
			}
			records[i] = max;
			printArray(records, i+1);
			if (records[i] > greaterMax) {
				greaterMax = records[i];
			}
		}

		cout << greaterMax << endl;
	}


		


}