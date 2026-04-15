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
    int k; cin >> k;
    stack<char> stk;
    for(char c : s){
        while(stk.size() && k && stk.top() < c){
            stk.pop();
            --k;
        }
        stk.push(c);
    }
    while(k--){
        stk.pop();
    }
    string res = "";
    while(stk.size()){
        res += stk.top();
        stk.pop();
    }
    reverse(begin(res), end(res));
    cout << res << endl;
    return (0 ^ 0);
}