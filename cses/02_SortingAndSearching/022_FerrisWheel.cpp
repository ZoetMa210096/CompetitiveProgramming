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
    int n, x;
    cin >> n >> x;

    vi weights(n);
    for(int &y : weights) cin >> y;
    sort(weights.rbegin(), weights.rend());

    int cnt = 0, l = 0, r = n - 1;
    while(l < r) {
        if(weights[l]+weights[r] <= x) {
            ++cnt; ++l; --r;
        }
        else {
            ++cnt; ++l;
        }
    }

    cout << (l == r ? cnt + 1 : cnt);
    
    return 0;
}
