#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

bool isPrime(ll n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll a,b; // Here a>b;
		cin >> a >> b;	

		if((a-b) != 1)
		{
			cout << "NO" << endl;
			continue;
		}
		
		if(isPrime(a+b) == true	)
			cout << "YES" << endl;
		else
			cout << "NO"<< endl;



	}


	return 0 ; 

}

