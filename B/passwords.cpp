#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main()
{

	int n,k;

	cin >> n >> k;

	string *list = new string[n];

	for(int i=0;i<n;i++)
		cin >> list[i];

	string myPassword;
	int length;
	cin >> myPassword;
	length = myPassword.size();

	int count_less = 0;
	int count_equal = 0;


	for(int i=0;i<n;i++)
	{
		if(list[i].size() < length)
			count_less++;

		if(list[i].size() == length)
			count_equal++;
	}

	

	//Best Case
	int time =0;
	int number = count_less;
	int excess = number/k;
	int leftover = number - excess*k;
	time += excess*(k+5);
	time += leftover;

	cout << time+1 << " ";

	//Worst Case
	time=0;
	number = count_equal+count_less - 1;
	excess = number/k;
	leftover = number - excess*k;
	time += excess*(k+5);
	time += leftover;
	cout << time+1 << endl;

	

}

