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
    int x, y;
    cin >> x >> y;
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> prefix0(n + 1, 0), prefix1(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(s[i] == '0'){
            prefix0[i] = prefix0[i - 1] + 1;
            prefix1[i] = prefix1[i - 1];
        }
        else{
            prefix1[i] = prefix1[i - 1] + 1;
            prefix0[i] = prefix0[i - 1];
        }
    }
    for(int i = 1; i <= n; i++){
        prefix0[i] *= y;
        prefix1[i] *= x;
    }
    int res = 0;
    map<int, int> mp;
    mp[0] = 1;
    for(int i = 1; i <= n; i++){
        res += mp[prefix0[i] - prefix1[i]];
        ++mp[prefix0[i] - prefix1[i]];
    }
    cout << res << endl;
    return (0 ^ 0);
}