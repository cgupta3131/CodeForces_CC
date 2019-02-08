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

ll greatestDivisor(ll n)
{
	ll max = 1;
	for (int i=2; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
            {

                if(i > max)
                	max = i;
            }
  
            else // Otherwise print both 
            {
                if(i > max)
                	max = i;
                if(n/i > max)
                	max = n/i;
            }
        } 
    }

    return max;	
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll q;
    cin >> q;

    while(q--)
    {
    	ll a;
    	cin >> a;
    	int flag = 0;
    	int i;
    	ll temp = 0;
    	for(i=2;i<=25;i++)
    	{
    		temp = pow(2,i) - 1;
    		if(temp == a)
    		{
    			flag = 1;
    			break;
    		}

    		if(temp > a)
    			break;
    	}


    	if(flag == 1)
    	{
    		cout << greatestDivisor(a) << endl;
    	}
    	else
    		cout << temp << endl;

    }
    
    
    
	return 0 ;

}
