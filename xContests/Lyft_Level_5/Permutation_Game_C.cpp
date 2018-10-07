#include<bits/stdc++.h>

using namespace std;


int solve(int *input, int n, int *helper_array, int i)
{	
	int value = input[i];

	if(helper_array[i] !=0 )
		return helper_array[i];

	for(int j=1;j<=n;j++)
	{
		if(j == i)
			continue;
		if( (i-j)%value != 0)
			continue;
		if(input[j] < input[i])
			continue;

		int x = solve(input,n,helper_array,j);

		if(x == 2)
		{
			helper_array[i] = 1; 
			break;
		}
 	
		if(x == 1)
			helper_array[i] = 2;

	}

	if(helper_array[i] != 0)
		return helper_array[i];
	else
	{
		helper_array[i] = 2;
		return 2;
	}




}



void Permutation_Game(int *input,int n)
{
	int *helper_array = new int[n+1];

	for(int i=1;i<=n;i++)
		helper_array[i] = 0; 

	for(int i=1;i<=n;i++)
	{
		if(input[i] == n)
			helper_array[i] = 2;
		if(input[i] == 1)
			helper_array[i] = 1;
	}

	for(int i=1;i<n;i++)
	{
		if(helper_array[i] != 0)
			continue;

		int value = input[i];
		for(int j=1;j<=n;j++)
		{
			if(j == i)
				continue;
			if( (i-j)%value != 0)
				continue;
			if(input[j] < input[i])
				continue;

			if(helper_array[j] == 2)
			{
				helper_array[i] = 1;
				break;
			}
		}

		if(helper_array[i] == 0)
			helper_array[i] = solve(input,n,helper_array,i);
	}

	for(int i=1;i<=n;i++)
		if(helper_array[i] == 1)
			cout << "A";
		else
			cout << "B";
	cout << endl;

	return;

}





int main()
{
	int n;
	cin >> n;

	int *input = new int[n+1];

	for(int i=1;i<=n;i++)
		cin >> input[i];

	Permutation_Game(input,n);

	return 0 ; 

}

