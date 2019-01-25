#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{	
	int second = 12518;
	int length2 = 1;
	for(int k=10;;k = k*10)
	{
		if(second/k != 0)
			length2++;
		else
			break;
	}
	cout << length2 << endl;

	int value = 0;
	int index = 0;
	int mult = 1;
	int temp = second;
	for(int k=0;k<length2;k++)
	{
		int x = temp%10;
		value += x*mult;
		mult *= 10;
		temp = temp/10;
	}	

	cout << value << endl;	
	

}

