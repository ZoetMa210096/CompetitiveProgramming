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

    vi nums(n);
    for(int &x : nums) cin >> x;

    ll smallSum = 1;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; ++i) {
        if(nums[i] > smallSum) break;
        smallSum += nums[i];
    }

    cout << smallSum;
    
    return 0;
}
