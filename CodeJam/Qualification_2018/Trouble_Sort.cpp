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

    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++)
    {
    	cout << "Case #" << tc << ": ";
    	int n;
    	cin >> n;

    	ll *input = new ll[n];
    	for(int i=0;i<n;i++)
    		cin >> input[i];

    	vector<ll> pos1;
    	vector<ll> pos2;

    	for(int i=0;i<n;i++)
    	{
    		if(i%2 == 0)
    			pos1.pb(input[i]);
    		else
    			pos2.pb(input[i]);
    	}

    	sort(pos1.begin(),pos1.end());
    	sort(pos2.begin(),pos2.end());
    	sort(input,input+n);

    	int flag = 0;
    	for(int i=0;i<n;i++)
    	{
    		ll ele1 = input[i];
    		ll ele2;
    		if(i%2 == 0)
    			ele2 = pos1[i/2];
    		else
    			ele2 = pos2[i/2];
    		if(ele1 != ele2)
    		{
    			flag = 1;
    			cout << i << endl;
    			break;
    		}
    	}

    	if(flag == 1)
    		continue;
    	else
    		cout << "OK" << endl;

    }
    
    
	return 0 ;

}
