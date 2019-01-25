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

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n,m;
	cin >> n >> m;

	int *count = new int[n+1];

	for(int i=1;i<=n;i++)
		count[i] = 0;
	
	int req = n;

	if(n > m)
	{
		for(int i=0;i<m;i++)
			cout << 0;
		cout << "\n";	

		return 0;
	}

	for(int i=0;i<m;i++)
	{
		int x; 
		cin >> x;

		if(count[x] == 0)
		{
			req--;
			count[x]++;
		}

		else
			count[x]++;

		if(req == 0)
		{
			for(int j=1;j<=n;j++)
			{
				if(count[j] == 1)
					req++;
				count[j]--;
			}

			cout << 1;
		}

		else
			cout << 0;
	}

	cout << "\n";




	return 0 ; 

}



