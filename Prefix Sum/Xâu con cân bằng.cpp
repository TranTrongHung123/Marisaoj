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

TranHungss(){
    FastIO();
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int x = (s[i] == '0' ? -1 : 1);
        prefix[i] = prefix[i - 1] + x;
    }
    int res = 0;
    map<int, int> mp;
    mp[0] = 1;
    for(int i = 1; i <= n; i++){
        res += mp[prefix[i]];
        ++mp[prefix[i]];
    }
    cout << res << endl;
    return (0 ^ 0);
}