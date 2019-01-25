#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	/*Final palindrome contains only 'a' 'b' or 'c' and have no palindrome of length 3!
	Also 'c' has to be minimized as much as possible*/	


	//Allowed Non Palindromies
	/*
	abb
	aab
	baa
	bba 
	*/

	if(n==1)
		cout << "a" << endl;
	else if(n == 2)
		cout << "aa" << endl;
	else if(n == 3)
		cout << "aab" << endl;

	else
	{
		string output;
		int excess = n/4;
		int leftover = n - excess*4;

		for(int i=0;i<excess;i++)
			output += "abba";

		if(leftover==1)
			output += "a";
		if(leftover == 2)
			output += "ab";
		if(leftover == 3)
			output += "abb";
		cout << output << endl;
	}



}

