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
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    int left[n], right[n];
    stack<int> stk;
    for(int i = 0; i < n; i++){
        while(stk.size() && a[stk.top()] >= a[i]) stk.pop();
        left[i] = stk.empty() ? -1 : stk.top();
        stk.push(i);
    }
    while(stk.size()) stk.pop();
    for(int i = n - 1; i >= 0; i--){
        while(stk.size() && a[stk.top()] >= a[i]) stk.pop();
        right[i] = stk.empty() ? n : stk.top();
        stk.push(i);
    }
    int res = LLONG_MIN;
    for(int i = 0; i < n; i++){
        res = max(res, a[i] * (right[i] - left[i] - 1));
    }
    cout << res << endl;
    return (0 ^ 0);
}