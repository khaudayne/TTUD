#include <bits/stdc++.h>
using namespace std;
int const M = 1e9 + 7;
int main()
{
    int N, K1, K2;
    scanf("%d %d %d", &N, &K1, &K2);
    vector<int> v(N + 1, 0);
    v[K1] = 1;
    for(int i = K1 + 1; i <= N; i++){
        for(int j = K1; j <= min(K2, i); j++){
            if(i - j - 1 <= 0) v[i] = (v[i] + 1) % M;
            else v[i] = (v[i] + v[i - j - 1]) % M;
        }
    }
    printf("%d", (v[N] + v[N - 1]) % M);
}
