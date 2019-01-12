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
#define ppi pair< pair<int,int>,int>

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		ppi *arr = new ppi[n];

		for(int i=0;i<n;i++)
		{
			cin >> arr[i].first.first >> arr[i].first.second;
			arr[i].second = i;
		}

		sort(arr,arr+n);
		int ans[n] = {0};

		ans[ arr[0].second ] = 1;

		int g1min = arr[0].first.first;
		int g1max = arr[0].first.second;

		int flag = 0;
		for(int i=1;i<n;i++)
		{
			if(flag == 1)
			{
				ans[arr[i].second] = 2;
				continue;
			}

			if(arr[i].first.first >= g1min && arr[i].first.first <= g1max)
			{
				ans[arr[i].second] = 1;
				if(arr[i].first.second > g1max)
					g1max = arr[i].first.second;
			}

			else
			{
				ans[arr[i].second] = 2;
				flag = 1;
			}

		}

		if(flag == 0)
			cout << -1 << endl;
		else
		{
			for(int i=0;i<n;i++)
				cout << ans[i] << " ";
			cout << endl;
		}

	}


	return 0 ; 

}



