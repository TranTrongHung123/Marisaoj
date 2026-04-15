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

bool cmp(tuple<int, int, int> u, tuple<int, int, int> v){
    auto [x1, y1, z1] = u;
    auto [x2, y2, z2] = v;
    if(x1 != x2){
        return x1 < x2;
    }
    else if(y1 != y2){
        return y1 < y2;
    }
    return z1 < z2;
}

TranHungss(){
    FastIO();
    int n; cin >> n;
    tuple<int, int, int> a[n];
    for(auto &[x, y, z] : a) cin >> x >> y >> z;
    sort(a, a + n, cmp);
    for(auto &[x, y, z] : a){
        cout << x << " " << y << " " << z << endl;
    }
    return (0 ^ 0);
}