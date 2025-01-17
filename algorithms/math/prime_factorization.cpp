#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> primes;
vector<int> pFac(int x) {
    vector<int> _pFac;
    for (ll prime : primes) {
        if (prime*prime>x||x==1) break;
        while (x%prime==0) {
            x/=prime;
            _pFac.push_back(prime);
        }
    }
    if (x>1) _pFac.push_back(x);
    return _pFac;
}
