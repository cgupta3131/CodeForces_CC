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

    vector<int> divisors[101];
    for(int i=1;i<=100;i++)
    {
    	for(int j=2;j<i;j++)
    	{
    		if(i%j == 0) //means that j divides i except '1' and 'j'
    			divisors[i].pb(j);
    	}
    }

    int n;
    cin >> n;
    int total_sum = 0;

    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
    	cin >> arr[i];
    	total_sum += arr[i];
    	
    }

    sort(arr,arr+n);
    vector<int> vec;

    int latest = -1;
    for(int i=0;i<n;i++)
    {
    	if(arr[i] != latest)
    	{
    		vec.pb(arr[i]);
    		latest = arr[i];
    	}
    }

    int mini = total_sum;
    //cout << mini << endl;
    for(int i=vec.size()-1;i>0;i--)
    {
    	for(int j=0;j<divisors[ vec[i] ].size(); j++)
    	{
    		int a = divisors[ vec[i] ][j]; //alpha
    		int b = vec[i]/a; //beta

			int first = vec[i];
			int second = vec[0];
			int add_1 = vec[i]/a;
			int add_2 = vec[0]*a;

			int temp_sum = total_sum - first-second + add_2 + add_1;
			if(temp_sum < mini)
				mini = temp_sum;
    	}

    }

    cout << mini << endl;


    
    
    
	return 0 ;

}
