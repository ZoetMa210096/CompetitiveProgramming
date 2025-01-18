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

    if(n <= 3 && n > 1) cout << "NO SOLUTION";
    else {
        for(int i = 2; i <= n; i += 2) cout << i << " ";
        for(int i = 1; i <= n; i += 2) cout << i << " ";
    }
    
    return 0;
}
