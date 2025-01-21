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
    int n, m;
    cin >> n >> m;

    vi customers(m);
    multiset<int> tickets;
    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        tickets.insert(tmp);
    }
    for(int &x : customers) cin >> x;

    int c = 0;
    for(int i = 0; i < m; ++i) {

        auto it = tickets.upper_bound(customers[i]);
        if(it == tickets.begin()) cout << "-1\n";
        else {
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }

    return 0;
}
