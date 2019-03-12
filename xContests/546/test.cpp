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

    int n,k;
    cin >> n >> k;

    if(n == k)
    	k =1;
    if(k == 1)
    	cout << 3*n << endl;
    else
    {
    	k = min(k,n-k+1);
    	int t1 = min(k,n-k), t2 = max(k,n-k);
    	t1 -= 2;
    	t1 = max(0,t1);
    	int ans = 6;
    	if(t1 == 0)
    		ans += n-1+t2*2;
    	else
    		ans += n-1+t2*2+t1+t1*2;
    	cout << ans << endl;
    }
    
    
	return 0 ;

}
