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

    ll check = n*(n+1)/2;

    if(check%2) cout << "NO\n";
    else {
        cout << "YES\n";
        vi s1, s2;
        ll taken = 0;

        for(int i = n; i >= 1; --i) {
            if(taken + i <= check / 2) {
                s1.push_back(i);
                taken += i;
            }
            else s2.push_back(i);
        }

        cout << s1.size() << "\n";
        for(int n1 : s1) cout << n1 << " ";
        cout << "\n";
        cout << s2.size() << "\n";
        for(int n2 : s2) cout << n2 << " ";
        cout << "\n";
    }
    
    return 0;
}
