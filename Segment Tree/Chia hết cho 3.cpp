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

struct Node{    
    int cnt0, cnt1, cnt2;
} IT[4 * maxn];

int n, q, a[maxn], lazy[4 * maxn];

Node merge(Node x, Node y){
    return {x.cnt0 + y.cnt0, x.cnt1 + y.cnt1, x.cnt2 + y.cnt2};
}

void build(int i, int l, int r){
    if(l == r){
        if(a[l] % 3 == 0){
            IT[i] = {1, 0, 0};
        }
        else if(a[l] % 3 == 1){
            IT[i] = {0, 1, 0};
        }
        else{
            IT[i] = {0, 0, 1};
        }
    }
    else{
        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        IT[i] = merge(IT[2 * i], IT[2 * i + 1]);
    }
}

void add(int i, int val){
    val %= 3;
    int tmp0 = IT[i].cnt0, tmp1 = IT[i].cnt1, tmp2 = IT[i].cnt2;
    if(val == 1){
        IT[i] = {tmp2, tmp0, tmp1};
    }
    else if(val == 2){
        IT[i] = {tmp1, tmp2, tmp0};
    }
}

void push(int i){
    if(lazy[i] == 0) return;
    lazy[2 * i] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    add(2 * i, lazy[i]);
    add(2 * i + 1, lazy[i]);
    lazy[i] = 0;
}

void update(int i, int l, int r, int u, int v){
    if(l > v || r < u) return;
    if(l >= u && r <= v){
        add(i, 1);
        lazy[i] += 1;
        return;
    }
    push(i);
    int m = (l + r) >> 1;
    update(2 * i, l, m, u, v);
    update(2 * i + 1, m + 1, r, u, v);
    IT[i] = merge(IT[2 * i], IT[2 * i + 1]);
}

Node getAns(int i, int l, int r, int u, int v){
    if(l > v || r < u) return {0, 0, 0};
    if(l >= u && r <= v) return IT[i];
    push(i);
    int m = (l + r) >> 1;
    auto s1 = getAns(2 * i, l, m, u, v);
    auto s2 = getAns(2 * i + 1, m + 1, r, u, v);
    return merge(s1, s2);
}

TranHungss(){
    FastIO();
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 1){
            update(1, 1, n, u, v);
        }
        else{
            auto res = getAns(1, 1, n, u, v);
            cout << res.cnt0 << endl;
        }
    }
    return (0 ^ 0);
}