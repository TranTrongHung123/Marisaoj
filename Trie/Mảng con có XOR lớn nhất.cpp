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

const int maxn = 1000001;

int n, a[maxn], dp[maxn], child[maxn][2], id = 1;

void build(int x){
    int root = 0;
    for(int i = 31; i >= 0; i--){
        int bit = (x >> i) & 1;
        if(child[root][bit] == 0){
            child[root][bit] = id++;
        }
        root = child[root][bit];
    }
}

int get(int x){
    int res = 0, root = 0;
    for(int i = 31; i >= 0; i--){
        int bit = (x >> i) & 1;
        if(child[root][bit ^ 1]){
            res |= (1 << i);
            root = child[root][bit ^ 1];
        }
        else{
            root = child[root][bit];
        }
    }
    return res;
}

TranHungss(){
    FastIO();
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) dp[i] = dp[i - 1] ^ a[i];
    build(0);
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, get(dp[i]));
        build(dp[i]);
    }
    cout << res << endl;
    return (0 ^ 0);
}