#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


ll n,k;
ll maxvalue = 0;
int x =0;

ll solve(ll *arr)
{
	ll count = 0;
	ll sum = 0;
	for(ll i=0;i<n;i++)
	{
		sum += arr[i];
		if(arr[i] > k )
			count++;
	}

	if(count == 0 || count == 1) //base Case
		return sum;

	map<pair<ll,ll>,bool> mymap;

	for(ll i=0;i<n-1;i++)
	{
		for(ll j=i+1;j<n;j++)
		{
			if( min (arr[i],arr[j]) <= k)
					continue;

			else
			{	

				pair<ll,ll> p;
				p.first = arr[i];
				p.second = arr[j];

				pair<ll,ll> q;
				q.first = arr[j];
				q.second = arr[i];

				if(mymap[p] == true || mymap[q] == true )
					continue;

				pair<ll,ll> r;
				r.first = arr[i];
				r.second = arr[j];

				mymap[r] = true;

				if( sum-2 < maxvalue )
					continue;

				arr[i] = arr[i]-1;
				arr[j] = arr[j]-1;
				x++;
				ll value = solve(arr);
				if(value > maxvalue)
				{
					/*  cout << "Array : ";
					for(int i=0;i<n;i++)
						cout << arr[i] << " ";  */
					cout << endl;
					maxvalue = value;
					cout << maxvalue << endl;
				}
			}

			arr[i] = arr[i]+1;
			arr[j] = arr[j]+1;
		}
	}

	return maxvalue;
}

int main()
{
	ll test_cases;
	cin >> test_cases;

	while(test_cases--)
	{

		cin >> n;
		cin >> k;

		ll *arr = new ll[n];

		for(ll i=0;i<n;i++)
			cin >> arr[i];

		cout << solve(arr) << endl;
		//cout << x << endl;
	}

	return 0 ; 

}

