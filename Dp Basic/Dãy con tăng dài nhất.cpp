#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define TranHungss() signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int inf = (int)1e18;

TranHungss(){
    FastIO();
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    vector<int> res; res.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(a[i] > res.back()){
            res.push_back(a[i]);
        }
        else{
            auto it = lower_bound(begin(res), end(res), a[i]);
            res[distance(res.begin(), it)] = a[i];
        }
    }
    cout << res.size() << endl;
    return (0 ^ 0);
}