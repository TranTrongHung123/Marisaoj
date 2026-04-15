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

const int maxn = 100001;

int n, q, a[maxn];
vector<int> IT[4 * maxn];

void build(int i, int l, int r){
    if(l == r){
        IT[i].push_back(a[l]);
    }
    else{
        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        join(IT[i], IT[2 * i], IT[2 * i + 1]);
    }
}

int getAns(int i, int l, int r, int u, int v, int k){
    if(l > v || r < u) return 0;
    if(l >= u && r <= v){
        auto it = upper_bound(begin(IT[i]), end(IT[i]), k);
        return distance(it, IT[i].end());
    }
    int m = (l + r) >> 1;
    int s1 = getAns(2 * i, l, m, u, v, k);
    int s2 = getAns(2 * i + 1, m + 1, r, u, v, k);
    return s1 + s2;
}

TranHungss(){
    FastIO();
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int u, v, k;
        cin >> u >> v >> k;
        cout << getAns(1, 1, n, u, v, k) << endl;
    }
    return (0 ^ 0);
}