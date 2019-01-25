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
#define MOD 998244353

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll len;
    cin >> len;
    string s;
    cin >> s;
  

	ll front_len = 1; //give ll as typecast always unless very small integers!!
    for(ll i=0;i<len-1;i++)
    {
    	if(s[i] == s[i+1])
    		front_len++;
    	else
    		break;
    }

    ll back_len = 1;
    for(ll i=len-1;i>0;i--)
    {
    	if(s[i] == s[i-1])
    		back_len++;
    	else
    		break;
    }


    if(s[0] == s[len-1])
    	cout << ((front_len+1)*(back_len+1))%MOD << endl;
    else
    	cout << ((front_len+back_len+1))%MOD << endl;


	return 0 ; 

}



