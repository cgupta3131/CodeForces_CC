#include<bits/stdc++.h>
using namespace std;

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
	cin >> n;

	int *length = new int[n];
	for(int i=0;i<n;i++)
		cin >> length[i];

	sort(length,length+n);

	int minCost = INT_MAX;
	int t = -1;
	
	for(int i=length[0];i<=length[n-1];i++)
	{
		int tt = i;
		int possible_min_cost = 0;
		for(int i=0;i<n;i++)
		{
			if(length[i] == tt || length[i]+1 == tt || length[i]-1 == tt)
				continue;
			else
			{
				if(length[i] > tt)
					possible_min_cost += length[i] - tt -1;
				else
					possible_min_cost += tt - length[i] -1;
			}
		}

		if(possible_min_cost < minCost)
		{
			minCost = possible_min_cost;
			t = tt;
		}
	}

	cout << t << " " << minCost << endl;


	
	return 0 ; 

}



