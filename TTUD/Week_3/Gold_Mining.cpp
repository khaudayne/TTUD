#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<pair<int, int>> d;
    int n, L1, L2, i = 0, j = 1;
    scanf("%d %d %d", &n, &L1, &L2);
    int v[n];
    for(; i < n; i++) scanf("%d", &v[i]);
    d.push_back({v[0], 0});
    for(i = L1; i < n; i++){
        while(i - d.front().second > L2){
            d.pop_front();
        }
        v[i] += d.front().first;
        pair<int, int> tmp = {v[j], j};
        j++;
        if(tmp.first >= d.front().first){
            d.clear();    
        }else{
            while(tmp.first >= d.back().first) d.pop_back();
        }
        d.push_back(tmp);
    }
    printf("%d", *max_element(v, v + n));
}
