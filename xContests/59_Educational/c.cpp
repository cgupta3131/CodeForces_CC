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

int kthLargest (vector<int> input, int k)
{
	int n = input.size();
	vector<int> output;
	priority_queue<int, vector<int>, greater<int> > p;

	for(int i=0;i<k;i++)
		p.push(input[i]);

	for(int i=k;i<n;i++)
	{
		if(p.top() < input[i])
		{
			p.pop();
			p.push(input[i]);
		} 
	}
	int sum = 0;

	while(!p.empty())
	{
		sum += p.top();
		p.pop();
	}
	return sum;
	   
}

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

    vector<pii> myvec; //starting index and length!

    ll count = 1;
    ll final_sum = 0;

    for(int i=1;i<n;i++) 
    {
    	if(i == n-1)
    	{
    		if(s[i] == s[i-1])
    		{
    			count++;
    			
   				pii temp = mp(i+1-count,count);
                myvec.pb(temp);
    		}

    		else
    		{	
    			
    			pii temp = mp(i-count,count);
    			myvec.pb(temp);
    			
    			final_sum += input[i];
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
    //cout << myvec.size() << endl;
    for(int i=0;i<myvec.size();i++)
    {
    	ll a = myvec[i].f; //index
    	ll b = myvec[i].s; //len
        //cout << a << endl;
        //cout << b << endl;
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
