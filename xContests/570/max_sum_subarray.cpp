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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //string expression = "!(f)";
    string str;
	//cin >> str;
    str = "!(&(&(!(&(f)),&(t),|(f,f,t)),&(t),&(t,t,f)))";
    stack<char > s;
    for(int i=0;i<str.length();i++)
    {
    	//cout << str[i] << endl;
        if(str[i] == '&' || str[i] == '|' || str[i] == '!')
        {
            if(s.empty() == true)
            {
                s.push(str[i]);
                continue;
            }
            else
            {
                int f = 0;
                int t = 0;
                
                while(1)
                {
                    if(s.top() == 'f')
                    {
                        f++;
                        s.pop();
                    }
                    
                    else if(s.top() == 't')
                    {
                        t++;
                        s.pop();
                    }
                    
                    else
                        break;
                }
                
                /*if(str[i] == '!')
                {
                	cout << t << " " << f << " " << s.top() << endl;
                }*/
                if(s.top() == '&')
                {
                    if(t != 0 && f == 0)
                    {
                        s.pop();
                        s.push('t');
                        
                    }

                    else if(f > 0)	
                    {
                        s.pop();
                        s.push('f');
                    }
                }
                
                else if(s.top() == '|')
                {
                    if(t > 0)
                    {
                    	s.pop();
                        s.push('t');
                    }
                    else if(t == 0 && f != 0)
                    {
                    	s.pop();
                        s.push('f');
                    }
                }
                
                else if(s.top() == '!')
                {
                    if(t == 1)
                    {
                    	s.pop();
                        s.push('f');
                    }

                    else if(f == 1)
                    {
                    	s.pop();
                    	s.push('t');
                    }
                }

                s.push(str[i]);
            }
        }

        else if(str[i] == 'f' || str[i] == 't')
        {
        	s.push(str[i]);
        }
    }

    cout << "Stack : ";
    while(!s.empty())
    {
    	cout << s.top() << " ";
    	s.pop();
    }

    cout << endl;
    return 0;


    while(1)
    {
    	if(s.size() == 1)
    		break;

    	int f = 0;
    	int t = 0;
    	//cout << s.size() << endl;
    	while(1)
    	{
    		if(s.top() == 'f')
    		{
    			s.pop();
    			f++;
    			continue;
    		}

    		else if(s.top() == 't')
    		{
    			s.pop();
    			t++;
    			continue;
    		}

    		else
    		{
    			if(s.top() == '&')
                {
                    if(t != 0 && f == 0)
                    {
                        s.pop();
                        s.push('t');
                        
                    }
                    else if(f > 0)
                    {
                        s.pop();
                        s.push('f');
                    }
                }
                
                else if(s.top() == '|')
                {
                    if(t > 0)
                    {
                    	s.pop();
                        s.push('t');
                    }
                    else if(t == 0 && f != 0)
                    {
                    	s.pop();
                        s.push('f');
                    }
                }
                
                else if(s.top() == '!')
                {
                    if(t == 1)
                    {
                    	s.pop();
                        s.push('f');
                    }

                    else if(f == 1)
                    {
                    	s.pop();
                    	s.push('t');
                    }
                }

                break;
    		}
    	}
    }

    if(s.top() == 'f')
    {
    	//return false;
    	cout << "false" << endl;
    }
   	else
   	{
   		//return true;
   		cout << "true" << endl;
   	}

	return 0 ;

}
