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
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

ll BFSUtil(int u, vector<int> adj[], vector<bool> &visited) 
{ 
  
    list<int> q; 
   
    visited[u] = true; 
    q.push_back(u); 
    ll count = 0;
    while(!q.empty()) 
    { 
        u = q.front(); 
        count++;
        q.pop_front(); 

        for (int i = 0; i != adj[u].size(); ++i) 
        { 
            if (!visited[adj[u][i]]) 
            { 
                visited[adj[u][i]] = true; 
                q.push_back(adj[u][i]); 
            } 
        } 
    } 

    return count;
} 

ll calculatePower(ll n, int k)
{
	ll product = 1;
	for(int i=0;i<k;i++)
	{
		product *= n;
		product %= MOD;
	}

	return product;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    vector<int> *adj = new vector<int>[n];
    for(int i=0;i<n-1;i++)
    {
    	int x,y,z;
    	cin >> x >> y >> z;

    	if(z == 0)
    	{
    		adj[x-1].pb(y-1);
    		adj[y-1].pb(x-1);
    	}
    }

    vector<bool> visited(n, false);
    vector<ll> count; 
    for (int u=0; u<n; u++) 
        if (visited[u] == false)
        	count.pb(BFSUtil(u, adj, visited)); 
    
    ll sum = 0;
    for(int i=0;i<count.size();i++)
    {
    	sum += calculatePower(count[i],k);
    	sum %= MOD;	
    }

    ll total = calculatePower(n,k);
    ll final = total - sum;
    if(final < 0)
    	final += MOD;

    cout << final << endl;
    
	return 0 ;

}
