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

    string s;
    cin >> s;

    int len = s.length();
    int i=0;
    int j=1;
    int count = 0;
    
    if(len == 1)
    {
        cout << "NO" << endl;
        return 0;
    }

    stack<char> st;
    //Handling Palindromic Strings with the help of Stack!
    for(int i=0;i<len;i++)
    {
        if(st.empty())
            st.push(s[i]);
        else
        {
            if(st.top() == s[i])
            {
                st.pop();
                count++;
            }
            else
                st.push(s[i]);
        }
    }
        
    //  cout << count << endl;
    if(count%2 == 0)
    	cout << "NO" << endl;
    else
    	cout << "YES" << endl;

	return 0 ; 

}



