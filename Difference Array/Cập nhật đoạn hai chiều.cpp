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

const int maxn = 1005;

int n, m, q, matrix[maxn][maxn], prefix[maxn][maxn];

TranHungss(){
    FastIO();
    cin >> n >> m >> q;
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ++matrix[a][b];
        --matrix[c + 1][b];
        --matrix[a][d + 1];
        ++matrix[c + 1][d + 1];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            prefix[i][j] = matrix[i][j] + prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }
    return (0 ^ 0);
}