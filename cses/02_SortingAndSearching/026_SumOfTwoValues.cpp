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

    map<int, int> idxMap;

    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;

        int rev = x - tmp;
        if(idxMap[tmp]) {
            cout << (i + 1) << " " << idxMap[tmp];
            return 0;
        }
        else idxMap[rev] = i + 1;
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}
