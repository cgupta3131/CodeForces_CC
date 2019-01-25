#include<bits/stdc++.h>

using namespace std;

class myClass{

public:
	string input;
	int a;
	int b;

	myClass()
	{
		input="";
		a=b=0;
	}
};

pair<int, int> solve(string expr)
{
	int _a=0,_b=0;

	stack<int> st;

	for(int i=0;i<expr.length();i++)
	{
		if(expr[i] == '(')
		{
			st.push(expr[i]);
			continue;
		}

		if(st.empty() == true)
			_a++;
		else
		{
			if(st.top() == '(')
				st.pop();
			else
				st.push(')');
		}
	}

	_b = st.size();

	return make_pair(_a,_b);
}


int main()
{
	int n;
	cin >> n;

	myClass *array = new myClass[n];

	int helper1[1000001]; //for storing a
	int helper2[1000001]; //for storing b

	for(int i=0;i<=1000000;i++)
	{
		helper1[i] = 0;
		helper2[i] = 0;
	}

	int perfect = 0;

	for(int i=0;i<n;i++)
	{
		cin >> array[i].input;
		pair<int, int> temp = solve(array[i].input);

		array[i].a = temp.first;
		array[i].b = temp.second;

		if(array[i].a == 0 && array[i].b == 0)
			perfect++;
		else if(array[i].a != 0 && array[i].b != 0)
			continue;
		else
		{	
			if(array[i].a == 0)
				helper2[array[i].b]++;
			else
				helper1[array[i].a]++;
		}
	}
	int total = 0;
	
	for(int i=0;i<=1000000;i++)
		total += min(helper1[i],helper2[i]);

	total += perfect/2;

	cout << total << endl;




	return 0 ; 

}

