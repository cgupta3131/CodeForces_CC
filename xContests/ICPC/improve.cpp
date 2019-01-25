/*

                Name: Kartik Gupta
                IIT-Guwahati

*/


#include <bits/stdc++.h>

using namespace std;

#define ll long long 



int main( int argc , char ** argv )
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL) ;

    ll Num_Cases ; 
    cin >> Num_Cases ; 

    while(Num_Cases--)
    {
        ll n ;
        ll K ;

        cin >> n >> K ; 
        ll x = 0;

        ll * arr = new ll[n] ; 

        for(ll i = 0 ; i < n ; i++)
        {
            cin >> arr[i] ; 
        } 

        sort(arr,arr+n) ; 
        ll i = 0;
        while(1)
        {
            while(arr[i] > K)
            {
                ll diff = min(arr[n-2]-arr[n-3]+1, arr[i]-K);
                arr[i] -= diff;
                arr[n-2] -= diff;
                

                int j = n-2;
                x++;    
                while(arr[j] < arr[j-1])
                {
                    
                    swap(arr[j],arr[j-1]) ;
                    
                    j-- ;  
                }
            }

            i++;

            if(i >= n-2)
            {
                break ; 
            }

        }

        if(arr[n-2] > K)
        {
             arr[n-1] -= arr[n-2]-K;
             arr[n-2] -= arr[n-2]-K;
        }

        ll sum = 0;

        for(ll i = 0; i < n; i++) sum += arr[i] ; 
        cout << sum << '\n' ;

        cout << x << endl;
        delete[] arr ; 

    }


    



    return 0 ; 



}