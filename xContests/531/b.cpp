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
	int n,k;
	cin >> n >>k;

	int *count = new int[5001];
	for(int i=0;i<=5000;i++)
		count[i] = 0;

	int *input = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
		count[input[i]]++;
	}

	int max_count = -1;
	for(int i=0;i<=5000;i++)
		if(count[i] > max_count)
			max_count = count[i];

	if(max_count > k)
	{
		cout << "NO" << endl;
		return 0;
	}

	int *temp_count = new int[5001];
	int *temp_ans = new int[n];
	for(int i=0;i<=5000;i++)
		temp_count[i] = 0;

	for(int i=0;i<n;i++)
	{	
		temp_ans[i] = temp_count[input[i]]+1;
		temp_count[input[i]]++;
	}
	delete [] temp_count;

	int *arr = new int[k+1];

	for(int i=0;i<=k;i++)
		arr[i] = 0;

	for(int i=0;i<n;i++)
		arr[temp_ans[i]]++;

	/*  for(int i=0;i<=k;i++)
		cout << arr[i] << " ";
	cout << endl;  */

	int *tempCount = new int[k+1];
	for(int i=0;i<=k;i++)
		tempCount[i] = 0;

	int j = max_count+1;
	for(int i=0;i<n;i++)
	{
		if(j > k)
			break;
		if(tempCount[temp_ans[i]] == 0)
		{
			tempCount[temp_ans[i]]++;
			continue;
		}

		else
		{
			temp_ans[i] = j;
			j++;
		}


	}

	cout << "YES" << endl;
	for(int i=0;i<n;i++)
		cout << temp_ans[i] << " ";
	cout << endl;

	
	return 0 ; 

}



