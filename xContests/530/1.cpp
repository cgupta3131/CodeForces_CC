#include<bits/stdc++.h>

using namespace std;


int main()
{
	int w,h,u1,d1,u2,d2;

	cin >> w >> h >> u1>> d1 >> u2 >> d2;

	int cur_weight = w;

	for(int i=h;i>=0;i--)
	{
		cur_weight += i;

		if(i == d1)
			cur_weight -= u1;
		else if(i == d2)
			cur_weight -= u2;

		//cout << i << " " << cur_weight << endl;
		if(cur_weight < 0)
			cur_weight = 0;
	}

	cout << cur_weight << endl;


	return 0 ; 

}

