// C++ program to print sums of all possible 
// subsets. 
#include<bits/stdc++.h> 
using namespace std; 

vector<int> final;

void sums(int arr[], int l, int r, int sum) 
{ 
	if (l > r) 
	{ 
		final.push_back(sum);
		return; 
	} 
	sums(arr, l+1, r, sum+arr[l]); 
	sums(arr, l+1, r, sum - arr[l]); 
} 

int main() 
{  
	int n;
	cin >> n;

	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];

	sums(arr, 0, n-1,0); 

	for(int i=0;i<final.size();i++)
	{
		if(final[i]%360 == 0)
		{
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
} 
