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

    ll n;
    cin >> n;

    if(n == 1)
    {
    	cout << 1 << endl;
    	return 0;
    }

    ll *arr = new ll[n];
    for(ll i=0;i<n;i++)
    	cin >> arr[i];

    ll count = 0;

    ll *aux = new ll[n];
    for(ll i=0;i<n;i++)
    	aux[i] = 0;
    	
    aux[0] = arr[0];
    aux[1] = arr[1];

    for(ll i=2;i<n;i=i+2)
    	aux[i] = aux[i-2] + arr[i];

    for(ll i=3;i<n;i=i+2)
    	aux[i] += aux[i-2] + arr[i];

    /*for(int i=0;i<n;i++)
    	cout <<  aux[i] << " ";
    cout << endl;*/

    for(ll i=0;i<n;i++) //removing the ith candy
    {
    	if(n%2 == 1) //odd number of elements
    	{
    		ll second_last = aux[n-2];
    		ll last = aux[n-1];

    		if(i%2 == 1)
    		{
    			ll sum1 = second_last - aux[i] + aux[i-1];
    			ll sum2;
    			if(i-2>=0)
    				sum2 = aux[i-2] + last - aux[i-1];
    			else
    				sum2 = last - aux[i-1];

    			if(sum1 == sum2)
    			{
    				//cout << i << endl;
    				count++;
    			}
    		}

    		else
    		{
    			ll sum1; 
    			ll sum2;
    			if(i-1>=0)
    				sum1 = aux[i-1] + last - aux[i];
    			else
    				sum1 = last - aux[i];

    			if(i-2>=0)
    				sum2 = aux[i-2] + second_last - aux[i-1];
    			else
    				sum2 = second_last;

    			if(sum1 == sum2)
    			{
    				//cout << i << endl;
    				count++;
    			}

    		}
    	}

    	if(n%2 == 0) //odd number of elements
    	{
    		ll second_last = aux[n-2]; //even indices
    		ll last = aux[n-1]; //odd indicies

    		if(i%2 == 1)
    		{
    			ll sum1 = last - aux[i] + aux[i-1];
    			ll sum2;
    			if(i-2>=0)
    				sum2 = aux[i-2] + second_last - aux[i-1];
    			else
    				sum2 = second_last - aux[i-1];

    			if(sum1 == sum2)
    			{
    				//cout << i << endl;
    				count++;
    			}
    		}

    		else
    		{
    			ll sum1; 
    			ll sum2;
    			if(i-1>=0)
    				sum1 = aux[i-1] + second_last - aux[i];
    			else
    				sum1 = second_last - aux[i];

    			if(i-2>=0)
    				sum2 = aux[i-2] + last - aux[i-1];
    			else
    				sum2 = last;

    			if(sum1 == sum2)
    			{
    				//cout << i << endl;
    				count++;
    			}

    		}
    	}
    }	

    cout << count << endl;

    
    
	return 0 ;

}
