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

int dp[15][2][200][200];

int solve(int pos, int tight, int sum, int sum_digit, const string &s, int k){
    if(pos == s.size()) return sum == 0 && sum_digit == 0;
    if(dp[pos][tight][sum][sum_digit] != -1) return dp[pos][tight][sum][sum_digit];
    int res = 0, limit = tight ? s[pos] - '0' : 9;
    for(int d = 0; d <= limit; d++){
        res += solve(pos + 1, tight && d == limit, (10 * sum + d) % k, (sum_digit + d) % k, s, k);
    }
    return dp[pos][tight][sum][sum_digit] = res;
}

int f(int n, int k){
    if(k > 117) return 0;
    memset(dp, -1, sizeof(dp));
    string s = to_string(n);
    return solve(0, 1, 0, 0, s, k);
}

TranHungss(){
    FastIO();
    int TC; cin >> TC;
    while(TC--){
        int a, b, k;
        cin >> a >> b >> k;
        cout << f(b, k) - f(a - 1, k) << endl;
    }
    return (0 ^ 0);
}