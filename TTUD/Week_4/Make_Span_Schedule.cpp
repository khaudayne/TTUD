#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n, m, tmp1, tmp2, rs = - 1;
    vector<vector<int>> v;
    scanf("%d %d", &n, &m);
    v.resize(n + 1, vector<int>());
    int d[n + 1];
    vector<int> cnt(n + 1, 0);
    vector<int> st(n + 1, 0);
    for(int i = 1; i <= n; i++){
        scanf("%d", &d[i]);
    }
    while(m--){
        scanf("%d %d", &tmp1, &tmp2);
        cnt[tmp2]++;
        v[tmp1].push_back(tmp2);
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(rs < st[x] + d[x]) rs = st[x] + d[x];
        for(auto ix : v[x]){
            st[ix] = max(st[ix], st[x] + d[x]);
            cnt[ix]--;
            if(cnt[ix] == 0){
                q.push(ix);
            }
        }
    }
    printf("%d", rs);
}
