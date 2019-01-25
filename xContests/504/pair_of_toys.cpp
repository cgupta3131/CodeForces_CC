#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	
	long long int n; //total number of toys
	long long int k; // the value of the toy	

	cin >> n >> k;		


	long long int count = 0;
	/*
	long long int i;
	for(i=1;i<=n;i++)
	{
		if(k-i > 0 && k-i <= n)

			count++;
		if(k-i == 0)
			break;
	}
*/

	long long int value = k-1;

	if(value <=0)
		count =0;


	if( value <=n && value >0)
		count = value;

	if( value > n )
	{
		long long int temp = k-n;

		if(temp > n)
			count = 0;
		else
			count = n - temp +1;

	}

	if(count%2 == 1)
		cout << (count-1)/2 << endl;
	else
		cout << count/2 << endl;


}


