#include<bits/stdc++.h>

using namespace std;


int main()
{
	string input;
	cin >> input;

	int k;
	cin >> k;

	int letters = 0;
	int candies = 0;
	int flakes = 0;

	for( int i=0;i<input.length();i++ )
	{
		if(input[i] == '?')
			candies++;
		else if(input[i] == '*')
			flakes++;
		else
			letters++;
	} 


	if(candies == 0 && flakes == 0)
	{
		if(k == letters)
			cout << input << endl;
		else
			cout << "Impossible" << endl;

		return 0;
	}

	if(candies != 0 && flakes == 0)
	{
		if(k >= letters - candies && k <= letters)
		{
			int deleted = letters - k;
			int count = 0;

			for( int i=0;i<input.length();i++ )
			{
				if(input[i] == '?')
					continue;

				if(input[i] != '?' && input[i+1] == '?' && count < deleted)
				{
					count++;
					continue;
				}

				cout << input[i];
			}

			cout << endl;

		}

		else
			cout << "Impossible" << endl;

		return 0;
	}


	if(candies == 0 && flakes != 0)
	{
		if(k >= letters - flakes && k <= letters)
		{
			int deleted = letters - k;
			int count = 0;

			for( int i=0;i<input.length();i++ )
			{
				if(input[i] == '*')
					continue;

				if(input[i] != '*' && input[i+1] == '*' && count < deleted)
				{
					count++;
					continue;
				}

				cout << input[i];
			}

			cout << endl;
		}

		else if( k>letters )
		{
			int added = k - letters;
			int flag = 0;

			for( int i=0;i<input.length();i++ )
			{
				if(input[i] == '*')
					continue;

				if(input[i] != '*' && input[i+1] == '*' && flag == 0)
				{
					for(int k=0;k<=added;k++)
						cout << input[i];
					flag=1;
					continue;
				}

				cout << input[i];
			}

			cout << endl;
		}

		else
			cout << "Impossible" << endl;

	}


	if(candies != 0 && flakes != 0)
	{
		if(k >= letters - flakes - candies && k <= letters)
		{
			int deleted = letters - k;
			int count = 0;

			for( int i=0;i<input.length();i++ )
			{
				if(input[i] == '*' || input[i] == '?')
					continue;

				if(input[i] != '*' && input[i+1] == '*' && count < deleted)
				{
					count++;
					continue;
				}

				if(input[i] != '?' && input[i+1] == '?' && count < deleted)
				{
					count++;
					continue;
				}

				cout << input[i];
			}

			cout << endl;
		}

		else if( k>letters )
		{
			int added = k - letters;
			int flag = 0;

			for( int i=0;i<input.length();i++ )
			{
				if(input[i] == '*' || input[i] == '?')
					continue;

				if(input[i] != '*' && input[i+1] == '*' && flag == 0)
				{
					for(int k=0;k<=added;k++)
						cout << input[i];
					flag=1;
					continue;
				}

				cout << input[i];
			}

			cout << endl;
		}

		else
			cout << "Impossible" << endl;




	}


	return 0 ; 

}

