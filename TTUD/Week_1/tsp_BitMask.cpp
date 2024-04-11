#include <bits/stdc++.h> 
using namespace std;
int n;
int tcp(vector<vector<int>> m, vector<vector<int>> dp, int check_all, int pos, int des){
    if(pos == check_all) return m[0][des];
    if(dp[pos][des] != -1) return dp[pos][des];
    int r = INT_MAX;
    for(int i = 1; i <= n; i++){
        if((pos & (1 << i)) == 0){
            int new_r = tcp(m, dp, check_all, pos | (1 << i), i) + m[i][des];
            r = min(r, new_r);
        } 
    }
    dp[pos][des] = r;
    return dp[pos][des];
}


int main() 
{ 
    cin >> n;
    vector<vector<int>> m(n + 1, vector<int>(n + 1));
    // dp[i][j] la mang luu tru duong di ngan nhat toi dinh j thong qua cac dinh duoc danh dau boi i ( khong chua j )
    vector<vector<int>> dp(1 << (n + 1) + 1, vector<int>(n + 1, -1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cin >> m[i][j];
        }
    }
    int check_all = (1 << (n + 1)) - 1;
    cout << tcp(m, dp, check_all, 1, 0);
}