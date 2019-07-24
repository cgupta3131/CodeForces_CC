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

    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;

    int a = s1[0] - '0';
	int b = s2[0] - '0';
	int c = s3[0] - '0';

    if(s1[0] == s2[0] && s2[0] == s3[0] && s1[1] == s2[1] && s2[1] == s3[1])
    	cout << 0 << endl;
    else
    {
    	if(s1[1] == s2[1] && s2[1] == s3[1]) //same suit
    	{
    		//cout << "Chirag" << endl;
    		vector<int> temp;
    		temp.push_back(a);
    		temp.push_back(b);
    		temp.push_back(c);

    		sort(temp.begin(), temp.end());
    		int x = temp[0];
    		int y = temp[1];
    		int z = temp[2];

    		if(y == x+1 && z == y+1)
    		{
    			cout << 0 << endl;
    			return 0;
    		}

    		if(y == x+1 || z == y+1)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		if(y == x || z == y)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		if(y == x+2 || z == y+2)
    		{
    			cout << 1 << endl;
    			return 0;
    		}	

    		else
    		{
    			cout << 2 << endl;
    			return 0;
    		}
    	}

    	else if(s1[1] == s2[1]) //two cards same suit
    	{
    		int x = min(a,b);
    		int y = max(a,b);

    		if(x == y)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		if(y == x+1)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		if(y == x+2)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		else
    		{
    			cout << 2 << endl;
    			return 0;
    		}
    	}

    	else if(s2[1] == s3[1]) //two cards same suit
    	{
    		int x = min(b,c);
    		int y = max(b,c);

    		if(x == y)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		if(y == x+1)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		if(y == x+2)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		else
    		{
    			cout << 2 << endl;
    			return 0;
    		}
    	}

    	else if(s1[1] == s3[1]) //two cards same suit
    	{
    		int x = min(a,c);
    		int y = max(a,c);

    		if(x == y)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		if(y == x+1)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		if(y == x+2)
    		{
    			cout << 1 << endl;
    			return 0;
    		}

    		else
    		{
    			cout << 2 << endl;
    			return 0;
    		}
    	}

    	else
    	{
    		cout << 2 << endl;
    		return 0;
    	}



    }
    
    
	return 0 ;

}
