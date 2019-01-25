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
int angles[181];

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    for(int i=3;i<=180;i++) //i denotes i sided polygon
    {
    	int temp_gcd = gcd(180,i);
		int ang = 180/temp_gcd;
		for(int j=1;j<=i-2;j++)
		{
			int temp_ang = ang*j;
			if(temp_ang<180 && angles[temp_ang] == 0)
				angles[temp_ang] = i;
		}
    }	

    angles[179] = 360;
    int t;
    cin >> t;

    while(t--)
    {
    	int ang;
    	cin >> ang;

    	cout << angles[ang] << endl;
    }

	return 0 ; 

}



