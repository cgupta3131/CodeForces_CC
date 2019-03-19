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
vector<ll> factors;
void primeFactors(ll n) 
{ 
    while (n%2 == 0) 
    { 
    	factors.pb(2);
        n = n/2; 
    } 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        while (n%i == 0) 
        { 
        	factors.pb(i);
            n = n/i; 
        } 
    } 

    if (n > 2) 
    	factors.pb(n);
} 

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m;
    cin >> n >> m;

    ll rem = m%n;

    if(rem != 0)
    {
    	cout << -1 << endl;
    }

    else
    {
    	ll d = m/n;
    	if(d == 1)
    	{
    		cout << 0 << endl;
    		return 0;
    	}
    	primeFactors(d);


    	if(factors[factors.size()-1] == 2 || factors[factors.size()-1] == 3 )
    		cout << factors.size() << endl;

    	else
    		cout << -1 << endl;

    }
    
    
	return 0 ;

}
