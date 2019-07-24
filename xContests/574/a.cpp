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

    int *arr = new int[k+1];
    for(int i=0;i<=k;i++)
    	arr[i] = 0;

    for(int i=0;i<n;i++)
    {
    	int x;
    	cin >> x;
    	arr[x]++;
    }

    int odd = 0;
    int even = 0;
    for(int i=1;i<=k;i++)
    {
    	if(arr[i]%2 == 0)
    		even++;
    	else
    		odd++;
    }

    int sets = (n+1)/2;
    if(n%2 == 0) //even number
    {
    	int ans = odd/2;
    	cout << n-ans << endl;
    }

    else
    {
    	int ans = (odd-1)/2;
    	cout << n-ans << endl;

    }
    
    
	return 0 ;

}
