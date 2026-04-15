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

int dp[100][2][2];

int solve(int pos, int tight, int tight_Xor, string &y, string &x, string &s){
    if(pos == y.size()) return 1;
    if(dp[pos][tight][tight_Xor] != -1){
        return dp[pos][tight][tight_Xor];
    }
    int res = 0, limit = tight ? y[pos] - '0' : 1;
    for(int d = 0; d <= limit; d++){
        int bit =  d ^ (x[pos] - '0');
        if(tight_Xor && bit > (s[pos] - '0')) continue;
        res += solve(pos + 1, tight && d == limit, tight_Xor && bit == (s[pos] - '0'), y, x, s);
    }
    return dp[pos][tight][tight_Xor] = res;
}

int f(int n, int x, int s){
    memset(dp, -1, sizeof(dp));
    string _n = bitset<60>(n).to_string();
    string _x = bitset<60>(x).to_string();
    string _s = bitset<60>(s).to_string();
    return solve(0, 1, 1, _n, _x, _s);
}

TranHungss(){
    FastIO();
    int x, l, r, s;
    cin >> x >> l >> r >> s;
    cout << f(r, x, s) - f(l - 1, x, s) << endl;
    return (0 ^ 0);
}