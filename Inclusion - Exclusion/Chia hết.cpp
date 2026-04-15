#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;


long long lcm_cap(long long a, long long b, long long cap) {
    if(a == 0 || b == 0) return 0;
    long long g = __gcd(a, b);
    __int128 t = (__int128)(a / g) * b;
    if(t > cap) return cap + 1;  
    return (long long)t;
}

long long f(long long x, int a[], int n) {
    long long res = 0;
    for (long long mask = 1; mask < (1LL << n); mask++) {
        long long tmp = 1;
        bool over = false;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1LL) {
                tmp = lcm_cap(tmp, a[i], x);
                if (tmp > x) { over = true; break; }
            }
        }
        if (!over) {
            int bits = __builtin_popcountll(mask);
            if (bits & 1) res += x / tmp;
            else          res -= x / tmp;
        }
    }
    return res;
}

TranHungss(){
    FastIO();
    int n; long long l, r;
    cin >> n >> l >> r;
    int a[n];
    for (int &x : a) cin >> x;
    cout << f(r, a, n) - f(l - 1, a, n) << endl;
    return 0;
}