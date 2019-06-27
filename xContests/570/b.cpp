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
    	int n,k;
    	cin >> n;
    	cin >> k;
    	int *arr = new int[n];

    	for(int i=0;i<n;i++)
    		cin >> arr[i];

    	int mini = INT_MAX;
    	int maxi = INT_MIN;

    	for(int i=0;i<n;i++)
    	{
    		mini = min(mini,arr[i]);
    		maxi = max(maxi,arr[i]);
    	}
    	//cout << mini << " " << maxi << "---";
    	int x = mini+k;
    	int y = maxi-k;

    	if(x>=y)
    		cout << x << endl;
    	else
    		cout << -1 << endl;	

    }

    
	return 0 ;

}
