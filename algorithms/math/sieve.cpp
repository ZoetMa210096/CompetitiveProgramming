#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> primes;
const int n = 1'000'000;

void sieve() {
    vector<bool> p(n+1,true);
    for(ll i = 2; i*i <= n; ++i)
        if(p[i])
            for(ll j = i*i; j <= n; j+=i)
                p[j]=false;
    for(int i = 2; i <= n; ++i)
        if(p[i]) primes.push_back(i);
}
