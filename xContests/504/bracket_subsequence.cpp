#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// function to check if paranthesis are balanced
bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;
 
    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i] =='(')
        {
            s.push(expr[i]);
            continue;
        }

        if (s.empty())
           return false;
 		
 		if (expr[i] == ')')	
 			s.pop();
    }
 
    return (s.empty());
}


int main()
{
	int n; //length of fiven bracket sequence

	int k; // required length of the bracket sequence


	// Jeyyy!
	string input;

	cin >> n >> k;
	cin >> input;

	for(int i=0;i<=n-k;i++)
	{
		if( areParanthesisBalanced(input.substr(i,k)) == true)
		{
			for(int j=i;j<i+k;j++)
				cout << input[j];
			cout << endl;

			return 0;
		}
	}


}

