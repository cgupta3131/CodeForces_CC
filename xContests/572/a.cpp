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

    
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count0 = 0;
    int count1 = 0;
    for(int i=0;i<n;i++)
    {
    	if(s[i] == '0')
    		count0++;
    	else
    		count1++;
    }

	if(count0 != count1)
    {
    	cout << 1 << endl;
    	cout << s << endl;

    }

    else
    {
    	string s1 = "";
    	string s2 = "";

    	s1 = s[0];
    	for(int i=1;i<n;i++)
    		s2 += s[i];

    	cout << 2 << endl;
    	cout << s1 << " " << s2 << endl;
    }
    
	return 0 ;

}

