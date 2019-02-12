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
vector<pll> vec;

void factorize(ll n) 
{ 
    ll count = 0; 
  
    while (!(n % 2))
    {
    	n >>= 1; 
        count++; 
    }
  
    if(count) 
    {
    	pll foo = make_pair(2,count);
    	vec.pb(foo);
    }
  
    // check for all the possible numbers that can  
    // divide it 
    for (ll i = 3; i <= sqrt(n); i += 2) 
    {
        count = 0; 
        while (n % i == 0) 
        { 
            count++; 
            n = n / i; 
        } 
        if (count) 
        {
        	pll foo = make_pair(i,count);
    		vec.pb(foo);
        }
    } 
  
    // if n at the end is a prime number. 
    if (n > 2)
    {
    	pll foo = make_pair(n,1);
    	vec.pb(foo);
    }	

} 

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   	ll N,B,p,c,noz,k;
   	cin >> N >> B;
	noz=N;
	factorize(B);	

	for(ll i=0;i<vec.size();i++)
	{
		ll prime = vec[i].first;
		ll count = vec[i].second;
		ll k = N;
		ll temp = 0;
		while(k/prime > 0)
		{
			temp += k/prime;
			k /= prime;
		}

		noz = min(noz,temp/count);
	}

	cout << noz << endl;
	return 0 ;

}
