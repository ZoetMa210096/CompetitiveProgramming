#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll mod = 1e9+7;

void solve() {

    ll k;
    cin >> k;

    ll power = 0, base = 9;
    for(; k > (power+1) * base; ++power) {
        k -= (power+1) * base;
        base *= 10;
    }

    ll res = 0;
    if(power > 0) res = pow(10,power);

    res += (k-1)/(power+1);
    if(res < 10) ++res;

    string _res = to_string(res);
    if(res >= 10) cout << _res[(k-1)%(power+1)] << "\n";
    else cout << _res[0] << "\n";
    
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q;
    cin >> q;
    while(q--) solve();
    
    return 0;
}
