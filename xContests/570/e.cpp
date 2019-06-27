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
const int MAX_CHAR = 256;
#define MOD 1000000007

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer

void generate(set<string> &st, string s, int *dp)
{
	if(s.size() == 0)
	{
		dp[0] = 1;
		return;
	}

	if(st.find(s) == st.end())
	{
		int len = s.length();
		dp[len]++;
		st.insert(s);
	}

	for(int i=0;i<s.size();i++)
	{
		string t = s;
		t.erase(i,1);
		generate(st,t,dp);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int k;
    cin >> n >> k;

    string s;
    cin >> s;

    int *dp = new int[n+1];
    for(int i=0;i<=n;i++)
    	dp[i] = 0;
    
    set<string> st;
    generate(st,s,dp);

    int count_rem = k;
    int cost = 0;
    /*for(int i=0;i<=n;i++)
    	cout << dp[i] << " ";
    cout << endl;*/	

    int total = 0;
    for(int i=0;i<=n;i++)
    	total += dp[i];
   	if(k > total)
   	{
   		cout << -1 << endl;
   		return 0;
   	}

    for(int i=n;i>=0;i--)
    {
    	//cout << count_rem << " " << dp[i] << endl;
    	int val = dp[i];
    	if(count_rem > val)
    	{
    		count_rem -= val;
    		cost += (n-i) * dp[i];
    	}

    	else
    	{
    		cost += (n-i) * count_rem;
    		break;
    	}
    }

    cout << cost << endl;
	return 0 ;

}
