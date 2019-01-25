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

	vector<int> vec1;
	vector<int> vec2;

	int perfect_count = 0;

	for(int i=0;i<n;i++)
	{
		int x = degree(input[i]);
		if(x < INT_MAX)
		{	
			if(x > 0)
				vec1.push_back(x);
			else if(x < 0)
				vec2.push_back(-1*x);
			else
				perfect_count++;
		}
	}

	int total = 0;
	total += perfect_count/2;

	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());

	if(vec1.size() == 0 || vec2.size() == 0)
	{
		cout << total << endl;
		return 0;
	}

	int min_value = 1000001;

	int helper1[1000001];
	int helper2[1000001];

	for(int i=0;i<=min_value;i++)
	{
		helper1[i] = 0;
		helper2[i] = 0;
	}

	for(int i=0;i<vec1.size();i++)
		helper1[vec1[i]]++;

	for(int i=0;i<vec2.size();i++)
		helper2[vec2[i]]++;

	for(int i=0;i<=min_value;i++)
		total += min(helper1[i],helper2[i]);

	cout << total << endl;

	return 0 ; 

}

