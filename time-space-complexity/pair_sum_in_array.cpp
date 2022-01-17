/*
You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
 Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7
Sample Output 1:
7
*/
CODE
#include <iostream>
#include <algorithm>
using namespace std;
int pairSum(int *arr, int n, int num)
{int count=0;
	//Write your code here
    for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]==num){
                count++;
            }
        }
    }
 return count;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;
		int x;
		cin >> size;
		int *input = new int[size];
		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;
		cout << pairSum(input, size, x) << endl;
		delete[] input;
	}
	return 0;
}
