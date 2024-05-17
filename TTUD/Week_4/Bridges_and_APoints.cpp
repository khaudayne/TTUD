#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> v;
vector<int> num_dfs, low;
int n, m, tmp1, tmp2, num_APoints = 0, num_Bridges = 0, num = 1;
vector<bool> aPoints;
void dfs(int p, int parent){
    int child = 0;
    num_dfs[p] = num++;
    low[p] = num_dfs[p];
    for(int i : v[p]){
        if(i == parent) continue;
        if(num_dfs[i] == 0){
            child++;
            dfs(i, p);
            low[p] = min(low[p], low[i]);
            if(low[i] >= num_dfs[p] && parent != -1 && aPoints[p]){
                num_APoints++;
                aPoints[p] = false;
            }
            if(low[i] > num_dfs[p]) num_Bridges++;
        }else{
            low[p] = min(low[p], num_dfs[i]);
        }
    }
    if(parent == -1 && child > 1 && aPoints[p]){
        num_APoints++;
        aPoints[p] = false;
    }
}

int main() 
{ 
    scanf("%d %d", &n, &m);
    v.resize(n + 1);
    num_dfs.resize(n + 1, 0);
    low.resize(n + 1, 0);
    aPoints.resize(n + 1, true);
    while(m--){
        scanf("%d %d", &tmp1, &tmp2);
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    for(int i = 1; i <= n; i++){
        if(num_dfs[i] == 0) dfs(i, -1);
    }
    printf("%d %d", num_APoints, num_Bridges);
}