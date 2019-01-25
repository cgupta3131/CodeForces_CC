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

    int *arr = new int[n+1];
    int *helper = new int[n+1];

    for(int i=1;i<=n;i++)
    	cin >> arr[i];

    int max = -1;
    for(int i=1;i<=k;i++)
    {
    	for(int j=1;j<=n;j++)
    		helper[j] = arr[j];

    	int b = i;
    	int j=0;
    	while(1)
    	{
    		if(b+j*k > n)
    			break;
    		
    		helper[b+j*k] = 0;
    		j++;
    		
    	}

    	int e = 0;
    	int s = 0;

    	for(int j=1;j<=n;j++)
    	{
    		if(helper[j] == -1)
    			e++;
    		if(helper[j] == 1)
    			s++;
    	}

    	int pos = abs(e-s);
    	if(pos > max)
    		max = pos;
    }

    cout << max << "\n";
 

	return 0 ; 

}



