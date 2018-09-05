#include<iostream>
#include<string>
#include<vector>
#include<climits>

using namespace std;

int main()
{
	int n;

	cin >> n;
	int *left = new int[n];
	int *right = new int[n];

	for(int i=0;i<n;i++)
		cin >> left[i] >> right[i];

	long long int min = LONG_MAX;
	int min_index;
	for(int i=0;i<n;i++)
	{
		if(right[i] - left[i] < min)
		{
			min = right[i] - left[i];
			min_index = i;
		}

	}

	int max = -1;
	int max_index;

	for(int i=0;i<n;i++)
	{
		if(right[i] - left[i] > max)
		{
			max= right[i] - left[i];
			max_index = i;
		}

	}

	int maxvalue = -1;

	int l = -1;
	long long int r = LONG_MAX;
	for(int j=0;j<n;j++)
	{
		if(j == min_index)
			continue;

		if(left[j] > l)
			l = left[j];
		if(right[j] < r)
			r = right[j];
	}

	maxvalue = r-l;

	l = -1;
	long long int _r = LONG_MAX;
	for(int j=0;j<n;j++)
	{
		if(j == max_index)
			continue;

		if(left[j] > l)
			l = left[j];
		if(right[j] < _r)
			_r = right[j];
	}

	if(_r-l > maxvalue)
		maxvalue = _r-l;

	if(maxvalue < 0)
		cout << 0 << endl;
	else
		cout << maxvalue << endl;


	

}

