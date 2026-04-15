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

int n, q, a[maxn], lg[maxn];
pair<int, int> spt[20][maxn];

void Sparse_Table(){
    for(int i = 1; i <= n; i++){
        lg[i] = __lg(i);
    }
    for(int i = 1; i <= n; i++){
        spt[0][i] = {a[i], i};
    }
    for(int i = 1; i <= __lg(n); i++){
        for(int j = 1; j <= n - (1 << i) + 1; j++){
            spt[i][j] = min(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))]);
        }
    }
}

pair<int, int> getMin(int l, int r){
    int k = lg[r - l + 1];
    return min(spt[k][l], spt[k][r - (1 << k) + 1]);
}

TranHungss(){
    FastIO();
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    Sparse_Table();
    while(q--){
        int x, y;
        cin >> x >> y;
        auto res = getMin(x, y);
        cout << res.second << endl;
    }
    return (0 ^ 0);
}