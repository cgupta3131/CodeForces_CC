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

    string s;
    cin >> s;

    if(n == 1)
    {
    	cout << 0 << endl;
    	cout << s << endl;
    	return 0;
    }

    if(n == 2)
    {
    	if(s[0] == s[1])
    	{
    		cout << 1 << endl;
    		if(s[0] == 'G')
    			cout << "GB" << "\n";
    		else if(s[0] == 'B')
    			cout << "BR" << "\n";
    		else if(s[0] == 'R')
    			cout << "RG" << "\n";
    		return 0;
    	}

    	else
    	{
    		cout << 0 << endl;
    		cout << s << endl;
    		return 0;	
    	}
    }


    int max = -1;
    int conf = -1;
    int count = 0;
    
    for(int i=0;i<n;i++)
    {
    	if(i%3 == 0 && s[i] == 'R')
    		count++;
    	if(i%3 == 1 && s[i] == 'G')
    		count++;
    	if(i%3 == 2 && s[i] == 'B')
    		count++;
    }

    if(count > max)
    {
    	max = count;
    	conf = 1;
    }

    count = 0;
    for(int i=0;i<n;i++)
    {
    	if(i%3 == 0 && s[i] == 'R')
    		count++;
    	if(i%3 == 2 && s[i] == 'G')
    		count++;
    	if(i%3 == 1 && s[i] == 'B')
    		count++;
    }

    if(count > max)
    {
    	max = count;
    	conf = 2;
    }

    count = 0;
    for(int i=0;i<n;i++)
    {
    	if(i%3 == 1 && s[i] == 'R')
    		count++;
    	if(i%3 == 0 && s[i] == 'G')
    		count++;
    	if(i%3 == 2 && s[i] == 'B')
    		count++;
    }

    if(count > max)
    {
    	max = count;
    	conf = 3;
    }

    count = 0;
    for(int i=0;i<n;i++)
    {
    	if(i%3 == 1 && s[i] == 'R')
    		count++;
    	if(i%3 == 2 && s[i] == 'G')
    		count++;
    	if(i%3 == 0 && s[i] == 'B')
    		count++;
    }

    if(count > max)
    {
    	max = count;
    	conf = 4;
    }

    count = 0;
    for(int i=0;i<n;i++)
    {
    	if(i%3 == 2 && s[i] == 'R')
    		count++;
    	if(i%3 == 0 && s[i] == 'G')
    		count++;
    	if(i%3 == 1 && s[i] == 'B')
    		count++;
    }

    if(count > max)
    {
    	max = count;
    	conf = 5;
    }

    count = 0;
    for(int i=0;i<n;i++)
    {
    	if(i%3 == 2 && s[i] == 'R')
    		count++;
    	if(i%3 == 1 && s[i] == 'G')
    		count++;
    	if(i%3 == 0 && s[i] == 'B')
    		count++;
    }

    if(count > max)
    {
    	max = count;
    	conf = 6;
    }

    cout << n - max << endl;

    if(conf == 1)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(i%3==0)
    			cout << "R";
    		else if(i%3 == 1)
    			cout << "G";
    		else
    			cout << "B";
    	}
    	cout << endl;
    }


    if(conf == 2)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(i%3==0)
    			cout << "R";
    		else if(i%3 == 2)
    			cout << "G";
    		else
    			cout << "B";
    	}
    	cout << endl;
    }


    if(conf == 3)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(i%3==1)
    			cout << "R";
    		else if(i%3 == 0)
    			cout << "G";
    		else
    			cout << "B";
    	}
    	cout << endl;
    }

    if(conf == 4)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(i%3==1)
    			cout << "R";
    		else if(i%3 == 2)
    			cout << "G";
    		else
    			cout << "B";
    	}
    	cout << endl;
    }

    if(conf == 5)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(i%3==2)
    			cout << "R";
    		else if(i%3 == 0)
    			cout << "G";
    		else
    			cout << "B";
    	}
    	cout << endl;
    }

    if(conf == 6)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(i%3==2)
    			cout << "R";
    		else if(i%3 == 1)
    			cout << "G";
    		else
    			cout << "B";
    	}
    	cout << endl;
    }

	
	return 0 ; 

}



