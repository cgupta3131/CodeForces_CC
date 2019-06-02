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

    int x,y,z;
    cin >> x >> y >> z;

    long long int len = 0;

    len += z*2; //using all ab one's
    z = 0;

    
	int mini = min(x,y);
	len += mini*2;

	x -= mini;
	y -= mini;

	//starting with a and ending with b
	if(x > 0)
	{
		x--;
		len += 1;
	}

	if(y > 0) //add in starting
	{
		y--;
		len += 1;
	}

	cout << len << endl;
    
	return 0 ;

}
	
											