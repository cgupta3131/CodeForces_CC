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

    int n,m;
    cin >> n >> m;

    int A[n][m];
    int B[n][m];

    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		cin >> A[i][j];

    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		cin >> B[i][j];

    for(int i=0;i<m;i++)
    {
    	//index being (0,i)
    	int idx1 = 0;
    	int idx2 = i;

    	vector<int> a;
    	vector<int> b;
    	while(1)
    	{
    		if(idx2 < 0 || idx1 >= n)
    			break;
    		a.pb(A[idx1][idx2]);
    		b.pb(B[idx1][idx2]);

    		idx1++;
    		idx2--;
    	}

    	sort(a.begin(), a.end());
    	sort(b.begin(), b.end());

    	for(int j=0;j<a.size();j++)
    	{
    		if(a[j] != b[j])
    		{
    			cout << "NO" << endl;
    			return 0;
    		}
    	}
    }

    for(int i=0;i<m;i++)
    {
    	//index being (n-1,i)
    	int idx1 = n-1;
    	int idx2 = i;

    	vector<int> a;
    	vector<int> b;
    	while(1)
    	{
    		if(idx2 >= m || idx1 < 0)
    			break;
    		a.pb(A[idx1][idx2]);
    		b.pb(B[idx1][idx2]);

    		idx1--;
    		idx2++;
    	}

    	sort(a.begin(), a.end());
    	sort(b.begin(), b.end());

    	for(int j=0;j<a.size();j++)
    	{
    		if(a[j] != b[j])
    		{
    			cout << "NO" << endl;
    			return 0;
    		}
    	}
    }

    for(int i=0;i<n;i++)
    {
    	//index being (i,0)
    	int idx1 = i;
    	int idx2 = 0;

    	vector<int> a;
    	vector<int> b;
    	while(1)
    	{
    		if(idx2 >= m || idx1 < 0)
    			break;
    		a.pb(A[idx1][idx2]);
    		b.pb(B[idx1][idx2]);

    		idx1--;
    		idx2++;
    	}
    	
    	/*for(int j=0;j<a.size();j++)
    		cout << a[j] << " ";
    	cout << endl;
    	for(int j=0;j<b.size();j++)
    		cout << b[j] << " ";
    	cout << endl;*/
    	sort(a.begin(), a.end());
    	sort(b.begin(), b.end());

    	for(int j=0;j<a.size();j++)
    	{
    		if(a[j] != b[j])
    		{
    			cout << "NO" << endl;
    			return 0;
    		}
    	}
    }

    for(int i=0;i<n;i++)
    {
    	//index being (i,m-1)
    	int idx1 = i;
    	int idx2 = m-1;

    	vector<int> a;
    	vector<int> b;
    	while(1)
    	{
    		if(idx2 < 0 || idx1 >=n)
    			break;
    		a.pb(A[idx1][idx2]);
    		b.pb(B[idx1][idx2]);

    		idx1++;
    		idx2--;
    	}
    	
    	sort(a.begin(), a.end());
    	sort(b.begin(), b.end());

    	for(int j=0;j<a.size();j++)
    	{
    		if(a[j] != b[j])
    		{
    			cout << "NO" << endl;
    			return 0;
    		}
    	}
    }

    cout << "YES" << endl;

	    
	return 0 ;

}
