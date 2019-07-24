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

ll exponentMod(ll A, ll B, ll C) 
{ 
    // Base cases 
    if (A == 0) 
        return 0; 
    if (B == 0) 
        return 1; 
  
    // If B is even 
    ll y; 
    if (B % 2 == 0) { 
        y = exponentMod(A, B / 2, C); 
        y = (y * y) % C; 
    } 
  
    // If B is odd 
    else { 
        y = A % C; 
        y = (y * exponentMod(A, B - 1, C) % C) % C; 
    } 
  
    return (ll)((y + C) % C); 
} 

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    ll temp1 = 1000000000;

    ll *arr = new ll[n];

    for(int i=0;i<n;i++)
    	cin >> arr[i];

   	ll ans = 0;
   	ll mod = 998244353;
    
    ll len = 0;
    ll temp = arr[0];

    while(temp != 0)
    {
    	len++;
    	temp /= 10;
    }

    for(int i=0;i<n;i++)
    {
    	ll x = arr[i];
    	ll p = 0;

    	while(x != 0)
    	{
    		ll dig = x%10;
    		x /= 10;

    		ll mul1 = exponentMod(10,p,mod);
    		mul1 %= mod;

    		ll a1 = dig*mul1;
    		a1 %= mod;
    		a1 *= n;
    		a1 %= mod;

    		ans += a1;
    		ans %= mod;

    		ll mul2 = exponentMod(10,p+1,mod);
    		mul2 %= mod;

    		ll a2 = dig*mul2;
    		a2 %= mod;
    		a2 *= n;
    		a2 %= mod;

    		ans += a2;
    		ans %= mod;

    		//cout << ans << " " << p << endl;

    		p +=2;
    	}
    }

    cout << ans << endl;


    
	return 0 ;

}
