#include <bits/stdc++.h>
using namespace std;
int const mdl = 1e9 + 7;
int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
          int right);
 
int mergeSort(int arr[], int array_size)
{
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left) {

        mid = (right + left) / 2;

        inv_count = (inv_count + _mergeSort(arr, temp, left, mid) % mdl) % mdl;
        inv_count = (inv_count + _mergeSort(arr, temp, mid + 1, right) % mdl) % mdl;

        inv_count = (inv_count + merge(arr, temp, left, mid + 1, right) % mdl) % mdl;
    }
    return inv_count;
}

int merge(int arr[], int temp[], int left, int mid,
          int right)
{
    int i, j, k;
    int inv_count = 0;
 
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = (inv_count + (mid - i) % mdl) % mdl;
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d", mergeSort(a, n)) ;
}

// #include <bits/stdc++.h> 
// using namespace std;
// struct comparePair {
//     bool operator()(pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2)
//     {
//         return p1.first.second > p2.first.second;
//     }
// };
// int main() 
// { 
//     int n, t1, t2;
//     scanf("%d", &n);
//     vector<pair<int, int>> v(n);
//     for(int i = 0; i < n; i++){
//         scanf("%d %d", &t1, &t2);
//         v[i] = {t1, t2};
//     }
//     sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
//         return a.first < b.first;
//     });  
//     priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comparePair> pq;
//     pair<int, int> caingolnhatvuabidayra;
//     for(auto x : v){
//         int max_L = 1;
//         while(!pq.empty() && x.first >= pq.top().first.second){
//             if(max_L < pq.top().second + 1){
//                 max_L = pq.top().second + 1;
//                 caingolnhatvuabidayra = pq.top().first;
//             }
//             pq.pop();        
//         }
//         pq.push({caingolnhatvuabidayra, max_L - 1});
//         pq.push({x, max_L});
//     }
//     int rs = INT_MIN;
//     while(!pq.empty()){
//         rs = max(rs, pq.top().second);
//         pq.pop();
//     }
//     printf("%d", rs);
// }
