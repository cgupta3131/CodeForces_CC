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

    int n,m,k;
    cin >> n >> m >> k;

    ll *input = new ll[n];
    ll *sorted = new ll[n];
    for(int i=0;i<n;i++)
    {
    	cin >> input[i];
    	sorted[i] = input[i];
    }

    sort(sorted,sorted+n, greater<ll>());
    int l = m*k; //lth smallest number
    int num = 0;
    int count_smallest = 0;

    for(int i=0;i<n;i++)
    {
    	if(i == l-1)
    	{
    		num = sorted[i];
    		break;
    	}
    }
    
   	ll total_sum = 0;
    for(int i=0;i<l;i++)
    {
    	total_sum += sorted[i];
    	if(sorted[i] == num)
    		count_smallest++;
    }

    vector<int> sequence;
    int check_smallest = 0;
    int subarrays = 0;
    int temp_count = 0; //when this becomes 'm', we will reset everything

    for(int i=0;i<n;i++)
    {	
    	if(subarrays == k-1)
    		break;
    	if(input[i] > num)
    		temp_count++;
    	if(input[i] == num && check_smallest < count_smallest) 
    	{
    		check_smallest++;
    		temp_count++;
    	}

    	if(temp_count == m)
    	{
    		temp_count = 0;
    		sequence.pb(i+1);
    		subarrays += 1;
    	}
    }	

    cout << total_sum << endl;
    for(int i=0;i<sequence.size();i++)
    	cout << sequence[i] << " ";
    cout << endl;
    
	return 0 ;

}
