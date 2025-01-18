#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll mod = 1e9+7;
int cnt[26] = {0};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;

    for(char c : s) cnt[c-'A']++;
    bool flag = true;
    int unevenIdx = -1;

    for(int i = 0; i < 26; ++i) {
        if(unevenIdx >= 0 & cnt[i]%2) flag = false;
        else if(cnt[i]%2) unevenIdx = i;
    }

    string build = "";
    if(!flag) cout << "NO SOLUTION";
    else {
        for(int i = 0; i < 26; ++i) {
            char toAdd = ('A'+i);
            for(int j = 0; j < cnt[i]/2; ++j) build += toAdd;
        }
        if(unevenIdx != -1) build += ('A'+unevenIdx);
        for(int i = 25; i >= 0; --i) {
            char toAdd = ('A'+i);
            for(int j = 0; j < cnt[i]/2; ++j) build += toAdd;
        }
        cout << build;
    }
    
    return 0;
}
