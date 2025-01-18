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
    ll n, tmp;
    cin >> n;

    ll s = 0;
    for(int i = 0; i < n - 1; ++i) {
        cin >> tmp;
        s += tmp;
    }

    ll exp = n*(n+1)/2;
    cout << exp - s;
    
    return 0;
}
