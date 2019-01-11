#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	

void print(int *input, int n)
{
	for(int i=0;i<n;i++)
		cout << input[i];
	cout << endl;

	return;
}

int main()
{
	int n;
	cin >>n;

	int req = n/3;
	int zero = 0;
	int one = 0;
	int two = 0;

	char *arr = new char[n];
	int *input = new int[n];

	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
		if(arr[i] == '0')
		{
			input[i] = 0;
			zero++;
		}
		else if(arr[i] == '1')
		{
			input[i] = 1;
			one++;
		}
		else if(arr[i] == '2')
		{
			input[i] = 2;
			two++;
		}
	}
	/*  for(int i=0;i<n;i++)
		cout << input[i];
	cout << endl;  */


	if(zero == req)
	{
		if(one == req)
		{
			print(input,n);
			return 0;
		}
		else if(one > req )
		{			
			int temp_count = 0;

			for(int i=0;i<n;i++)
			{
				if(input[i] == 1 && temp_count < req)
					temp_count++;
				else if(input[i] == 1 && temp_count >= req)
					input[i] = 2;
			}
			print(input,n);
			return 0;
		}

		else if(one < req)
		{
			//cout << "hey" << endl;
			int diff = two - req;
			int temp_count = 0;

			for(int i=0;i<n;i++)
			{
				if(input[i] == 2 && temp_count < diff)
				{
					input[i] = 1;
					temp_count++;
				} 	
			}
			print(input,n);
			return 0;

		}
	}


	if(one == req)
	{

		if(zero > req )
		{			
			int temp_count = 0;

			for(int i=0;i<n;i++)
			{
				if(input[i] == 0 && temp_count < req)
					temp_count++;
				else if(input[i] == 0 && temp_count >= req)
					input[i] = 2;
			}
			print(input,n);
			return 0;
		}

		else
		{
			//cout << "hey" << endl;
			int diff = two - req;
			int temp_count = 0;

			for(int i=0;i<n;i++)
			{
				if(input[i] == 2 && temp_count < diff)
				{
					input[i] = 0;
					temp_count++;
				} 	
			}
			print(input,n);
			return 0;
		}

	}


	if(two == req)
	{

		if(zero > req )
		{			
			int temp_count = 0;

			for(int i=0;i<n;i++)
			{
				if(input[i] == 0 && temp_count < req)
					temp_count++;
				else if(input[i] == 0 && temp_count >= req)
					input[i] = 1;
			}
			print(input,n);
			return 0;
		}

		else
		{
			//cout << "hey" << endl;
			int diff = one - req;
			int temp_count = 0;

			for(int i=0;i<n;i++)
			{
				if(input[i] == 1 && temp_count < diff)
				{
					input[i] = 0;
					temp_count++;
				} 	
			}
			print(input,n);
			return 0;
		}

	}

	
	if(zero > req && one > req)
	{
		int temp_count0 = 0;
		int temp_count1 = 0;

		for(int i=0;i<n;i++)
		{
			if(input[i] == 0 && temp_count0 < req)
				temp_count0++;
			else if(input[i] == 0 && temp_count0 >= req)
				input[i] = 2;

			if(input[i] == 1 && temp_count1 < req)
				temp_count1++;
			else if(input[i] == 1 && temp_count1 >= req)
				input[i] = 2;
		}

		print(input,n);
		return 0;
	}

	if(one > req && two > req)
	{
		int diff1 = one - req;
		int diff2 = two - req;

		int temp_count1 = 0;
		int temp_count2 = 0;

		for(int i=0;i<n;i++)
		{
			if(input[i] == 1 && temp_count1 < diff1)
			{
				input[i] = 0;
				temp_count1++;
			} 	

			if(input[i] == 2 && temp_count2 < diff2)
			{
				input[i] = 0;
				temp_count2++;
			}
		}

		print(input,n);
		return 0;
 	}

 	if(zero > req && two > req)
 	{

		int diff2 = two - req;

		int temp_count0 = 0;
		int temp_count2 = 0;

		for(int i=0;i<n;i++)
		{
			if(input[i] == 0 && temp_count0 < req)
				temp_count0++;
			else if(input[i] == 0 && temp_count0 >= req)
				input[i] = 1;

			if(input[i] == 2 && temp_count2 < diff2)
			{
				input[i] = 1;
				temp_count2++;
			}
		}

		print(input,n);
		return 0;
 	}

 	if(zero < req && one < req)
 	{
 		int diff0 = req-zero;
 		int diff1 = req-one;


 		int temp_count2 = 0;
 		for(int i=0;i<n;i++)
 		{
 			if(input[i] == 2 && temp_count2 < diff0)
 			{	
 				input[i] = 0;
 				temp_count2++;
 				continue;
 			}

 			if(input[i] == 2 && temp_count2 < diff1+diff0)
 			{
 				input[i] = 1;
 				temp_count2++;
 				continue;
 			}
 		}

 		print(input,n);
		return 0;
 	}

 	if(one < req && two < req)
 	{
 		int diff1 = req-one;
 		int diff2 = req-two;

 		int temp_count0 = 0;

 		for(int i=0;i<n;i++)
 		{
 			if(input[i] == 0 && temp_count0 < req)
 			{
 				temp_count0++;
 				continue;
 			}

 			if(input[i] == 0 && temp_count0 < req+diff1)
 			{
 				input[i] = 1;
 				temp_count0++;
 				continue;
 			}

 			if(input[i] == 0 && temp_count0 < req+diff1+diff2)
 			{
 				input[i] = 2;
 				temp_count0++;
 				continue;
 			}
 		}

 		print(input,n);
		return 0;

 	}

 	if(zero < req && two < req)
 	{
 		int diff0 = req-zero;
 		int diff2 = req-two;

 		int temp_count1 = 0;
 		for(int i=0;i<n;i++)
 		{
 			if(input[i] == 1 && temp_count1 < diff0)
 			{
 				input[i] = 0;
 				temp_count1++;
 				continue;
 			}

 			if(input[i] == 1 && temp_count1 < diff0+req)
 			{
 				temp_count1++;
 				continue;
 			}

 			if(input[i] == 1 && temp_count1 < diff0+req+diff2)
 			{
 				input[i] = 2;
 				temp_count1++;
 				continue;
 			}

 		}
 		print(input,n);
		return 0;
 	}
	
	return 0 ; 

}



