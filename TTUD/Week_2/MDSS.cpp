#include <bits/stdc++.h> 
using namespace std;
int v[100000];
int f(int v[], int C, int N){
    int left = 0, right = v[N - 1] - v[0] + 1;
    if(C == 2) return right - left;
    int rs = 0, mid;
    while(left <= right){
        mid = (right + left)/ 2;
        bool ch = false;
        int last_Ix = 0, num_Choosed = 1;
        for(int i = 1; i < N; i++){
            if(v[i] - v[last_Ix] >= mid){
                last_Ix = i;
                num_Choosed++;
                if(num_Choosed >= C){
                    ch =  true;
                    break;
                }
            }
        }
        if(ch){
            rs = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return rs;
}
int main() 
{ 
    int T, N, C;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &C);
        for(int i = 0; i < N; i++){
            scanf("%d", &v[i]);
        }
        sort(v, v + N);
        printf("%d\n", f(v, C, N));
    } 
}