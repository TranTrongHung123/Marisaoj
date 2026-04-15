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
    int cnt = 0;
    for(auto x : s){
        if(x == '0'){
            ++cnt;
        }
    }
    sort(begin(s), end(s));
    cout << s[cnt] + string(cnt, '0') + s.substr(cnt + 1) << endl;
    return (0 ^ 0);
}