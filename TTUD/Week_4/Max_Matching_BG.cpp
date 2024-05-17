#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> v;
vector<int> take_task;
bool ch[10001];
bool f(int m){
    for(auto x : v[m]){
        if(ch[x] == false){
            ch[x] = true;
            if(take_task[x] == -1 || f(take_task[x])){
                take_task[x] = m;
                ch[x] = false;
                return true;
            }
            ch[x] = false;
        }
    }
    return false;
}
int main(){
    int n, m;
    int tmp1, tmp2, rs = 0;
    scanf("%d %d", &n, &m);
    v.resize(m + 1, vector<int>());
    take_task.resize(n + 1, -1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &tmp1);
        while(tmp1--){
            scanf("%d", &tmp2);
            v[tmp2].push_back(i);
        }
    }
    for(int i = 1; i <= m; i++){
        if(f(i)) rs++;
    }
    printf("%d", rs);
}
