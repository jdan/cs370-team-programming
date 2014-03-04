#include <cstdio>
#include <iostream>

using namespace std;

/*For some strange reason things go differently when I get rid of the print statements...why is that? */


//used for testing
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
	//The numbers themselves are not stored in an array, but their positions. 
	//For example, if the number 7 comes third in the order, order[7] = 3
	//Only arrays go from index 0 to n-1, not 1-n, so we have an offset of -1
	//So in fact, order[6] = 3, which tells us that n (6+1) is in the third place
	for (i= 0; i < n; i++) {
		cin >> x;
		x--;
		order[x] = i;

	}

	//do this for many things
	while (!cin.eof()) {

		//add all of the numbers (real numbers this time) to the submission array
		for(i=0; i < n; i++) {
			cin >> submission[i];
		}
	

		//cout << "Submission: "; 
		//printArray(submission,n);
		
		//records tells you the largest substring at that position in the submission array
		//since submission[0] is the first number, records[0] is one
		records[0] = 1;

		//this is the length of the largest substring overall.
		//We have only seen one substring so far, and that is of length 1
		greaterMax = 1;


		//the first for loop traverses through the array starting at the second element
		for (i = 1; i < n; i++) {
			cout << "i: " << i << endl;
			cout << "Number:" << submission[i] << endl;

			//local max
			max = 1;

			//the second for loop goes backwards through the array, starting at submission[i-1]
			for (j = i-1; j >= 0; j--) {

				cout << "    Number Read: " << submission[j] << endl;
				cout << "    order of i: " << order[submission[i]-1] << "order of j: "<< order[submission[j]-1]<<endl;
				//if the number at i has a larger order than the number at position j
				//and if 1 + the record at position j is greater than local max
				//set 1 + record[j] to local max and keep searching for a higher max
				//the reason for the i-1 and j-1 is the offset described before
				if (order[submission[i]-1] > order[submission[j]-1]) {
					if ( 1 + records[j] > max) {
						max = records[j] + 1;
					}
					
				}
				
			}

			//store max in records[i]
			//check to see if that max is the largest max we've seen so far
			records[i] = max;
			printArray(records, i+1);
			if (records[i] > greaterMax) {
				greaterMax = records[i];
			}
		}

		cout << greaterMax << endl;
	}


		


}