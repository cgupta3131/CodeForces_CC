#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	
	int n;
	cin >> n;
	int *arr = new int[n];

	for(int i=0;i<n;i++)
		cin >> arr[i];



	int max = 1;
	int count = 0;

	for(int i=0;i<n-1;i++)
	{
		if(arr[i+1] <= 2*arr[i])
			count++;
		else
		{	if(count+1 > max)
				max = count+1;
			count = 0;
		}

	}

	if(count+1 > max)
		max = count+1;		

	cout << max << endl;




}

