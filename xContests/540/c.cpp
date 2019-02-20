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

    int matrix[n][n];

    int *arr = new int[n*n];
    for(int i=0;i<n*n;i++)
    	cin >> arr[i];

    if(n == 1)
    {
    	cout << "YES" << endl;
    	cout << arr[0] << endl;
    	return 0;
    }

    if(n%2 == 0)
    {
    	int *list = new int[(n/2)*(n/2)];
    	int *count = new int[1005];
    	for(int i=0;i<1005;i++)
    		count[i] = 0;
    	for(int i=0;i<n*n;i++)
    		count[arr[i]]++;

    	int flag = 0;
    	for(int i=0;i<1005;i++)
    	{
    		if(count[i]%4 != 0)
    		{
    			flag = 1;
    			break;
    		}
    	}

    	if(flag == 1)
    	{
    		cout << "NO" << endl;
    		return 0;
    	}

    	int idx = 0;
    	for(int i=0;i<1005;i++)
    	{
    		if(count[i] != 0)
    		{
    			int inc = count[i]/4;
    			for(int j=0;j<inc;j++)
    				list[idx++] = i; 
    		}
    	}

    	cout << "YES" << endl;

    	for(int i=0;i<(n/2);i++)
    	{
    		int start_idx = (i)*(n/2); //starting index in the array list
    		for(int j=0;j<(n/2);j++)
    			matrix[i][j] = list[start_idx++];

    		start_idx = (i)*(n/2);
    		for(int j=n-1;j>=n/2;j--)
    			matrix[i][j] = list[start_idx++];
    	}

    	for(int i=n-1;i>=(n/2);i--)
    	{
    		int start_idx = (n-i-1)*(n/2); //starting index in the array list
    		for(int j=0;j<(n/2);j++)
    			matrix[i][j] = list[start_idx++];

    		start_idx = (n-i-1)*(n/2);
    		for(int j=n-1;j>=n/2;j--)
    			matrix[i][j] = list[start_idx++];
    	}

    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    			cout << matrix[i][j] << " ";
    		cout << endl;
    	}


    }


    if(n%2 == 1) //odd number of states
    {
    	int *list4 = new int[((n-1)/2)*((n-1)/2)];
    	int *list2 = new int[n-1];
    	int *list1 = new int[1];

    	int *count = new int[1005];
    	int *aux = new int[1005];
    	for(int i=0;i<1005;i++)
    	{
    		aux[i] = 0;
    		count[i] = 0;
    	}
    	for(int i=0;i<n*n;i++)
    	{
    		aux[arr[i]]++;
    		count[arr[i]]++;
    	}

    	int flag = 0;
    	int count4 = 0;
    	int idx = 0;

    	for(int j=400;j>=0;j--)
	    {
	    	for(int i=0;i<1005;i++)
	    	{
	    		if(count4 == pow( ((n-1)/2),2 ) )
	    			break;
	    		if(aux[i] >= 4)
	    		{
	    			list4[idx++] = i;
	    			aux[i] -= 4;
	    			count4++;
	    		}
	    	}
    	}

    	//cout << count4 << endl;
    	if( count4 != pow( ((n-1)/2),2 ) )
    	{
    		cout << "NO" << endl;
    		return 0;
    	}

    	idx=0;
    	int count2 = 0;
    	for(int j=400;j>=0;j--)
	    {
	    	for(int i=0;i<1005;i++)
	    	{
	    		if(count2 == (n-1) )
	    			break;
	    		if(aux[i] >=2)
	    		{
	    			list2[idx++] = i;
	    			aux[i] -= 2;
	    			count2++;
	    		}
	    	}
    	}

    	if(count2 != (n-1) )
    	{
    		cout << "NO" << endl;
    		return 0;
    	}

    	idx=0;
    	int count1 = 0;
    	for(int i=0;i<1005;i++)
    	{
    		if(aux[i] > 0)
    		{
    			list1[idx++] = i;
    			aux[i] -= 1;
    			count1++;
    		}
    	}

    	if(count1 != 1)
    	{
    		cout << "NO" << endl;
    		return 0;
    	}

    	cout << "YES" << endl;

    	for(int i=0;i<(n/2);i++)
    	{
    		int start_idx = (i)*(n/2); //starting index in the array list
    		for(int j=0;j<(n/2);j++)
    			matrix[i][j] = list4[start_idx++];

    		start_idx = (i)*(n/2);
    		for(int j=n-1;j>=(n+1)/2;j--)
    			matrix[i][j] = list4[start_idx++];
    	}

    	for(int i=n-1;i>=((n+1)/2);i--)
    	{
    		int start_idx = (n-i-1)*(n/2); //starting index in the array list
    		for(int j=0;j<(n/2);j++)
    			matrix[i][j] = list4[start_idx++];

    		start_idx = (n-i-1)*(n/2);
    		for(int j=n-1;j>=(n+1)/2;j--)
    			matrix[i][j] = list4[start_idx++];
    	}

    	for(int i=0;i<(n/2);i++)
    		matrix[i][(n-1)/2] = list2[i];

    	for(int i=n-1;i>=((n+1)/2);i--)
    		matrix[i][(n-1)/2] = list2[n-i-1];

    	for(int i=0;i<(n/2);i++)
    		matrix[(n-1)/2][i] = list2[i+((n-1)/2)];

    	for(int i=n-1;i>=((n+1)/2);i--)
    		matrix[(n-1)/2][i] = list2[n-i-1+((n-1)/2)];

    	matrix[(n-1)/2][(n-1)/2] = list1[0];

    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    			cout << matrix[i][j] << " ";
    		cout << endl;
    	}


    }
    
    
	return 0 ;

}
