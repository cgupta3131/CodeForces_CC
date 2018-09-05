#include <iostream>
#include<string>

using namespace std;

int main()
{
	string input;
	cin >> input;

	string output;

	for(int i=0;i<input.size();i++)
	{
		if(input[i] == 'A' || input[i] == 'O' || input[i] == 'Y' || input[i] == 'E' || input[i] == 'U' || input[i] == 'I' 
	|| input[i] == 'a' || input[i] == 'o' || input[i] == 'y' || input[i] == 'e' || input[i] == 'u' || input[i] == 'i'  )
		continue;

		if(input[i] >= 'A' && input[i] <= 'Z' )
		{
			input[i] += 32;
			i--;
		}

		else
			output = output + '.' + input[i];	

	}

	
	cout << output << endl;


}
