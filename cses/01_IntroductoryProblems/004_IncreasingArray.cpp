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
    ll n;
    cin >> n;

    vi x(n);
    for(int &a : x) cin >> a;

    ll sum = 0;
    for(int i = 1; i < n; ++i) {
        sum += max(0, x[i-1]-x[i]);
        x[i]=max(x[i-1],x[i]);
    }

    cout << sum;
    
    return 0;
}
