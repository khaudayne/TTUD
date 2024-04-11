//C++ 
#include <bits/stdc++.h> 
using namespace std;
int n, kk, min_d = INT_MAX, rs = INT_MAX, load = 0, cur_rs = 0;
vector<vector<int>> v;
void f(int k, int visited, int st){
    for(int i = 1; i <= 2 * n; i++){
        if(((visited & (1 << i)) != 0) && ((i <= n && (visited & (1 << (i + n))) > 0) || (i > n && (visited & (1 << (i - n))) == 0))){
            if(i <= n) load++;
            else load--;
            if(load > kk){
                load--;
                continue;
            }
            cur_rs += v[st][i];
            visited -= (1 << i);
            if(k == 2 * n){
                if(rs > cur_rs + v[i][0]) rs = cur_rs + v[i][0];
            }else{
                if(cur_rs + min_d * (2 * n - k + 1) < rs) f(k + 1, visited, i);
            }
            if(i <= n) load--;
            else load++;
            cur_rs -= v[st][i];
            visited += (1 << i);
        }

    }
}
int main() 
{ 
    scanf("%d %d", &n, &kk);
    v.resize(2 * n + 1, vector<int>(2 * n + 1));
    for(int i = 0; i < 2 * n + 1; i++){
        for(int j = 0; j < 2 * n + 1; j++){
            scanf("%d", &v[i][j]);
            if(min_d > v[i][j] && v[i][j] > 0) min_d = v[i][j];
        }
    }
    int visited = (1 << (2 * n + 1)) - 1;
    f(1, visited, 0);
    printf("%d", rs);
}
