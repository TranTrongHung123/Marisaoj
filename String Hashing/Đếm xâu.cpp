#include <bits/stdc++.h>
#define base 311
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int maxn = 1000005;
const int mod = 1e9 + 9;

string s, t;
int n, m, HashT;

int HashS[maxn], p[maxn] = {1};

int getHash(int l, int r){
    return (HashS[r] - HashS[l - 1] * p[r - l + 1] + mod * mod) % mod;
}

TranHungss(){
    FastIO();
    cin >> s >> t;
    n = s.size(); m = t.size();
    s = " " + s; t = " " + t;
    for(int i = 1; i <= n; i++){
        HashS[i] = (HashS[i - 1] * base + (int)s[i]) % mod;
    }
    for(int i = 1; i <= m; i++){
        HashT = (HashT * base + (int)t[i]) % mod;
    }
    for(int i = 1; i <= m; i++){
        p[i] = (p[i - 1] * base) % mod;
    }
    int cnt = 0;
    for(int i = 1; i <= n - m + 1; i++){
        if(getHash(i, i + m - 1) == HashT){
            ++cnt;
        }
    }
    cout << cnt << endl;
    return (0 ^ 0);
}