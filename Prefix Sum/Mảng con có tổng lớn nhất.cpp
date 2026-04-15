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
    for(auto &x : a) cin >> x;
    vector<int> dp(a, a + n);
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i], dp[i - 1] + a[i]);
    }
    cout << *max_element(begin(dp), end(dp)) << endl;
    return (0 ^ 0);
}
