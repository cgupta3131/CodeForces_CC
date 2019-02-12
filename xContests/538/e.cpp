//#pragma comment(linker, "/stack:247474112")
//#pragma GCC optimize("Ofast")
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
	mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;
  	v.resize(n);
  	for(int i=0;i<n;i++)
  		v[i] = i+1;
  	for(int i=0;i<v.size();i++)
  		cout << v[i] << endl;

    int query_left = 60;
    //int left = -1000000005;
    int left =  999999995;
    int right = 1000000005;
    int largest_value = -1;

    while(right - left >=1)
    {
    	int mid = (right+left)/2;
    	cout << "> " << mid << endl;
    	fflush(stdout);
    	query_left--;
    	int value;
    	cin >> value;

    	if(value == 0)
    	{
    		right = mid;
    		largest_value = mid;
    	}
    	else
    		left = mid+1;
    }

    cout << "largest_value : " << largest_value << endl;

  	vector<int> list;
  	int random_range = n;

	while(query_left--)
	{
		if(random_range < 0)
			break;

		int index = rng32() % random_range;
		cout << "? " << v[index] << endl;
		fflush(stdout);

		int z;
		cin >> z;
		list.pb(z);
		random_range--;
		swap(v[index],v[random_range]);
	}

    sort( list.begin(), list.end() );

    if(list.back() != largest_value)
    	list.pb(largest_value);
    
    int d = 0;
    for(int i=1;i<list.size();i++)
    	d = __gcd( d,list[i]-list[i-1] );

    int mini = largest_value - d*(n-1);
    cout << "! " << mini << " " << d << endl;
    fflush(stdout);
	return 0 ;

}
