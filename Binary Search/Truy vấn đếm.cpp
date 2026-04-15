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
const int maxn = 100005;
const int block = 500;

int n, m, a[maxn], freq[maxn], res[maxn];

struct Data{
    int l, r, x, idx;
} query[maxn];

bool cmp(Data a, Data b){
    int block_l = a.l / block;
    int block_r = b.l / block;
    if(block_l != block_r){
        return block_l < block_r;
    }
    if(block_l & 1){
        return a.r < b.r;
    }
    return a.r > b.r;
}

void add(int x){
    ++freq[x];
}

void del(int x){
    --freq[x];
}

 _nO_Op_ {
    FastIO();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        int l, r, x;
        cin >> l >> r >> x;
        query[i] = {l, r, x, i};
    }
    sort(query + 1, query + m + 1, cmp);
    int left = 1, right = 0;
    for(int i = 1; i <= m; i++){
        while(left > query[i].l) add(a[--left]);
        while(right < query[i].r) add(a[++right]);
        while(left < query[i].l) del(a[left++]);
        while(right > query[i].r) del(a[right--]);
        res[query[i].idx] = freq[query[i].x];
    }
    for(int i = 1; i <= m; i++){
        cout << res[i] << endl;
    }
    return (0 ^ 0);
}