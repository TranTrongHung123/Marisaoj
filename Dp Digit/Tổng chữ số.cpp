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

int dp[15][2][150];

int solve(int pos, int tight, int sum, const string &s){
    if(pos == s.size()) return sum;
    if(dp[pos][tight][sum] != -1) return dp[pos][tight][sum];
    int res = 0, limit = tight ? s[pos] - '0' : 9;
    for(int d = 0; d <= limit; d++){
        res += solve(pos + 1, tight && d == limit, sum + d, s);
    }
    return dp[pos][tight][sum] = res;
}

int f(int n){
    memset(dp, -1, sizeof(dp));
    string s = to_string(n);
    return solve(0, 1, 0, s);
}

TranHungss(){
    FastIO();
    int x, y;
    cin >> x >> y;
    if(x == 0){
        cout << f(y) << endl;
    }
    else{
        cout << f(y) - f(x - 1) << endl;
    }
    return (0 ^ 0);
}