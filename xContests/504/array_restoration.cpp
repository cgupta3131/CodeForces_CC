#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{

	int n; //number of integers in the array
	int q; //number of the queries to be performed on the array

	int *arr = new int[n];

	for(int i=0;i<n;i++)
		cin >> arr[i];


	for(int i=q;i>=1;i--)
	{
		//We will check for the query i;

		for(int j=0;j<n;j++)
		{
			if(arr[j] == i && j+1 == i)
				continue;

			if(arr[j] == i)

		}


	}


	

}

