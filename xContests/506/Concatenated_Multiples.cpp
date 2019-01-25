#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
	
	long int n,r;
	cin >> n >> r;

	long long int *arr = new long long int[n];

	for(long long int i=0;i<n;i++)		
		cin >> arr[i];


	long int count = 0;

	for(long int i=0;i<n;i++)
	{
		for(long int j=0;j<n;j++)
		{
			if(j == i)
				continue;
			else
			{
				long int first = arr[i];
				long int second = arr[j];

				long int length1 = 1;
				for(long int k=10;;k = k*10)
				{
					if(first/k != 0)
						length1++;
					else
						break;
				}

				long int length2 = 1;
				for(long int k=10;;k = k*10)
				{
					if(second/k != 0)
						length2++;
					else
						break;
				}

				long int value = second;
				long int temp = first;

				long int index = 0;
				long int mult = pow(10,length2);
				for(long int k=length2;k<length1+length2;k++)
				{
					long int x = temp%10;
					value += x*mult;
					mult *= 10;
					temp = temp/10;
				}

				
				if(value % r == 0)
				{
					cout << first << " " << second << " " << value << endl;
					count ++;
				}
			}
		}


	}


	cout << count << endl;

}

