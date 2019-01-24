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

    string s;
    cin >> s;
    
    if(n == 1)
    {
    	cout << 0 << endl;
    	cout << s << endl;
    	return 0;
    }

    vector<pii> myvec; //index, length

    int len = 1;
    for(int i=0;i<n;i++)
    {
    	if(s[i] == s[i+1])
    		len++;
    	else
    	{
    		if(len >= 2)
    		{
    			pii temp = mp(i-len+1, len);
    			myvec.pb(temp);
    		}
	    		len = 1;
    	}
    }
    //for(int i=0;i<myvec.size();i++)
    //	cout << myvec[i].f << " " << myvec[i].s << endl;
    	
    int count = 0;
	for(int i=0;i<myvec.size();i++)
	{
		int index = myvec[i].f;
		int len = myvec[i].s;

		if(len == 2)
		{
			if(s[index] == 'B')
			{
				if(s[index+2] == 'G')
					s[index+1] = 'R';
				else
					s[index+1] = 'G';
			}

			else if(s[index] == 'G')
			{
				if(s[index+2] == 'B')
					s[index+1] = 'R';
				else
					s[index+1] = 'B';
			}

			else if(s[index] == 'R')
			{
				if(s[index+2] == 'B')
					s[index+1] = 'G';
				else
					s[index+1] = 'B';
			}

			count++;
		}
			
		else
		{
			if(index+len >=n )
			{
				if(s[index] == 'B')
				{
					for(int j=index+1;j<index+len;j+=2)
					{
						count++;
						s[j] = 'R';
					}
				}

				if(s[index] == 'R')
				{
					for(int j=index+1;j<index+len;j+=2)
					{
						count++;
						s[j] = 'B';
					}
				}

				if(s[index] == 'G')
				{
					for(int j=index+1;j<index+len;j+=2)
					{
						count++;
						s[j] = 'R';
					}
				}

				continue;
			}
			if(s[index+len] == 'G')
			{
				if(s[index] == 'B')
				{
					for(int j=index+1;j<index+len;j+=2)
					{
						count++;
						s[j] = 'R';
					}
				}

				else if(s[index] == 'R')
				{
					for(int j=index+1;j<index+len;j+=2)
					{
						count++;
						s[j] = 'B';
					}
				}
			}


			if(s[index+len] == 'B')
			{
				if(s[index] == 'G')
				{
					for(int j=index+1;j<index+len;j+=2)
					{
						count++;
						s[j] = 'R';
					}
				}

				else if(s[index] == 'R')
				{
					for(int j=index+1;j<index+len;j+=2)
					{
						count++;
						s[j] = 'G';
					}
				}
			}

			if(s[index+len] == 'R')
			{
				if(s[index] == 'B')
				{
					for(int j=index+1;j<index+len;j+=2)
					{
						count++;
						s[j] = 'G';
					}
				}

				else if(s[index] == 'G')
				{
					for(int j=index+1;j<index+len;j+=2)
					{
						count++;
						s[j] = 'B';
					}
				}
			}
		}
	}	

	cout << count << endl;
	cout << s << endl;
	return 0 ; 

}



