#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll mod = 1e9+7;

vector<string> queenMap(8);
int col[8] = {0}, diag1[15] = {0}, diag2[15] = {0};
ll cnt = 0;

void placeQueens(int y, int n) {

    if(y == n) {
        ++cnt;
        return;
    }

    for(int x = 0; x < 8; ++x) {
        if(col[x] || diag1[x+y] || diag2[x-y+n-1] || queenMap[y][x] == '*') continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        placeQueens(y+1,n);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    for(int i = 0; i < 8; ++i) {
        string s;
        cin >> s;
        queenMap[i]=s;
    }

    placeQueens(0,8);
    cout << cnt;
    
    return 0;
}
