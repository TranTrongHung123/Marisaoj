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

bool cmp(pair<int, int> x, pair<int, int> y){
    return x.second < y.second;
}

 _nO_Op_ {
    FastIO();
    int n, q;
    cin >> n >> q;
    pair<int, int> a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, cmp);
    int prefix[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i].first;
    }
    while(q--){
        int k; cin >> k;
        auto it = lower_bound(prefix + 1, prefix + n + 1, k);
        cout << a[distance(prefix, it)].second << endl;
    }
    return (0 ^ 0);
}