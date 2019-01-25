#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<int> vi;
#define EPS 1e-9 // 10^-9
#define pb push_back
#define ll long long
#define INF 1e9 // 10^9
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

int main(){
    int n, k, level=INT_MIN, tempLevel=0;
    cin >> n >> k;
    string s, temp, temp2;
    cin >> s;
    char c=s[0], cc;
    int startInd=0, m, count=1;
    vi val;
    
    for(int i=1; i<s.length() && k!=1; i++){
        cc = s[i];
        if(count == k){
            //cout << "SAME " << i << endl;
            val.pb(startInd);
            if(i<s.length()-1){
                startInd = i;
                c = s[startInd];
                count = 1;
            }
            continue;
        }
        if(c == cc){
            //cout << i << " bam\n";
            ++count;
        }else{
            //cout << i << endl;
            if(i<s.length()-1){
                startInd = i;
                c = s[startInd];
                count = 1;
            }
        }
    }
    if(count == k){
            //cout << "SAME " << s.length()-1 << endl;
            val.pb(s.length()-k);
        }
    // for(int i: val)
    //  cout << s.substr(i, k) << endl;
    vector<string> inps;
    //for(int i=0; i<s.length()-k+1; i++){
    for(int q=0; q<val.size(); q++){
        int i = val[q];
        temp = s.substr(i, k);
        //cout << temp << " " << i << endl;
        inps.pb(temp);
    }
    if(k==1){
        inps.clear();
        for(int i=0; i<s.size(); i++){
            temp = s.substr(i, 1);
            inps.pb(temp);
        }
    }
    if(inps.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(inps.begin(), inps.end());
    temp = inps[0];
    tempLevel = 1; level = INT_MIN;
    for(int i=1; i<inps.size(); i++){
        temp2 = inps[i];
        //cout << temp2 << i << endl;
        if(temp == temp2){
            tempLevel++;
        }else{
            temp = temp2;
            level = max(tempLevel, level);
            tempLevel = 1;
        }
    }
    if(tempLevel > 0)
        level = max(tempLevel, level);
    if(level == INT_MIN)
        level = 0;
    cout << level << endl;
    return 0;
}

