#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll mod = 1e9+7;

void solve() {
    int a, b;
    cin >> a >> b;
    if(a > 2 * b || b > 2 * a) cout << "NO";
    else if((a+b)%3 == 0) cout << "YES";
    else cout << "NO";
    cout << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
