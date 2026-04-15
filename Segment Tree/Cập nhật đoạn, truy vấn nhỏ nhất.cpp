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

const int maxn = 100001;

int n, q, a[maxn], IT[4 * maxn], lazy[4 * maxn];

void build(int i, int l, int r){
    if(l == r){
        IT[i] = a[l];
    }
    else{
        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        IT[i] = min(IT[2 * i], IT[2 * i + 1]);
    }
}

void push(int i){
    if(lazy[i] == 0) return;
    IT[2 * i] += lazy[i];
    lazy[2 * i] += lazy[i];
    IT[2 * i + 1] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    lazy[i] = 0;
}

void update(int i, int l, int r, int u, int v, int val){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        IT[i] += val;
        lazy[i] += val;
        return;
    }
    push(i);
    int m = (l + r) >> 1;
    update(2 * i, l, m, u, v, val);
    update(2 * i + 1, m + 1, r, u, v, val);
    IT[i] = min(IT[2 * i], IT[2 * i + 1]);
}

int getMin(int i, int l, int r, int u, int v){
    if(l > v || r < u) return LLONG_MAX;
    if(l >= u && r <= v) return IT[i];
    push(i);
    int m = (l + r) >> 1;
    int s1 = getMin(2 * i, l, m, u, v);
    int s2 = getMin(2 * i + 1, m + 1, r, u, v);
    return min(s1, s2);
}

TranHungss(){
    FastIO();
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int x; cin >> x;
        if(x == 1){
            int u, v, val;
            cin >> u >> v >> val;
            update(1, 1, n, u, v, val);
        }
        else{
            int u, v;
            cin >> u >> v;
            cout << getMin(1, 1, n, u, v) << endl;
        }
    }
    return (0 ^ 0);
}