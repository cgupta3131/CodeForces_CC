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

    int *input = new int[n-1];
    for(int i=0;i<n-1;i++)
    	cin >> input[i];
    
    int *aux = new int[n];
    aux[0] = 0;

    for(int i=0;i<n-1;i++)
    	aux[i+1] = aux[i] + input[i];
    // for(int i=0;i<n;i++)
    // 	cout << aux[i] << " ";
    // cout << endl;

    int min = 2*n;
    for(int i=0;i<n;i++)
    	if(aux[i] < min)
    		min = aux[i];

    // min is atmost 0;

    int x = -1*min + 1;
    
    for(int i=0;i<n;i++)
    	aux[i] += x;
    // for(int i=0;i<n;i++)
    // 	cout << aux[i] << " ";
    // cout << endl;

    int *temp = new int[n];

    for(int i=0;i<n;i++)
    	temp[i] = aux[i];

    sort(temp,temp+n);
    // for(int i=0;i<n;i++)
    // 	cout << temp[i] << " ";
    // cout << endl;

    int flag = 0;

    for(int i=1;i<=n;i++)
    {
    	if(temp[i-1] != i)
    	{
    		flag = 1;
    		break;    
    	}
    }

    if(flag == 1)
    	cout << -1 << endl;
    else
    {
    	for(int i=0;i<n;i++)
    		cout << aux[i] << " ";
    	cout << endl;
    }
    
	return 0 ;

}
