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
	ll n;
	cin >> n;

	if(n == 3)
	{
		cout << 0 << endl;
		return 0;
	}

	if(n == 1 || n == 2)
	{
		cout << 1 << endl;
		return 0;
	}

	if(n%2 == 0)
	{
		if(n%4 == 0)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}

	else
	{
		if( (n+1)%4 == 0)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}
	
	return 0 ; 

}



