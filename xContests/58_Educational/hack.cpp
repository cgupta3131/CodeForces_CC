#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q,s=1,j;

    long long a,b,c;
    cin >> q;
    for(int w=0; w<q; w++)
    {
        cin >> a >> b >> c;
        int x,y;
        x=(a-1)/c;
        y=(b+1)/c;
        if(c==1 && a>1)cout << 1 << endl;
        else
        {
            if(x>0)
        {
            j = 1;
            if(j%c==0)a=j;
            else a = j + (c - (j%c));
            cout << a << endl;
        }
        else
        {
            j = b+1;
            if(j%c==0)b=j;//lol
            else b = j + (c-(j%c));
            cout << b << endl;
        }
        }


    }
    return 0;
}