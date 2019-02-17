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
const int maxa = (1 << 20) + 3;
int cnt[2][maxa];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    ll *arr = new ll[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];

    ll *xorArr = new ll[n];
    xorArr[0] = arr[0];

    for(int i=1;i<n;i++)
    	xorArr[i] = xorArr[i-1] ^ arr[i];

    ll total = 0;
    int count_0 = 0;
    unordered_map<ll, ll> mp;
    unordered_map<ll, ll> mp2;

    for(int i=0;i<n;i++)
    {
    	if(xorArr[i] == 0 && i%2 == 1)
    		count_0++;
    	
		if(i%2 == 1)
			mp[xorArr[i]]++;
		else
			mp2[xorArr[i]]++;
    	
    }

   	total += count_0;

   	for(auto i: mp)
   	{
   		ll value = i.second;
   		total += ((value)*(value-1))/2;
   	}

   	for(auto j: mp2)
   	{
   		ll value = j.second;
   		total += ((value)*(value-1))/2;
   	}

   	cout << total << endl;

   	/*ll ans = 0;
   	cnt[1][0] = 1;

   	for(int i=0;i<n;i++)
   	{
   		ans += cnt[i%2][xorArr[i]];
   		cnt[i%2][xorArr[i]]++;
   	} 

   	cout << ans << endl;*/
    
	return 0 ;

}
