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

    ll *input = new ll[n];
    for(int i=0;i<n;i++)
    	cin >> input[i];

    string s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<pii> myvec;

    ll count = 1;
    ll final_sum = 0;
    //Corner Case left!
    if(n == 1)
    {
    	cout << input[0] << endl;
    	return 0;
    }

    for(int i=1;i<n;i++) 
    {
    	if(i == n-1)
    	{
    		if(s[n-1] == s[n-2])
    		{
    			count++;
    			
   				pii temp = mp(n-count,count);
                myvec.pb(temp);
    		}

    		else
    		{	
    			pii temp = mp(n-1-count,count);
    			myvec.pb(temp);
    			
    			final_sum += input[n-1];
    		}

    		break;
    	}
    	if(s[i] == s[i-1])
    		count++;

    	if(s[i] != s[i-1])
    	{
    		pii temp = mp(i-count,count);
    		myvec.pb(temp);
    		count = 1;
    	}
    }   

    for(int i=0;i<myvec.size();i++)
    {
    	ll a = myvec[i].f; 
    	ll b = myvec[i].s; 
     
    	sort(input+a,input+a+b,greater<ll>());

        if(b>k)
        {
    	   for(int j=a;j<a+k;j++)
    		  final_sum += input[j];
        }
        else
        {
           for(int j=a;j<a+b;j++)
              final_sum += input[j]; 
        }
    }

    cout << final_sum << endl;
	return 0 ;

}
