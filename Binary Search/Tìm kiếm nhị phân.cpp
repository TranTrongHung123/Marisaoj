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
    int n, q;
    cin >> n >> q;
    int a[n];
    for(auto &x : a) cin >> x;
    while(q--){
        int k; cin >> k;
        cout << distance(a, lower_bound(a, a + n, k)) + 1 << endl;
    }
    return (0 ^ 0);
}