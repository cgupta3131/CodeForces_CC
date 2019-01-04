#include<bits/stdc++.h>

using namespace std;


int degree(string s)
{
	stack<char> st;
	for(int i=0;i<s.length();i++)
	{
		if(s[i] == '(')
			st.push(s[i]);
		else if(s[i] == ')')
		{
			if(st.empty() == false && st.top() == '(')
				st.pop();
			else
				st.push(s[i]);
		}
	}

	int answer = st.size();

	if(answer == 0)
		return 0;

	char c = st.top();
	st.pop();

	while(!st.empty())
	{
		if(st.top() != c)
			return INT_MAX;
		st.pop();
	}

	if(c == '(')
		return answer;
	else
		return -1*answer;
}

int main()
{
	int n;
	cin >> n;

	string *input = new string[n];

	for(int i = 0; i < n; i++) 
		cin >> input[i];

	map<int, int> m;

	for(int i=0;i<n;i++)
	{
		int x = degree(input[i]);
		if(x < INT_MAX)
		{	
			if(m.find(x) == m.end()) //Means that we are not able to find 'x'
				m[x] = 1;
			else
				m[x]++;
		}
	}

	int total = 0;

	for(auto i = m.begin(); i != m.end();i++)
	{
		int x = i->first;
		if(m.find(-x) != m.end()){ //Means that we are able to find '-x' in our map
            total += min(i->second, m[-x]);
        }
	}

	cout << total/2 << endl;

	return 0 ; 

}

