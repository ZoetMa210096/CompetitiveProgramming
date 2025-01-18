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

    cout << 0 << "\n";
    for(ll k = 2; k <= n; ++k) {
        // possible positions: k² (first horse) * (k²-1) (second horse)
        // attacks: imagine as a 2*3 rect -> (k-1)*(k-2) of such can be placed
        // multiply *8 possible attacks / 2 so no duplicates
        cout << ((k*k)*(k*k-1))/2 - (k-1)*(k-2)*4 << "\n";
    } 
    
    return 0;
}
