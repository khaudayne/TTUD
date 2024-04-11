#include <bits/stdc++.h> 
using namespace std;
int main() 
{ 
    int n, t1, t2;
    scanf("%d", &n);
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &t1, &t2);
        v[i] = {t1, t2};
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });  
    int last_E = INT_MIN, rs = 0;

    for(auto x : v){
        if(x.first >= last_E){
            rs++;
            last_E = x.second;
        }
    }
    printf("%d", rs);
}