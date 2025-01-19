#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll mod = 1e9+7;

void createString(int cur, int n, vi &left, string s, vector<string> &sol) {

    if(cur == n) {
        sol.push_back(s);
        return;
    }

    for(int i = 0; i < 26; ++i) {
        if(left[i]) {
            s[cur]='a'+i;
            left[i]--;
            createString(cur+1,n,left,s,sol);
            left[i]++;
        }
    }

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string in;
    cin >> in;
    string s(in.length(),' ');

    vi freq(26);
    for(char c : in) freq[c-'a']++;

    vector<string> sol;
    createString(0,in.length(),freq,s,sol);

    cout << sol.size() << "\n";
    for(string t : sol) cout << t << "\n";

    return 0;
}
