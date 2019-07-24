#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<pii,int> ppi;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    ll *arr = new ll[n];
    for(ll i=0;i<n;i++)
    	cin >> arr[i];

    sort(arr,arr+n);
    ll cur_turn = 0;

    if(n == 1)
    	cur_turn += arr[0];

    else if(n == 2)
    {
    	for(ll i=0;i<n;i++)
		{
			ll x = arr[i] - i;
			if(x < 0)
				break;
			cur_turn += x;
			cur_turn %= 2;
		}
    }

	else
	{
		ll count = 0;
		for(ll i=0;i<n-1;i++)
			if(arr[i] == arr[i+1])
				count++;

		if(count == 1)
		{
			ll idx = -1;
			for(ll i=0;i<n-1;i++)
			{
				if(arr[i] == arr[i+1])
				{
					idx = i;
					break;
				}
			}

			if(idx != 0 && arr[idx-1]+1 == arr[idx])
			{
				//first player will lose
			}

			else if(idx == 0)
				count--;

			else if(idx != 0 && arr[idx-1]+1 != arr[idx])
			{
				arr[idx] -= 1;
				cur_turn = 1;
				count--;
			}
		}

		else if(count > 2)
		{
			//first player will lose
		}

		if(count == 0)	
		{
			for(ll i=0;i<n;i++)
			{
				ll x = arr[i] - i;
				if(x < 0)
					break;
				cur_turn += x;
				cur_turn %= 2;
			}
		}
	}    	

	//cout << cur_turn << endl;
	cur_turn %= 2;
	if(cur_turn == 1)
		cout << "sjfnb" << endl;
	else
		cout << "cslnb" << endl;
     
	return 0 ;

}
