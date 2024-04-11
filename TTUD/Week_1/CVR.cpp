#include <bits/stdc++.h> 
using namespace std;
int n, K, Q;
int d[13];
int m[13][13];
int load[6];
bool visited[13];
int b_g[6];
int rs = INT_MAX, cur_rs = 0, g_visited = 0, min_m = INT_MAX;
bool check_x(int i, int no){
    if(i > 0 && visited[i]) return false;
    if(load[no] + d[i] > Q) return false;
    return true;
}

void try_x(int i, int no){
    if(cur_rs + (n - g_visited + 1) * min_m >= rs) return;
    for(int j = n; j >= 0; j--){
        if(check_x(j, no)){
            if(j){
                g_visited++;
                b_g[no]++;
                if(b_g[no] > b_g[no - 1]){
                    g_visited--;
                    b_g[no]--;
                    return;
                }
            }
            load[no] += d[j];
            visited[j] = true;
            cur_rs += m[i][j];
            if(j > 0) try_x(j, no);
            else{
                if(g_visited == n){
                    if(rs > cur_rs) rs = cur_rs;
                }else{
                    if(no < K){
                        try_x(0, no + 1);
                    }
                }
            }
            visited[j] = false;
            load[no] -= d[j];
            cur_rs -= m[i][j];
            if(j){
                g_visited--;
                b_g[no]--;
            }
        }
    }
}


int main() 
{ 
    scanf("%d %d %d", &n, &K, &Q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &d[i]);
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            scanf("%d", &m[i][j]);
            if(m[i][j]) min_m = min(min_m, m[i][j]);
        }
    }
    b_g[0] = INT_MAX;
    try_x(0, 1);
    printf("%d", rs);
}
