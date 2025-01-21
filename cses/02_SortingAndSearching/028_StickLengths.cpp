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

    vi lens(n);
    for(int &x : lens) cin >> x;

    sort(lens.begin(), lens.end());
    int cmp = lens[n/2];

    ll minDiff = 0;
    for(int &x : lens) {
        minDiff += abs(cmp-x);
    }
    cout << minDiff;
    
    return 0;
}
