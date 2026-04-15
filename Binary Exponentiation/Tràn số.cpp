#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define endl "\n"
#define int long long
#define double long double
#define _nO_Op_ signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int BASE1 = 311;
const int BASE2 = 997;
const int INF = (int)1e18;

int mul(int a, int b, int c){
    if(b == 0){
        return 0;
    }
    int x = mul(a, b / 2, c) % c;
    if(b & 1){
        return ((x + x) % c + a % c) % c;
    }
    else{
        return (x + x) % c;
    }
}

 _nO_Op_ {
    FastIO();
    int a, b, c;
    cin >> a >> b >> c;
    cout << mul(a, b, c) << endl;
    return (0 ^ 0);
}