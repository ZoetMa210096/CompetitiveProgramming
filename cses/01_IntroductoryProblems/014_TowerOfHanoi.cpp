#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll mod = 1e9+7;

void helper(int n, int source, int aux, int dest) {
    if(n == 1) {
        cout << source << " " << dest << "\n";
        return;
    }
    helper(n-1, source, dest, aux);
    cout << source << " " << dest << "\n";
    helper(n-1, aux, source, dest);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    cout << pow(2,n)-1 << "\n";
    helper(n,1,2,3);
    
    return 0;
}
