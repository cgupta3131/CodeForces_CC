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

    int n;
    cin >> n;
    string l,r;
    cin >> l;
    cin >> r;

    int *left = new int[27];
    int *right = new int[27];

    vector<int> *vec_left = new vector<int>[27];
    vector<int> *vec_right = new vector<int>[27];

    int *ptr_l = new int[27];
    int *ptr_r = new int[27];

    for(int i=0;i<27;i++)
    {
    	//stores the count corressponding to each alphabet
    	left[i] = 0;
    	right[i] = 0;
    	ptr_l[i] = 0;
    	ptr_r[i] = 0;
    }

    int alpha_l = 0;
    int ques_l = 0;
    for(int i=0;i<n;i++)
    {
    	if(l[i] == '?')
    	{
    		ques_l++;
    		left[26]++;
    		vec_left[26].pb(i+1);
    	}
    	else
    	{
    		alpha_l++;
    		left[l[i]-'a']++;
    		vec_left[l[i]-'a'].pb(i+1);
    	}
    }

    int alpha_r = 0;
    int ques_r = 0;
    for(int i=0;i<n;i++)
    {
    	if(r[i] == '?')
    	{
    		ques_r++;
    		right[26]++;
    		vec_right[26].pb(i+1);
    	}
    	else
    	{
    		alpha_r++;
    		right[r[i]-'a']++;
    		vec_right[r[i]-'a'].pb(i+1);
    	}
    }
    
    int total_count = 0;
    //cout << total_count << endl;
    vector<pair<int,int>> final;

    for(int i=0;i<26;i++)
    {
    	int min_val = min(left[i],right[i]);
    	//cout << i << " " << min_val << endl;
    	if(min_val == 0)
    		continue;
    	else
    	{
    		total_count += min_val; //total count incremented
    		alpha_l -= min_val;
    		alpha_r -= min_val;
    		left[i] -= min_val;  //decreasing the used ones
    		right[i] -= min_val; //decreasing the used ones
    		//cout << i << " " << min_val << endl;
    		for(int j=0;j<min_val;j++)
    		{
    			//pair<int,int> temp = make_pair(vec_left[i][0], vec_right[i][0]);
    			pair<int,int> temp = make_pair(vec_left[i][ptr_l[i]], vec_right[i][ptr_r[i]]);
    			ptr_l[i]++;
    			ptr_r[i]++;
    			//vec_left[i].erase(vec_left[i].begin());
    			//vec_right[i].erase(vec_right[i].begin());
    			final.pb(temp);
    		}
    	}
    }

    // left side's question mark and right side's alphabet
    for(int i=0;i<26;i++)
    {
    	int min_val = min(ques_l,right[i]);
	    if(min_val != 0)
	    {
	    	total_count += min_val;
	    	ques_l -= min_val;
	    	alpha_r -= min_val;
	    	left[26] -= min_val; //26 denotes question mark
	    	right[i] -= min_val;

	    	for(int j=0;j<min_val;j++)
    		{
    			/*pair<int,int> temp = make_pair(vec_left[26][0], vec_right[i][0]);
    			vec_left[26].erase(vec_left[26].begin());
    			vec_right[i].erase(vec_right[i].begin());*/
    			pair<int,int> temp = make_pair(vec_left[26][ptr_l[26]], vec_right[i][ptr_r[i]]);
    			ptr_l[26]++;
    			ptr_r[i]++;
    			final.pb(temp);
    		}
	    }
    }

    // left side's alphabet and right side's question mark
    for(int i=0;i<26;i++)
    {
    	int min_val = min(left[i],ques_r);
	    if(min_val != 0)
	    {
	    	total_count += min_val;
	    	alpha_l -= min_val;
	    	ques_r -= min_val;
	    	left[i] -= min_val;
	    	right[26] -= min_val; //26 denotes question mark

	    	for(int j=0;j<min_val;j++)
    		{
    			/*pair<int,int> temp = make_pair(vec_left[i][0], vec_right[26][0]);
    			vec_left[i].erase(vec_left[i].begin());
    			vec_right[26].erase(vec_right[26].begin());*/
    			pair<int,int> temp = make_pair(vec_left[i][ptr_l[i]], vec_right[26][ptr_r[26]]);
    			ptr_l[i]++;
    			ptr_r[26]++;
    			final.pb(temp);
    		}
	    }
    }

     // left side's question mark and right side's question mark
   
	int min_val = min(ques_l,ques_r);
    if(min_val != 0)
    {
    	total_count += min_val;
    	ques_l -= min_val;
    	ques_r -= min_val;
    	left[26] -= min_val;
    	right[26] -= min_val; //26 denotes question mark

    	for(int j=0;j<min_val;j++)
		{
			/*pair<int,int> temp = make_pair(vec_left[26][0], vec_right[26][0]);
			vec_left[26].erase(vec_left[26].begin());
			vec_right[26].erase(vec_right[26].begin());*/
			pair<int,int> temp = make_pair(vec_left[26][ptr_l[26]], vec_right[26][ptr_r[26]]);
    		ptr_l[26]++;
    		ptr_r[26]++;
			final.pb(temp);
		}
    }
    	
    cout << total_count << endl;
    for(int i=0;i<final.size();i++)
    	cout << final[i].f << " " << final[i].s << endl;

	return 0 ;

}
