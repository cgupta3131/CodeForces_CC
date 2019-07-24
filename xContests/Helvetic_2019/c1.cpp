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

    pii *arr = new pii[4*n+1];
    pii *aux = new pii[4*n+1];

   	map<int, int> m1;
    map<int, int> m2;

    for(int i=0;i<(4*n+1);i++)
    {
    	int a;
    	int b;
    	cin >> a >> b;

  	    if(m1.find(a) == m1.end())
	    	m1[a] = 1;
	    else
	    	m1[a] += 1;

	    if(m2.find(b) == m2.end())
	    	m2[b] = 1;
	    else
	    	m2[b] += 1;


    	/*arr[i].f = a;
    	arr[i].s = b;

    	aux[i].f = b;
    	aux[i].s = a;*/
    }

    /*sort(arr,arr+(4*n+1));
    sort(aux,aux+(4*n+1));*/

    int idx1 = -1;
    int idx2 = -1;

    if(m1.size() == n+2)
    {
    	for(auto i=m1.begin();i != m1.end() ; i++)
    	{
    		if(i->second == 1)
    		{
    			idx1 = i->first;
    			break;
    		}
    	}
    }

    else
    {
    	int count = 0;
    	for(auto i=m1.begin();i != m1.end();i++)
    	{
    		count++;
    		if(count == 1 || count == n+1)
    		{
    			if(i->second == n+2)
    			{
    				idx1 = i->first;
    				break;
    			}
    		}

    		else
    		{
    			if(i->second == 3)
    			{
    				idx1 = i->first;
    				break;
    			}
    		}

    	}
    }



    if(m2.size() == n+2)
    {
    	for(auto i=m2.begin();i != m2.end() ; i++)
    	{
    		if(i->second == 1)
    		{
    			idx2 = i->first;
    			break;
    		}
    	}
    }

    else
    {
    	int count = 0;
    	for(auto i=m2.begin();i != m2.end();i++)
    	{
    		count++;
    		if(count == 1 || count == n+1)
    		{
    			if(i->second == n+2)
    			{
    				idx2 = i->first;
    				break;
    			}
    		}

    		else
    		{
    			if(i->second == 3)
    			{
    				idx2 = i->first;
    				break;
    			}
    		}

    	}
    }

    cout << idx1 << " " << idx2 << endl;
    
 	


    
    
	return 0 ;

}
