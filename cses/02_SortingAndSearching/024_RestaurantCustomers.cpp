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
    vii events(n);
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        events.push_back({tmp, 1});
        cin >> tmp;
        events.push_back({tmp, -1});
    }
    sort(events.begin(), events.end());

    int cur = 0, mx = 0;
    for(auto &ev : events) {
        cur += ev.second; mx = max(mx, cur);
    }

    cout << mx;
    return 0;
}
