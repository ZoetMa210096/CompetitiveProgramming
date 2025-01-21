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

    vii movies(n);
    for(int i = 0; i < n; ++i) {
        cin >> movies[i].second >> movies[i].first;
    }

    sort(movies.begin(), movies.end());
    int curTime = 0, cnt = 0;

    for(auto mv : movies) {
        if(curTime <= mv.second) {
            curTime = mv.first; ++cnt;
        }
    }

    cout << cnt;
    return 0;
}
