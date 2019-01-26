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

    int q;
    cin >> q;

    while(q--)
    {
    	int n;
    	cin >> n;

    	string s;
    	cin >> s;
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');

    	int first1 = s[0] - '0';
    	int second1 = s[1] - '0';
    	if(n == 2 && first1 >= second1)
    		cout << "NO" << "\n";
    	else
    	{
    		cout << "YES" << endl;
    		cout << 2 << endl;
    		cout << s[0] << " ";
    		for(int i=1;i<n;i++)
    			cout << s[i];
    		cout << endl;
    	}

    }
    
    
    
	return 0 ;

}
