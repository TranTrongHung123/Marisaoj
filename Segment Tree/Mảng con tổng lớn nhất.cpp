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
const int inf = (int)1e18;

struct Node {
    int max_sum, pre, suf, sum;
} IT[4 * maxn];

int n, q, a[maxn];

Node merge(Node x, Node y){
    Node res;
    res.sum = x.sum + y.sum;
    res.max_sum = max({x.max_sum, y.max_sum, x.suf + y.pre});
    res.pre = max(x.pre, x.sum + y.pre);
    res.suf = max(y.suf, y.sum + x.suf);
    return res;
}

void build(int i, int l, int r){
    if(l == r){
        IT[i] = {a[l], a[l], a[l], a[l]};
    }
    else{
        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        IT[i] = merge(IT[2 * i], IT[2 * i + 1]);
    }
}

Node getAns(int i, int l, int r, int u, int v){
    if(l > v || r < u) return {-inf, -inf, -inf, 0LL}; 
    if(l >= u && r <= v) return IT[i];
    int m = (l + r) >> 1;
    auto s1 = getAns(2 * i, l, m, u, v);
    auto s2 = getAns(2 * i + 1, m + 1, r, u, v);
    return merge(s1, s2);
}

TranHungss(){
    FastIO();
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << getAns(1, 1, n, u, v).max_sum << endl;
    }
    return (0 ^ 0);
}