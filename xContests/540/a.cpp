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

    int q;
    cin >> q;

    while(q--)
    {
    	ll n,a,b;
    	cin >> n >> a >> b;

    	ll cost_a = a*2; //cost per 2 litres
    	ll cost_b = b; //cost per 2 litres

    	// << cost_a << " " <<   cost_b << endl; 
    	if(cost_a <= cost_b)
    	{
    		cout << a*n << endl;
    		continue;
    	}

    	else
    	{
    		int rem = n%2;
    		if(rem == 0)
    		{
    			cout << (n/2)*b << endl;
    			continue;
    		}

    		else
    		{
    			//cout << "chirag-----" ;
    			cout << ((n-1)/2)*b + a << endl;
    			continue;
    		}

    	}

    }
    
    
	return 0 ;

}
