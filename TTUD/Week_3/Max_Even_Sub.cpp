#include <bits/stdc++.h>
using namespace std;
long long const long_min = -1e15;
int main()
{
    int n;
    long long tmp, sum_old = long_min, sum_even = long_min, rs = long_min, tmp1;
    scanf("%d", &n);
    while(n--){
        scanf("%lld", &tmp);
        if(tmp % 2 != 0){
            tmp1 = sum_even;
            if(sum_old != long_min) sum_even = sum_old + tmp;
            else sum_even = long_min;
            if(tmp1 != long_min) sum_old = tmp1 + tmp;
            else sum_old = long_min;
            sum_old = max(sum_old, tmp);
        }else{
            if(sum_old != long_min) sum_old = sum_old + tmp;
            if(sum_even != long_min) sum_even = sum_even + tmp;
            sum_even = max(sum_even, tmp);
        }
        rs = max(rs, sum_even);
    }
    if(rs != long_min) printf("%lld", rs);
    else printf("NOT_FOUND");
}
