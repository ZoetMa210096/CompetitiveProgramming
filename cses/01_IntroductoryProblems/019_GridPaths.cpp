#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const ll mod = 1e9+7;

bool vis[7][7] = {false};
int reserved[48];
int ways = 0, curIdx = 0;
string s;

void dfs(int x, int y) {

	if (y == 6 && x == 0) {
		if (curIdx == 48) ++ways;
		return;
	}

    if(
        ((x >= 1 && x <= 5 && !vis[y][x+1] && !vis[y][x-1]) && ((y == 0 && vis[y+1][x]) || (y == 6 && vis[y-1][x]))) ||
        ((y >= 1 && y <= 5 && !vis[y+1][x] && !vis[y-1][x]) && ((x == 0 && vis[y][x+1]) || (x == 6 && vis[y][x-1]))) ||
        ((x >= 1 && x <= 5 && y >= 1 && y <= 5 && vis[y][x+1] && vis[y][x-1] && !vis[y+1][x] && !vis[y-1][x])) ||
        ((x >= 1 && x <= 5 && y >= 1 && y <= 5 && vis[y+1][x] && vis[y-1][x] && !vis[y][x+1] && !vis[y][x-1]))
    ) return;

    vis[y][x]=true;
	if (reserved[curIdx] != -1) {
		switch (reserved[curIdx]) {
            case 0:
                if (y > 0 && !vis[y - 1][x]) {
                    curIdx++;
                    dfs(x, y-1); // up
                    curIdx--;
                } 
                break;
            case 1:
                if (y < 6 && !vis[y + 1][x]) {
                    curIdx++;
                    dfs(x, y+1); // down
                    curIdx--;
                } 
                break;
            case 2:
                if (x > 0 && !vis[y][x - 1]) {
                    curIdx++;
                    dfs(x-1, y); // left
                    curIdx--;
                }
                break;
            case 3:
                if (x < 6 && !vis[y][x + 1]) {
                    curIdx++;
                    dfs(x+1, y); // right
                    curIdx--;
                } 
                break;
        }
		
		vis[y][x] = false;
		return;
	}
 
    curIdx++;
	if (y < 6 && !vis[y+1][x]) dfs(x, y+1); // down
	if (y > 0 && !vis[y-1][x]) dfs(x, y-1); // up
	if (x > 0 && !vis[y][x-1]) dfs(x-1, y); // left
	if (x < 6 && !vis[y][x+1]) dfs(x+1, y); // right
    curIdx--;
    vis[y][x]=false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]) {
            case '?':
                reserved[i] = -1;
                break;
            case 'U':
                reserved[i] = 0;
                break;
            case 'D':
                reserved[i] = 1;
                break;
            case 'L':
                reserved[i] = 2;
                break;
            case 'R':
                reserved[i] = 3;
                break;
        }
    }

    dfs(0,0);
    cout << ways;
    
    return 0;
}
