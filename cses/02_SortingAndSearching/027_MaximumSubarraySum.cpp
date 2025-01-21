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
    int n, tmp;
    cin >> n;

    ll cur = 0, mx = INT32_MIN;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        cur += tmp;
        mx = max(cur, mx);
        cur = max(cur, 0LL);
    }

    cout << mx;
    return 0;
}
