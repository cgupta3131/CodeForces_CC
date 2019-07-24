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

    if(n == 2)
    {
    	cout << "YES" << endl;
    	return 0;
    }

    if(n == 3)
    {
    	cout << "NO" << endl;
    	return 0;
    }

    //vector<pii> vec;
    pii *arr = new pii[2*(n-1)];
    for(int i=0;i<n-1;i++)
    {
    	int a,b;
    	cin >> arr[i].f >> arr[i].s;
    	//pair<int,int> p1(a,b);
    	//pair<int,int> p1(b,a);

    	/*vec.push_back(p1);
    	vec.push_back(p2);*/
    }

    //(vec.begin(), vec.end());
	//sort(arr,arr+n);

	int *count = new int[n+1];
	for(int i=0;i<=n;i++)
		count[i] = 0;

	for(int i=0;i<n-1;i++)
	{
		//cout << arr[i].f << " " << arr[i].s <<endl;
		count[arr[i].f]++;
		count[arr[i].s]++;
	}

	/*for(int i=1;i<=n;i++)
		cout << count[i] << " ";
	cout << endl;*/

	for(int i=1;i<=n;i++)
	{
		if(count[i] == 2)
		{
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

    
	return 0 ;

}