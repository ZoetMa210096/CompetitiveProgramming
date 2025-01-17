#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll adj[501][501]={0}, dist[501][501]={0};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> adj[i][j];
            if(i == j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j]=adj[i][j];
            else dist[i][j]=INFINITY;
        }
    }

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    return 0;
}
