#include<bits/stdc++.h>

using namespace std;


int main()
{
	string table;

	cin >> table;

	string first, second, third, fourth, fifth;

	cin >> first >> second >> third >> fourth >> fifth;


	if(table[0] == first[0] || table[0] == second[0] || table[0] == third[0] 
		|| table[0] == fourth[0] || table[0] == fifth[0])
		cout << "YES" << endl;
	else if(table[1] == first[1] || table[1] == second[1] || table[1] == third[1] 
		|| table[1] == fourth[1] || table[1] == fifth[1])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	return 0 ; 

}

