#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, T, D, rs = -1;
    scanf("%d %d %d", &N, &T, &D);
    int a[N + 1], t[N + 1];
    for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= N; i++) scanf("%d", &t[i]);
    vector<vector<int>> dp(N + 1, vector<int>(T + 1, -1));
    dp[1][T] = 0;
    dp[1][T - t[1]] = a[1];
    for(int i = 2; i <= N; i++){
        dp[i][T] = 0;
        for(int j = max(1, i - D); j < i; j++){
            for(int k = T - t[i]; k >= 0; k--){
                if(dp[j][k + t[i]] != -1){
                    dp[i][k] = max(dp[i][k], dp[j][k + t[i]] + a[i]);
                    rs = max(rs, dp[i][k]);
                }
            }
        }
    }
    printf("%d", rs);
}
