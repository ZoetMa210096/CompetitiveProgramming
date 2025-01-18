#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll mod = 1e9+7;

void solve() {
    ll y, x;
    cin >> y >> x;

    ll res = 0; 
    
    if(x >= y) {
        res += x * x;
        if(x%2) res -= (y - 1);
        else res = res - 2 * (x - 1) + (y - 1);
    }
    else {
        res += y * y;
        if(y%2) res = res - 2 * (y - 1) + (x - 1);
        else res -= (x - 1);
    }

    cout << res << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) solve();
    
    return 0;
}
