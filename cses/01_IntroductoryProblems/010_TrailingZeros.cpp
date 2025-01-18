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

    int sol = 0;
    // a 0 can be added if prime factors 5 and 2 exist -> sol = amount of 5 in n!
    for(int i = 5; n / i > 0; i *= 5) sol += n / i;
    cout << sol; 
    
    return 0;
}
