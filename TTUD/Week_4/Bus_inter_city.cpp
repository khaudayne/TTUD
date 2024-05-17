#include <bits/stdc++.h> 
using namespace std;
class Compare {
public:
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.first > b.first;
    }
};
int main() 
{ 
    int n, m, tmp1, tmp2;
    scanf("%d %d", &n, &m);
    int C[n + 1], D[n + 1];
    vector<vector<int>> v(n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &C[i], &D[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &tmp1, &tmp2);
        v[tmp1].push_back(tmp2);
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> pq;
    pq.push({0, {1, 0}});
    while(!pq.empty()){
        int tmp = pq.top().first;
        pair<int, int> tmp1 = pq.top().second;
        pq.pop();
        if(tmp1.first == n){
            printf("%d", tmp);
            break;
        }
        for(auto x : v[tmp1.first]){
            if(tmp1.second > 0) pq.push({tmp, {x, tmp1.second - 1}});
            pq.push({tmp + C[tmp1.first], {x, D[tmp1.first] - 1}});
        }
    }
}