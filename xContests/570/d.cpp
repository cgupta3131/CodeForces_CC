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

    int q;
    cin >> q;

    while(q--)
    {
    	int n;
    	cin >> n;

    	int *arr = new int[n];

    	for(int i=0;i<n;i++)
    		cin >> arr[i];

    	int *count = new int[n+1];
    	for(int i=0;i<=n;i++)
    		count[i] = 0;

    	for(int i=0;i<n;i++)
    		count[arr[i]]++;

    	vector<int> aux;

    	for(int i=0;i<=n;i++)
    	{
    		if(count[i] != 0)
    		{
    			aux.push_back(count[i]);
    		}
    	}	

    	sort(aux.begin(), aux.end(), greater<int>());
    	/*for(int i=0;i<aux.size();i++)
    		cout << aux[i] << " ";
    	cout << endl;*/
    	int final = aux[0];
    	for(int i=1;i<aux.size();i++)
    	{
    		if(aux[i] >= aux[i-1])
    			aux[i] = aux[i-1] - 1;
    		final += aux[i];
    		if(aux[i] == 0)
    			break;
    	}

    	cout << final << endl;
    }
    
    
	return 0 ;

}

