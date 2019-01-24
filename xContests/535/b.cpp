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

	int *arr  = new int[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];

	sort(arr,arr+n);

	int x =arr[n-1];
	int y = 1;

	if(arr[n-2] == x)
	{
		y =x;
		cout << x << " " << y << "\n";
		return 0;
	}


	for(int i=n-2;i>=0;i--)
	{
		if(i-1>=0 && arr[i] == arr[i-1])
		{
			y = arr[i];
			break;
		}

		if( x % arr[i] == 0)
			continue;

		else
		{
			y = arr[i];
			break;
		}

	}

	cout << x << " " << y << "\n";

	return 0 ; 

}



