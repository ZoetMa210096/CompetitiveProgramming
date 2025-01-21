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

    vi translation(n+1);

    for(int i = 1; i <= n; ++i) {
        cin >> tmp;
        translation[tmp] = i;
    }

    int rounds = 1, prevIdx = 0;
    for(int i = 1; i <= n; ++i) {
        int thisIdx = translation[i];
        if(thisIdx < prevIdx) {
            ++rounds; prevIdx = thisIdx;
        } else {
            prevIdx = thisIdx;
        }
    }

    cout << rounds;
    
    return 0;
}
