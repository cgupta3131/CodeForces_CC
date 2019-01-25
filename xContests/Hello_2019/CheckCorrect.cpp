#include<bits/stdc++.h> 
using namespace std; 

bool areParanthesisBalanced(string expr) 
{ 
	stack<char> s; 
	char x; 

	for (int i=0; i<expr.length(); i++) 
	{ 
		if (expr[i]=='(') 
		{ 
			s.push(expr[i]); 
			continue; 
		} 

	
		if (s.empty()) 
		return false; 

		switch (expr[i]) 
		{ 
		case ')': 

			x = s.top(); 
			s.pop(); 
			break; 

		} 
	} 

	return (s.empty()); 
} 

// Driver program to test above function 
int main() 
{ 
	string expr = "()"; 

	if (areParanthesisBalanced(expr)) 
		cout << "Balanced"; 
	else
		cout << "Not Balanced"; 
	return 0; 
} 
