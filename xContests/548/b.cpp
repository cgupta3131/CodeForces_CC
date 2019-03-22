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

    ll *input = new ll[n];

    for(int i=0;i<n;i++)
    	cin >> input[i];

    if(n == 1)
    {
    	cout << input[0] << endl;
    	return 0;
    }

    ll total_sum = input[n-1];
    ll prev = input[n-1];

    for(int i=n-2;i>=0;i--)
    {
    	if(prev == 0)
    		break;
    	if(input[i] < prev)
    	{
    		//cout << input[i] << endl;
    		total_sum += input[i];
    		prev = input[i];
    		continue;
    	}

    	else if(input[i] == prev)
    	{
    		total_sum += prev- 1;
    		prev = prev - 1;
    	}

    	else
    	{
    		total_sum += prev-1;
    		prev = prev-1;
    	}
    }

    cout << total_sum << endl;

	return 0 ;

}
