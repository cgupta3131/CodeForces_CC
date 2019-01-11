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
	string input;
	cin >> input;

	int len = input.length();

	int open = 0;
	int close = 0;
	int colon = 0;
	int vertical = 0;


	for(int i=0;i<len;i++)
	{
		if(input[i] == '[')
			open++;
		if(input[i] == ']')
			close++;
		if(input[i] == ':')
			colon++;
		if(input[i] == '|')
			vertical++;
	}

	if(colon < 2)
	{
		cout << -1 << endl;
		return 0;
	}

	if(open == 0 || close == 0)
	{
		cout << -1 << endl;
		return 0;

	}


	int start=0;
	int end = len-1;



	for(int i=0;i<len;i++)
	{
		if(input[i] == '[')
		{
			start = i;
			break;
		}
	}

	for(int i=len-1;i>=0;i--)
	{
		if(input[i] == ']')
		{
			close = i;
			break;
		}
	}
	

	int count =0;
	int colon_start;
	int colon_end;

	for(int i=start+1;i<close;i++)
	{
		if(input[i] == ':')
		{
			colon_start = i;
			break;
		}
	}
	//cout << "hey" << endl;
	for(int i=close-1;i>=start;i--)
	{
		if(input[i] == ':')
		{
			colon_end = i;
			break;
		}
	}

	if(colon_start == colon_end)
	{
		cout << -1 << endl;
		return 0;
	}


	for(int i=colon_start;i<colon_end;i++)
	{
		if(input[i] == '|')
			count++;
	}

	cout << count + 4 << endl;

	return 0 ; 

}



