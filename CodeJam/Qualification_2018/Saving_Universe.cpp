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

    int t;
    cin >> t;

    for(int tc=1;tc<=t;tc++)
    {
    	cout << "Case #" << tc << ": ";
    	ll d;
    	string s;

    	cin >> d >> s;
    	ll total_initial = 0;
    	int to_be_added = 1;
    	int power = 0;

    	int count[31];
    	for(int i=0;i<31;i++)
    		count[i] = 0;

    	for(int i=0;i<s.length();i++)
    	{
    		if(s[i] == 'C')
    		{
    			to_be_added *= 2;
    			power++;
    		}
    		else
    		{
    			count[power]++;
    			total_initial += to_be_added;
    		}
    	}

    	if(total_initial <= d)
    	{
    		cout << 0 << endl;
    		continue;
    	}

    	int moves = 0;
    	int start_idx = 30;
    	int flag = 0;
    	while(start_idx>0)
    	{
    		if(count[start_idx] == 0)
    		{
    			start_idx--;
    			continue;
    		}

    		moves++;
    		count[start_idx]--;
    		count[start_idx-1]++;
    		total_initial -= pow(2,start_idx);
    		total_initial += pow(2,start_idx-1);
    		if(total_initial <= d)
    		{
    			cout << moves << endl;
    			flag = 1;
    			break;
    		}
    		
    	}

    	if(flag == 1)
    		continue;
    	else
    		cout << "IMPOSSIBLE" << endl;

    }
    
    
	return 0 ;

}
