#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		pii *arr = new pii[n];

		int out_flag = 0;
		int *output = new int[n];

		for(int i=0;i<n;i++)
			output[i] = 0;

		for(int i=0;i<n;i++)
			cin >> arr[i].first >> arr[i].second;

		pii group1;
		group1.first = arr[0].first;
		group1.second = arr[0].second;

		output[0] = 1;

		pii group2;
		group2.first = -1;
		group2.second = -1;



		for(int i=1;i<n;i++)
		{
			int a = arr[i].first;
			int b = arr[i].second;

			int flag = 0;

			if(b >= group1.first && b <= group1.first) 
			//means that (a,b) would go to group 1
			{	
				output[1] = 1;
				group1.first = min(group1.first , a);
				flag = 1;
			}

			else if(a >= group1.first && a <= group1.first) 
			//means that (a,b) would go to group 1
			{
				output[1] = 1;
				group1.second = max(group1.first , b);
				flag = 1;
			}

			if(group2.first != -1)
			{
				if(b >= group2.first && b <= group2.first)
				{
					if(flag == 1)
					{
						cout << -1 << endl;
						out_flag = 1;
						break;
					}

					output[i] = 2;
					group2.first = min(group2.first , a);
					flag = 1;
				}

				else if(a >= group2.first && a <= group2.first) 
				//means that (a,b) would go to group 1
				{
					if(flag == 1)
					{
						cout << -1 << endl;
						out_flag = 1;
						break;
					}

					output[i] = 2;
					group2.second = max(group2.first , b);
					flag = 1;
				}
			}

			else
			{
				group2.first = a;
				group2.second = b;

				output[i] = 2;


			}
		}

		if(out_flag == 1)
			continue;

	}
	
	return 0 ; 

}



