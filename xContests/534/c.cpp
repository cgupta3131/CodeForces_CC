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
typedef pair<pii,int> ppi;
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
bool grid[5][5];
void Check()
{
	for(int i=1;i<=4;i++)
	{
		if(grid[i][1]&&grid[i][2]&&grid[i][3]&&grid[i][4])
		{
			grid[i][1] = false;
			grid[i][2] = false;
			grid[i][3] = false;
			grid[i][4] = false;
		}
	}

	for(int j=1;j<=4;j++)
	{
		if(grid[1][j]&&grid[2][j]&&grid[3][j]&&grid[4][j])
		{
			grid[1][j] = false;
			grid[2][j] = false;
			grid[3][j] = false;
			grid[4][j] = false;
		}
	}

}


void Vertical(string s, int len)
{
	int flag = 0;
	for(int j=1;j<=4;j++)
	{
		if( grid[1][j] && grid[2][j] && !grid[3][j] && !grid[4][j] )
		{
			grid[3][j] = true;
			grid[4][j] = true;
			cout << 3 << " " << j << "\n";
			Check();
			return;
		}

		if( grid[1][j] && !grid[2][j] && !grid[3][j] && grid[4][j] )
		{
			grid[2][j] = true;
			grid[3][j] = true;
			cout << 2 << " " << j << "\n";
			Check();
			return;
		}

		if( !grid[1][j] && !grid[2][j] && grid[3][j] && grid[4][j] )
		{
			grid[1][j] = true;
			grid[2][j] = true;
			cout << 1 << " " << j << "\n";
			Check();
			return;
		}
	}

	for(int j=1;j<=4;j++)
	{
		if( grid[1][j] && !grid[2][j] && !grid[3][j] && !grid[4][j] )
		{
			grid[2][j] = true;
			grid[3][j] = true;
			cout << 2 << " " << j << "\n";
			Check();
			return;
		}

		if( !grid[1][j] && grid[2][j] && !grid[3][j] && !grid[4][j] )
		{
			grid[3][j] = true;
			grid[4][j] = true;
			cout << 3 << " " << j << "\n";
			Check();
			return;
		}

		if( !grid[1][j] && !grid[2][j] && grid[3][j] && !grid[4][j] )
		{
			grid[1][j] = true;
			grid[2][j] = true;
			cout << 1 << " " << j << "\n";
			Check();
			return;
		}

		if( !grid[1][j] && !grid[2][j] && !grid[3][j] && grid[4][j] )
		{
			grid[2][j] = true;
			grid[3][j] = true;
			cout << 2 << " " << j << "\n";
			Check();
			return;
		}
	}

	for(int j=1;j<=4;j++)
	{
		if( !grid[1][j] && !grid[2][j] && !grid[3][j] && !grid[4][j] )
		{
			grid[1][j] = true;
			grid[2][j] = true;
			cout << 1 << " " << j << "\n";
			Check();
			return;
		}

	}
}


void Horizontal(string s, int len)
{
	int flag = 0;
	for(int i=1;i<=4;i++)
	{
		if( grid[i][1] && grid[i][2] && !grid[i][3] && !grid[i][4] )
		{
			grid[i][3] = true;
			grid[i][4] = true;
			cout << i << " " << 3 << "\n";
			Check();
			return;
		}

		if( !grid[i][1] && grid[i][2] && grid[i][3] && !grid[i][4] )
		{
			grid[i][2] = true;
			grid[i][3] = true;
			cout << i << " " << 2 << "\n";
			Check();
			return;
		}

		if( !grid[i][1] && !grid[i][2] && grid[i][3] && grid[i][4] )
		{
			grid[i][1] = true;
			grid[i][2] = true;
			cout << i << " " << 1 << "\n";
			Check();
			return;
		}
	}

	for(int i=1;i<=4;i++)
	{
		if( grid[i][1] && !grid[i][2] && !grid[i][3] && !grid[i][4] )
		{
			grid[i][2] = true;
			grid[i][3] = true;
			cout << i << " " << 2 << "\n";
			Check();
			return;
		}

		if( !grid[i][1] && grid[i][2] && !grid[i][3] && !grid[i][4] )
		{
			grid[i][3] = true;
			grid[i][4] = true;
			cout << i << " " << 3 << "\n";
			Check();
			return;
		}

		if( !grid[i][1] && !grid[i][2] && grid[i][3] && !grid[i][4] )
		{
			grid[i][1] = true;
			grid[i][2] = true;
			cout << i << " " << 1 << "\n";
			Check();
			return;
		}

		if( !grid[i][1] && !grid[i][2] && !grid[i][3] && grid[i][4] )
		{
			grid[i][2] = true;
			grid[i][3] = true;
			cout << i << " " << 2 << "\n";
			Check();
			return;
		}
	}

	for(int i=1;i<=4;i++)
	{
		if( !grid[i][1] && !grid[i][2] && !grid[i][3] && !grid[i][4] )
		{
			grid[i][1] = true;
			grid[i][2] = true;
			cout << i << " " << 1 << "\n";
			Check();
			return;
		}

	}
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    int count=0;
    int count2=0;
    
    for(int i=0;s[i];i++)
    {
        if(s[i]=='0')
        {
            if(count%2==0)
            {
                cout<<1<<" "<<1<<endl;
                count++;
                continue;
            }
            else
            {
                cout<<3<<" "<<1<<endl;
                count++;
                continue;
            }
        }
        else
        {
            if(count2%4==0)
            {
                cout<<1<<" "<<2<<endl;
                count2++;
                continue;
            }
            if(count2%4==1)
            {
                cout<<2<<" "<<2<<endl;
                count2++;
                continue;
            }
            if(count2%4==2)
            {
                cout<<3<<" "<<2<<endl;
                count2++;
                continue;
            }
            if(count2%4==3)
            {
                cout<<4<<" "<<2<<endl;
                count2++;
                continue;
            }
        }

    }


	return 0; 

}



