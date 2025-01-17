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

    while(n > 1) {
        cout << n << " ";
        if(n%2) n = n*3+1;
        else n /= 2;
    }

    cout << 1;
    
    return 0;
}
