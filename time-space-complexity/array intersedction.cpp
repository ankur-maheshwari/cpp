/*
Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 2 2
*/
CODE 

#include <iostream>
#include <algorithm>
using namespace std;

void fun(int arr1[], int arr2[], int n, int m){
    if(n == 0 || m == 0){
        return;
    }
    if(arr1[0] == arr2[0]){
        cout<<arr1[0]<<" ";
    	fun(arr1+1, arr2+1, n-1, m-1);
    }
    else{
        if(arr1[0] < arr2[0]){
            fun(arr1+1, arr2, n-1, m);
        }
        else{
            fun(arr1, arr2+1, n, m-1);
        }
    }
}

void intersection(int *arr1, int *arr2, int n, int m) {
	sort(arr1, arr1+n);
    sort(arr2, arr2+m);
	fun(arr1, arr2, n, m);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}
