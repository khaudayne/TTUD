#include<bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp(1001, vector<long long>(1001, 0));
int main(){
    int n, tmp1, tmp2, c, max_x = -1, max_y = -1;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d", &tmp1, &tmp2, &c);
        dp[tmp1][tmp2] += c;
        max_x =  max(max_x, tmp1);
        max_y=  max(max_y, tmp2);
    }
    for(int i = 1; i <= 1001; i++){
        dp[0][i] += dp[0][i - 1];
        dp[i][0] += dp[i - 1][0];
    }
    for(int i = 1; i <= max_x; i++){
        for(int j = 1; j <= max_y; j++){
            dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%lld", dp[max_x][max_y]);
}
