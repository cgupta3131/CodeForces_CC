#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long int a[n],b[n],c[n],m,p,q,count=0,count1=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    p=a[n-1];
    for(int i=0;i<n;i++)
    {
        if(a[n-1]%a[i]==0)
        {
            count++;
            a[i]=0;
        }
    }
    long long int maxi=0,maxnum;
    if(count==n)
    {
        cout << "hey" << "\n";
        count1=0;
        for(int i=0;i<n;i++)
        {
            if(b[i]==b[i+1])
            {
                c[count1]=b[i];
                count1++;
            }   
        }
        cout<<p<<" "<<c[count1-1]<<endl;
    }
    else
    {
        sort(a,a+n);
        q=a[n-1];
        cout<<p<<" "<<q<<endl;
    }
}