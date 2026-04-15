#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define _nO_Op_ signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = (int)1e18;

 _nO_Op_ {
    FastIO();
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int prefix[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }
    int res = 0;
    for(int i = 0; i <= n; i++){
        auto it = lower_bound(prefix + i + 1, prefix + n + 1, prefix[i] + k);
        res += distance(it, prefix + n + 1);
    }
    cout << res << endl;
    return (0 ^ 0);
}