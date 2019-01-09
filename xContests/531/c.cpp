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
	int n,x,y;
	cin >> n >> x >> y;

	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];

	if(x > y)
		cout << n << endl;
	if(x <= y)
	{
		int count = 0; //counts the number of doors with durability 
					   //less than or equal to x
		for(int i=0;i<n;i++)
			if(arr[i] <= x)
				count++;

		if(count%2 == 0)
			cout << count/2 << endl;
		else
			cout << (count+1)/2 << endl;
	}
	
	return 0 ; 

}



