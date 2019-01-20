#include<bits/stdc++.h>
using namespace std;

//cin.ignore(numeric_limits<streamsize>::max(), '\n'); -> Clears the input buffer	

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    cin >> s;

    int *count = new int[26];
    for(int i=0;i<26;i++)
    	count[i] = 0;
    
   	if(n == 1)
   	{
   		cout << 1 << endl;
   		return 0;
   	}

   	char prev = s[0];
   	char curr;
   	int temp = 1;

   	for(int i=1;i<n;i++)
   	{
   		curr = s[i];
   		if(prev == curr)
   		{
   			prev = curr;
   			temp++;
   			if(i == n-1)
   				count[prev-'a'] += temp/k;
   			continue;
   		}
   		else
   		{
   			if(i == n-1)
   				count[curr-'a'] += temp/k;
   			
   			count[prev-'a'] += temp/k;
   			temp = 1;
   			prev = curr;
   		}
   	}
   	int max = 0;
   	for(int i=0;i<26;i++)
   		if(count[i] > max)
   			max = count[i];

   	cout << max << endl;

	return 0 ; 

}



