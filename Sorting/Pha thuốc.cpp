#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define TranHungss() signed main()
#define __builtin_popcount __builtin_popcountll
#define join(x, y, z); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

TranHungss(){
    FastIO();
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a + n);
    int res = 0, l = 0, r = n - 1;
    while(l <= r){
        res += 1;
        if(a[l] + a[r] <= k){
            ++l; --r;
        }
        else{
            --r;
        }
    }
    cout << res << endl;
    return (0 ^ 0);
}