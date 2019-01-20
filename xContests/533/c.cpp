#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,l,r;
    cin >> n >> l >> r;
    ll count_0 = 0;
    ll count_1 = 0;
    ll count_2 = 0;

    if(l%3 == 0)
    {
    	if(r%3 == 0)
    	{
    		count_0 = (r-l+3)/3;
    		count_1 = count_0-1;
    		count_2 = count_0-1;
    	}

    	if(r%3 == 1)
    	{
    		count_0 = (r-1-l+3)/3;
    		count_1 = count_0;
    		count_2 = count_0-1;
    	}

    	if(r%3 == 2)
    	{
    		count_0 = (r-2-l+3)/3;
    		count_1 = count_0;
    		count_2 = count_0;
    	}
    }

    if(l%3 == 1)
    {
    	if(r%3 == 0)
    	{
    		ll temp = (r-(l-1)+3)/3;
    		count_0 = temp-1;
    		count_1 = temp-1;
    		count_2 = temp-1;
    	}

    	if(r%3 == 1)
    	{
    		ll temp = (r-1-(l-1)+3)/3;
    		count_0 = temp-1;
    		count_1 = temp;
    		count_2 = temp-1;

    	}

    	if(r%3 == 2)
    	{
    		ll temp = (r-2-(l-1)+3)/3;
    		count_0 = temp-1;
    		count_1 = temp;
    		count_2 = temp;	
    	}
    }


    if(l%3 == 2)
    {
    	if(r%3 == 0)
    	{
    		ll temp = (r-(l-2)+3)/3;
    		count_0 = temp-1;
    		count_1 = temp-2;
    		count_2 = temp-1;
    	}

    	if(r%3 == 1)
    	{
    		ll temp = (r-1-(l-2)+3)/3;
    		count_0 = temp-1;
    		count_1 = temp-1;
    		count_2 = temp-1;
    	}

    	if(r%3 == 2)
    	{
    		ll temp = (r-2-(l-2)+3)/3;
    		count_0 = temp-1;
    		count_1 = temp-1;
    		count_2 = temp;	
    	}
    }

    //cout << count_0 << count_1 << count_1 << "\n"; 
    ll dp[200007][4];
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		dp[i+1][j] = dp[i][j]*count_0 + dp[i][(j+1)%3]*count_2 + dp[i][(j+2)%3]*count_1;
    		dp[i+1][j] %= MOD;
    	}
    }
   
	cout << dp[n][0] << endl;	
	return 0 ; 

}



