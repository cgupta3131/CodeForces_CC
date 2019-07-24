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

    ll n,p,k;
    cin >> n >> p >> k;

    ll *arr = new ll[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];

    vector<ll> divisors;

    for(int i=1;i<=k;i++)
    {
    	if(k%i == 0)
    		divisors.push_back(i);
    }

    unordered_map<ll,ll> first_part;
    for(int i=0;i<divisors.size();i++)
    {
    	int sum = divisors[i];
    	first_part[sum] = 0;
    	int count = 0;


    	unordered_map<ll, ll> aux;
    	for(int j=0	;j<n;j++)
    	{	
    		ll temp = sum-arr[j] + p;
    		if( aux.find(temp%p) != aux.end() )
    			count += aux[temp%p];

    		if(aux.find(arr[j]) == aux.end() )
    			aux[arr[j]] = 1;
    		else
    			aux[arr[j]] += 1;
    	}

    	first_part[sum] = count;
    }

    cout << first_part[2] << endl;


    unordered_map<ll, ll > second_part;
    for(int i=0;i<divisors.size();i++)
    {
    	int sum = divisors[i];
    	first_part[sum] = 0;
    	int count = 0;


    	unordered_set<ll> aux;
    	for(int j=0;j<n;j++)
    	{	
    		ll temp = sum-(arr[j]*arr[j]) + p*p;
    		if( aux.find(temp%p) != aux.end() )
    			count++;

    		ll w = arr[j]*arr[j];
    		aux.insert( w%p ) ;
    	}

    	second_part[sum] = count;
    }

    int ans = 0;

   	int q = divisors.size();

   	for(int i=0;i<divisors.size();i++)
   	{
   		ans += first_part[divisors[i]]*second_part[divisors[n-1-i]];
   	}

   	cout << ans << endl;
    
    
	return 0 ;

}
