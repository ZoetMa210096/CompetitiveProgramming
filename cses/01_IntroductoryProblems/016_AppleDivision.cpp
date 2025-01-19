#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll mod = 1e9+7;

ll minDiff = 1e11;
int called = 0;

void findMin(ll w1, ll w2, vi &nums, int idx) {

    if(idx == nums.size()) {
        minDiff = min(abs(w1-w2), minDiff);
        return;
    }
    
    findMin(w1+nums[idx],w2,nums,idx+1);
    findMin(w1,w2+nums[idx],nums,idx+1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    vi weights(n);
    for(int i = 0; i < n; ++i) cin >> weights[i];

    findMin(0LL,0LL,weights,0);

    cout << minDiff;

    return 0;
}
