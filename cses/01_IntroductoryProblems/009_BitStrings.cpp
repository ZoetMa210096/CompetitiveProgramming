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

    int n;
    cin >> n;

    ll sol = 1;
    for(int i = 1; i <= n; ++i) {
        sol = (sol * 2) % mod;
    }
    cout << sol;
    
    return 0;
}
