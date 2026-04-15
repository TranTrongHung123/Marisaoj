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
const int block_size = 320;

struct Data{
    int l, r, idx;
} query[maxn];

int n, m, a[maxn], res[maxn], fre[maxn], cnt = 0;

bool cmp(Data x, Data y){
    int block_x = x.l / block_size;
    int block_y = y.l / block_size;
    if(block_x != block_y){
        return block_x < block_y;
    }
    if(block_x & 1){
        return x.r > y.r;
    }
    return x.r < y.r;
}

void add(int pos){
    int val = a[pos];
    ++fre[val];
    if(fre[val] == 1){
        ++cnt;
    }
}

void del(int pos){
    int val = a[pos];
    --fre[val];
    if(fre[val] == 0){
        --cnt;
    }
}

TranHungss(){
    FastIO();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        query[i] = {u, v, i};
    }
    sort(query + 1, query + m + 1, cmp);
    int left = 1, right = 0;
    for(int i = 1; i <= m; i++){
        while(left > query[i].l) add(--left);
        while(left < query[i].l) del(left++);
        while(right < query[i].r) add(++right);
        while(right > query[i].r) del(right--);
        res[query[i].idx] = cnt;
    }
    for(int i = 1; i <= m; i++){
        cout << res[i] << endl;
    }
    return (0 ^ 0);
}