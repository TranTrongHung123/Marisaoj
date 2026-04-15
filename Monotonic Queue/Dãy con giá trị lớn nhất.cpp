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

const int maxn = 1e5 + 5;

int n, m, k, a[maxn], dp[205][maxn];

TranHungss() {
    FastIO();
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) dp[1][i] = a[i];
    for (int t = 2; t <= k; t++) {
        deque<int> dq;
        for (int i = 1; i <= n; i++) {
            while (!dq.empty() && dq.front() < i - m) dq.pop_front();
            while (!dq.empty() && dp[t - 1][dq.back()] <= dp[t - 1][i - 1]) dq.pop_back();
            dq.push_back(i - 1);
            if (!dq.empty()) dp[t][i] = dp[t - 1][dq.front()] + t * a[i];
        }
    }
    int res = LLONG_MIN;
    for (int i = 1; i <= n; i++) res = max(res, dp[k][i]);
    cout << res << endl;
    return 0;
}