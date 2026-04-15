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
    int cnt = 1, pos = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] - pos >= x){
            cnt += 1;
            pos = a[i];
        }
    }
    return cnt >= k;
}

TranHungss(){
    FastIO();
    int n, k;
    cin >> n >> k;
    int a[n];
    for(auto &x : a){
        cin >> x;
    }
    sort(a, a + n);
    int res = 0, left = 0, right = 1e9;
    while(left <= right){
        int mid = left + right >> 1;
        if(check(mid, a, n, k)){
            res = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << res << endl;
    return (0 ^ 0);
}