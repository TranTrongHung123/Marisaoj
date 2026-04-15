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
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> pre(n, LLONG_MIN);
    pre[0] = a[0];
    int pos1 = a[0];
    for(int i = 1; i < n; i++){
        pos1 = max(a[i], pos1 + a[i]);
        pre[i] = max({pre[i], pre[i - 1], pos1});
    }
    vector<int> suf(n, LLONG_MIN);
    suf[n - 1] = a[n - 1];
    int pos2 = a[n - 1];
    for(int i = n - 2; i >= 0; i--){
        pos2 = max(a[i], pos2 + a[i]);
        suf[i] = max({suf[i], suf[i + 1], pos2});
    }
    int res = LLONG_MIN;
    for(int i = 0; i < n - 1; i++){
        res = max(res, pre[i] + suf[i + 1]);
    }
    cout << res << endl;
    return (0 ^ 0);
}