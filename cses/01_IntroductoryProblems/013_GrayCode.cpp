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
    string code = "";
    for(int i = 0; i < n; ++i) code += '0';

    cout << code << "\n";
    for(int i = 1; i < pow(2,n); ++i) {
        int idx = __builtin_ctz(i)+1;
        if(code[n-idx]=='0') code[n-idx]='1';
        else code[n-idx]='0';
        cout << code << "\n";
    }

    return 0;
}
