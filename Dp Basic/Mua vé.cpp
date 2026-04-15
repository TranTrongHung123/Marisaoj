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

const int maxn = 100005;

int n, t[maxn], r[maxn], dp[maxn];

TranHungss(){
    FastIO();
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> t[i];
    for(int i = 2; i <= n; i++) cin >> r[i];
    dp[1] = t[1];
    for(int i = 2; i <= n; i++){
        dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i]);
    }
    cout << dp[n] << endl;
    return (0 ^ 0);
}