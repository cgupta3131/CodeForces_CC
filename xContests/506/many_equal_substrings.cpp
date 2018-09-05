#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int n,k;
	string input;

	cin >> n >> k;
	cin >> input ;

	int mid = n/2;

	int i;
	int flag  = 0;
	for(i=n-1;i>=1;i--)
	{
		int si = n - i;

		if(input.substr(0,i) == input.substr(si,i))	
		{
			flag = 1;
			break;
		}
	}

	string output;
	if(flag == 0)
	{
		for(int i=0;i<k;i++)
			output += input;

		
	}

	else
	{
		string temp = input.substr(i);
		output = input;

		for(int i=1;i<k;i++)
			output += temp;
	}

	cout << output << endl;	

}

