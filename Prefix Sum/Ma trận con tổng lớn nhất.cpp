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

const int maxn = 505;

int n, m, a[maxn][maxn], prefix[maxn][maxn];

int Kadane(vector<int> &vt){
    vector<int> dp(begin(vt), end(vt));
    for(int i = 1; i < vt.size(); i++){
        dp[i] = max(dp[i], dp[i - 1] + vt[i]);
    }
    return *max_element(begin(dp), end(dp));
}

TranHungss(){
    FastIO();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            prefix[i][j] = a[i][j] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
        }
    }
    int res = LLONG_MIN;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            vector<int> vt;
            for(int k = 1; k <= m; k++){
                int tmp = prefix[j][k] - prefix[i - 1][k] - prefix[j][k - 1] + prefix[i - 1][k - 1];
                vt.push_back(tmp);
            }
            res = max(res, Kadane(vt));
        }
    }
    cout << res << endl;
    return (0 ^ 0);
}