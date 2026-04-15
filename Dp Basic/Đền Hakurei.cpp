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
const int mod = 1e9 + 7;

int dp[maxn] = {1, 1, 2, 4};

void init(){
    for(int i = 4; i < maxn; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    }
}

TranHungss(){
    FastIO();
    init();
    int n; cin >> n;
    cout << dp[n] << endl;
    return (0 ^ 0);
}