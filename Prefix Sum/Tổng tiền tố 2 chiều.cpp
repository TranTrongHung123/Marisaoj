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
    int n, m, q;
    cin >> n >> m >> q;
    int a[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            prefix[i][j] = a[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << prefix[c][d] - prefix[c][b - 1] - prefix[a - 1][d] + prefix[a - 1][b - 1] << endl;
    }
    return (0 ^ 0);
}