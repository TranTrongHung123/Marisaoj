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

const int inf = (int)1e18;
const int mod = 1e9 + 7;

TranHungss(){
    FastIO();
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if(j >= 1){
                dp[i][j] += ((dp[i - 1][j - 1] % mod) * (a[i] % mod)) % mod;
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][m] << endl;
    return (0 ^ 0);
}