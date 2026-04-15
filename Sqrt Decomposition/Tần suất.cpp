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

const int maxn = 100005;
const int block_size = 320;

int n, q, a[maxn], fre[maxn], cnt[maxn], res[maxn];

struct Data{
    int l, r, x, idx;
} Query[maxn];

bool cmp(Data x, Data y){
    int block_x = x.l / block_size;
    int block_y = y.l / block_size;
    if(block_x != block_y){
        return block_x < block_y;
    }
    if(block_x & 1) return x.r > y.r;
    return x.r < y.r;
}

void add(int pos){
    int val = a[pos];
    --cnt[fre[val]];
    ++fre[val];
    ++cnt[fre[val]];
}

void del(int pos){
    int val = a[pos];
    --cnt[fre[val]];
    --fre[val];
    ++cnt[fre[val]];
}

TranHungss(){
    FastIO();
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= q; i++){
        int l, r, x;
        cin >> l >> r >> x;
        Query[i] = {l, r, x, i};
    }
    sort(Query + 1, Query + q + 1, cmp);
    int L = Query[1].l, R = Query[1].r;
    for(int i = L; i <= R; i++){
        add(i);
    }
    res[Query[1].idx] = cnt[Query[1].x];
    for(int i = 2; i <= q; i++){
        while(L > Query[i].l) add(--L);
        while(R < Query[i].r) add(++R);
        while(L < Query[i].l) del(L++);
        while(R > Query[i].r) del(R--);
        res[Query[i].idx] = cnt[Query[i].x];
    }
    for(int i = 1; i <= q; i++){
        cout << res[i] << endl;
    }
    return (0 ^ 0);
}