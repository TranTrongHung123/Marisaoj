#include <bits/stdc++.h>
#define base1 311
#define base2 997
#define endl "\n"
#define int long long
#define double long double
#define uint unsigned long long
#define _nO_Op_ signed main()
#define __builtin_popcount __builtin_popcountll
#define join(z, x, y); merge(begin(x), end(x), begin(y), end(y), back_inserter(z));
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = (int)1e18;
const double eps = 1e-4;

bool check(double x, double a[], int n, int k){
    double prefix[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + a[i] - x;
    }
    double mn = prefix[0];
    for(int i = k; i <= n; i++){
        mn = min(mn, prefix[i - k]);
        if(prefix[i] - mn >= 0){
            return true;
        }
    }
    return false;
}

 _nO_Op_ {
    FastIO();
    int n, k;
    cin >> n >> k;
    double a[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    double left = 1, right = 1e9;
    // while(right - left > eps){
    //     double mid = (right + left) / 2;
    //     if(check(mid, a, n, k)){
    //         left = mid;
    //     }
    //     else{
    //         right = mid;
    //     }
    // }
    for(int i = 0; i < 100; i++){
        double mid = (right + left) / 2;
        if(check(mid, a, n, k)){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    cout << fixed << setprecision(3) << left << endl;
    return (0 ^ 0);
}