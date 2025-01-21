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
    int n, m, k;
    cin >> n >> m >> k;

    vi want(n), actual(m);

    for(int &x : want) cin >> x;
    for(int &x : actual) cin >> x;

    sort(want.begin(), want.end());
    sort(actual.begin(), actual.end());

    int i = 0, j = 0, cnt = 0;
    while(i < n && j < m) {
        if(want[i] + k >= actual[j] && want[i] - k <= actual[j]) {
            ++cnt; ++i; ++j;
        } else if(want[i] + k < actual[j]) {
            ++i;
        } else {
            ++j;
        }
    }

    cout << cnt;
    
    return 0;
}
