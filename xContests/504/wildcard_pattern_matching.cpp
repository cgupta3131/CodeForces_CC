#include<iostream>
#include<string>
#include<vector>

using namespace std;



int main()
{
		
	int n; //length of string s
	int m; // length of string t

	cin >> n >> m;

	string s,t;

	cin >> s;
	cin >> t;

	int flag =0;
	int i;
	for(i=0;i<n;i++)
		if(s[i] == '*')
		{
			flag =1;
			break;
		}

	int index = i; //gives the index where the * is present!!

	if(flag == 0) // the string s does not contain * character
	{
		if(s == t)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		return 0;
	}


	if(n > m+1)
	{
		cout << "NO" << endl;
		return 0;
	}


	flag = 0;
	for(int i=0;i<index;i++)
	{
		if(s[i] != t[i])
			flag = 1;
	}

	int k = m-1;
	for(int i=n-1;i>index;i--)
	{
		if(s[i] == t[k])
			k--;
		else
			flag = 1;
	}

	if(flag == 0)
		cout << "YES" << endl;
	else
	cout << "NO" << endl; 






	

}

