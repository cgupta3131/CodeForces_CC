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
    int a,b,c;

    cin >> x >> y >> z >> a >> b >> c;
    
    a -= x;
    if(a<0)
    {
    	cout << "NO" << endl;
    	return 0;
    }


   	if(y >= b)
   	{
   		y -= b;
   		b=0;
   		a -= y;

   		if(a<0)
   		{
   			cout << "NO" << endl;
    		return 0;
   		}

   		else
   		{
   			int sum = a+b+c;
   			if(z <= sum)
   			{
   				cout << "YES" << endl;
   				return 0;
   			}

   			else
   			{
   				cout << "NO" << endl;
    			return 0;
   			}
   		}
   	}

   	if(y < b)
   	{
   		b -= y;
   		int sum = a+b+c;
   		if(z <= sum)
		{
			cout << "YES" << endl;
			return 0;
		}

		else
		{
			cout << "NO" << endl;
		return 0;
		}

   	}
    
	return 0 ;

}