#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	

int main()
{

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //The above two lines 
    cout.tie(NULL);

  //  sdcsd/*    */
	int q;
	cin >> q;


	int max_left = -1;
	int max_right = -1;

	while(q--)
	{	
		char c;
		int a,b;
		cin >> c >> a >> b;

		if(c == '+')
		{	
			int mini = -1;
			int maxi = -1; 
			maxi = max(a,b);
			mini = min(a,b);
				
			if(max_left < mini)
				max_left = mini;

			if(max_right < maxi)
				max_right = maxi;
		}

		if(c == '?')
		{
			int mini = -1;
			int maxi = -1; 
			maxi = max(a,b);
			mini = min(a,b);

			if(max_left <= mini && max_right <= maxi)
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
				
		}
	}
	
	return 0 ; 

}



