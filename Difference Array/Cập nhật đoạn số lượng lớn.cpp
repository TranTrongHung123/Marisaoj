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

int n, q, m, diff[maxn], fre[maxn], a[maxn], prefix[maxn];
pair<int, int> update[maxn];

TranHungss(){
    FastIO();
    cin >> n >> q >> m;
    for(int i = 1; i <= q; i++){
        cin >> update[i].first >> update[i].second;
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        ++diff[x];
        --diff[y + 1];
    }
    for(int i = 1; i <= q; i++){
        fre[i] = fre[i - 1] + diff[i];
    }
    for(int i = 1; i <= q; i++){
        int l = update[i].first, r = update[i].second;
        a[l] += fre[i];
        a[r + 1] -= fre[i];
    }
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        cout << prefix[i] << " ";
    }
    return (0 ^ 0);
}