#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define TranHungss() signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = (int)1e18;

bool check(int x, int a[], int n, int k){
    int cnt = 1, sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > x) return false;
        if(sum + a[i] <= x){
            sum += a[i];
        }
        else{
            sum = a[i];
            ++cnt;
        }
    }
    return cnt <= k;
}

TranHungss(){
    FastIO();
    int n, k;
    cin >> n >> k;
    int a[n];
    for(auto &x : a){
        cin >> x;
    }
    int res = 0, left = 1, right = 1e14;
    while(left <= right){
        int mid = left + right >> 1;
        if(check(mid, a, n, k)){
            res = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << res << endl;
    return (0 ^ 0);
}