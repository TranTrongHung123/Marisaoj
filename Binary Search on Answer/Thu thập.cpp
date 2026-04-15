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
const double eps = 1e-6;

bool check(double x, pair<double, double> a[], int n, int k){
    vector<double> vt;
    for(int i = 0; i < n; i++){
        vt.push_back(a[i].first - a[i].second * x);
    }
    sort(begin(vt), end(vt), greater<double>());
    double sum = 0;
    for(int i = 0; i < k; i++){
        sum += vt[i];
    }
    return sum >= 0;
}

 _nO_Op_ {
    FastIO();
    int n, k;
    cin >> n >> k;
    pair<double, double> a[n];
    for(auto &[x, y] : a){
        cin >> x >> y;
    }
    double left = 1, right = 1e9;
    while(right - left > eps){
        double mid = (left + right) / 2;
        if(check(mid, a, n, k)){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    // for(int i = 0; i < 100; i++){
    //     double mid = (left + right) / 2;
    //     if(check(mid, a, n, k)){
    //         left = mid;
    //     }
    //     else{
    //         right = mid;
    //     }
    // }
    cout << fixed << setprecision(10) << left << endl;
    return (0 ^ 0);
}