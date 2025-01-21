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

    sort(nums.begin(), nums.end());
    int diff = 1;

    for(int i = 0; i < n - 1; ++i) {
        if(nums[i] != nums[i+1]) ++diff;
    }

    cout << diff;
    
    return 0;
}
