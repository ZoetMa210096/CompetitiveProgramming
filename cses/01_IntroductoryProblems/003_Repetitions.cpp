#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll mod = 1e9+7;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;

    int cur = 1, maxS = 1;
    char prev = s[0];
    for(int i = 1; i < s.length(); ++i) {
        if(s[i]==prev) {
            ++cur;
            maxS = max(cur, maxS);
        }
        else {
            cur = 1;
            prev = s[i];
        }
    }

    cout << maxS;
    
    return 0;
}
