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
    int ta, tb;
    int k;

    cin >> n >> m >> ta >> tb >> k;

    int *dep_A = new int[n];
    for(int i=0;i<n;i++)
    	cin >> dep_A[i];

   	int *dep_B = new int[m];
    for(int i=0;i<m;i++)
    	cin >> dep_B[i];
    
    int *arr_B = new int[n];
    int *arr_C = new int[m];

    for(int i=0;i<n;i++)
    	arr_B[i] = dep_A[i] + ta;

   	for(int i=0;i<m;i++)
   		arr_C[i] = dep_B[i] + tb;

   	if(k >= n)
   	{
   		cout << -1 << endl;
   		return 0;
   	}

   	int cur_idx_m = 0;
   	int cur_idx_n = 0;
   	int *aux = new int[n]; //this stores the number of flights that are available after 
   						   // arr_B[i] time;
   	for(int i=0;i<n;i++)
   		aux[i] = 0;

   	while(cur_idx_m < m && cur_idx_n < n)
   	{
   		if(dep_B[cur_idx_m] < arr_B[cur_idx_n]  )
   		{
   			aux[cur_idx_n]++;
   			cur_idx_m++;
   		}
   		else
   		{
   			cur_idx_n++;
   			aux[cur_idx_n] = aux[cur_idx_n-1];
   		}
   	}

   	cur_idx_n++;
   	while(cur_idx_n < n)
   	{
   		aux[cur_idx_n] = aux[cur_idx_n-1];
   		cur_idx_n++;
   	}

   	for(int i=0;i<n;i++)
   		aux[i] = m - aux[i];

   	/*for(int i=0;i<n;i++)
   		cout << aux[i] << " ";
   	cout << endl;	*/

   	if(k >= aux[0]) //will cancel all the incoming flights
   	{
 		cout << -1 << endl;
   		return 0;
   	}

   	long long int maxi = INT_MIN;
   	for(int l=0;l<=k;l++)
   	{
   		int r = k-l;

   		int x = aux[l]; //the current arriving flight player takes
   		int y = x-r; //number of departing flights from B

   		if(y <= 0)
   		{
   			cout << -1 << endl;
   			return 0;
   		}
   		long long int time = dep_B[m-y];
   		long long int final_time = time+tb;

   		if(final_time > maxi)
   		{
   			//cout << l << " " << r << " " << final_time << endl;
   			maxi = final_time;
   		}
   	}

   	cout << maxi << endl;

	return 0 ;

}
