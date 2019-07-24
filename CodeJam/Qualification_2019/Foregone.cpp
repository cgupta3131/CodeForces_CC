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

    for(int tt=1;tt<=t;tt++)
    {
    	cout << "Case #" << tt << ": ";
    	long long int n;
    	cin >> n;

    	long long int temp = n;
    	long long int num1 = 0;

    	int idx = 0;

    	while(temp != 0)
    	{
    		int rem = temp%10;

    		if(rem == 4)
    			num1 += pow(10,idx);

    		temp /= 10;
    		idx++;
    	}

    	cout << num1 << " " << n - num1 << endl;

    }
    
    
	return 0 ;

}
	