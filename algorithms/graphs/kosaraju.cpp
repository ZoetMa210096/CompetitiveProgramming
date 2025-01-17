#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void dfsOrder(unordered_map<int, vector<int>>& adj, vector<bool>& vis, int node, stack<int>& order) {
    vis[node]=true;
    for(int n : adj[node])
        if(!vis[n])
            dfsOrder(adj, vis, n, order);
    order.push(node);
}

void dfs(unordered_map<int, vector<int>>& adjT, vector<bool>& vis, int node) {
    vis[node]=true;
    for(int n : adjT[node])
        if(!vis[n])
            dfs(adjT, vis, n);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    unordered_map<int, vector<int>> adj(n);

    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<bool> vis(n, false);
    stack<int> order;
    
    for(int i = 0; i < n; ++i) {
        if(!vis[i])
            dfsOrder(adj, vis, i, order);
    }

    unordered_map<int, vector<int>> adjT(n);
    for(int i = 0; i < n; ++i) {
        vis[i]=false;
        for(int j : adj[i])
            adjT[j].push_back(i);
    }

    int scc = 0;
    while(!order.empty()) {
        int node = order.top();
        order.pop();
        if(!vis[node]) {
            ++scc;
            dfs(adjT, vis, node);
        }
    }

    return 0;
}
