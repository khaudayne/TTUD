#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
int cnt_components = 0, time_dfs = 0, number[maxn], low[maxn];
stack <int> vertex;
bool is_deleted[maxn];
vector <int> adj[maxn];

void dfs(int u)
{
    number[u] = ++time_dfs;
    low[u] = number[u];
    vertex.push(u);
    for (int v: adj[u])
    {		
        if (is_deleted[v])
            continue;
        if (!number[v])
        {
            dfs(v); 
            low[u] = min(low[u], low[v]); 
        }
        else 
        {
            low[u] = min(low[u], number[v]);
        }
    }
    if (low[u] == number[u]) 
    {
        cnt_components++;
        int v = vertex.top();
        is_deleted[v] = 1;
        while(v != u)
        {
            vertex.pop();
            v = vertex.top();
            is_deleted[v] = 1;
        }
    }
}

main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int u = 1; u <= n; ++u)
        if (!number[u])
            dfs(u);
    cout << cnt_components;
}
