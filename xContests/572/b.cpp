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

    int *arr = new int[n];
    for(int i=0;i<n;i++)
    	cin >> arr[i];

    sort(arr,arr+n);

    int x = arr[n-1];
    int y = arr[n-2];
    int z = arr[n-3];

    if(y+z <= x)
    	cout << "NO" << endl;
    else
    {
    	cout << "YES" << endl;
    	for(int i=0;i<n-3;i++)
    		cout << arr[i] << " ";
    	cout << arr[n-2] << " " << arr[n-1] << " " << arr[n-3] << endl;
    }	
     
    
    
	return 0 ;

}
