#include<bits/stdc++.h>

using namespace std;


int main()
{
	long long int n;
	cin >> n;

	long long int y = int(sqrt(n));

	int flag = 0;

	for(long long int i=1;i<=32000;i++)
	{
		if(i*i == n)
		{
			flag = 1;
			break;
		}
	}

	long long int nearest = y*y;

	if(flag == 1)
	{	
		//cout << "hey" << endl;
		cout << 2*y << endl;
		return 0;
	}

	if( n <= nearest + y)
		cout << 2*y +1 << endl;
	else
		cout << 2*(y+1) << endl;





	return 0 ; 

}

