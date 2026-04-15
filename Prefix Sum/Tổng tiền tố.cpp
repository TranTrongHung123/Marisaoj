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
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int prefix[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i];
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << endl;
    }
    return (0 ^ 0);
}
