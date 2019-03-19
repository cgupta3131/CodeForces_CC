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

    ll start,n;
    cin >> start >> n;

    ll *hp = new ll[n];
    ll *dp = new ll[n];
    ll sum_round = 0;


    for(ll i=0;i<n;i++)
    {
     	cin >> hp[i]; 
     	sum_round += hp[i];
    }

    dp[0] = hp[0];
    for(ll i=1;i<n;i++)
    	dp[i] = dp[i-1] + hp[i];
    ll min_val = INT_MAX;
    for(ll i=0;i<n;i++)
    	if(dp[i] < min_val)
    		min_val = dp[i];
    //Conducting the First Round
    ll curr_hp = start;	
    for(ll i=0;i<n;i++)
    {
    	curr_hp += hp[i];
    	if(curr_hp <= 0) //means the monster dies
    	{
    		cout << i+1 << endl;
    		return 0;
    	}
    }

    if(sum_round >= 0) //Monster can't die
    	cout << -1 << endl;
    else
    {
    	//cout << sum_round << " " << min_val << endl;
    	ll num = start + min_val;
    	ll den_int = -1*sum_round;
    	double den = -1*sum_round;
    	//cout << num/den << endl;
    	double k = ceil(num/den);

    	ll minutes = k*n;
    	ll curr_hp = start + k*sum_round;

	    for(ll i=0;i<n;i++)
	    {
	    	curr_hp += hp[i];
	    	if(curr_hp <= 0) //means the monster dies
	    	{
	    		cout << minutes+i+1 << endl;
	    		return 0;
	    	}
	    }
    }
    
 



	return 0 ;

}
