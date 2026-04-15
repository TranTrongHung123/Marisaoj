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

// Viết tất cả các số nguyên dương trên một hàng theo thứ tự tăng dần như sau: 1234567891011121314.... tìm số thứ k

const int INF = (int)1e18;
const int maxn = 100;

int p[maxn] = {1}, f[maxn], scs[maxn];

void init(){
    // p[i] = 10^i
    for(int i = 1; i <= 18; i++){
        p[i] = 10 * p[i - 1];
    }
    // Số có i chữ số thì tạo ra đc f(i) = 9 * i * 10^(i - 1) chữ số
    for(int i = 1; i <= 18; i++){ 
        f[i] = 9 * i * p[i - 1];
    }
    // Số chữ số tạo ra từ 1 -> i: scs[i] = f(1) + f(2) + ... + f(i)
    for(int i = 1; i <= 18; i++){
        scs[i] = scs[i - 1] + f[i];
    }
}

TranHungss(){
    FastIO();
    init();
    int k; cin >> k;
    int x = lower_bound(scs + 1, scs + 19, k) - scs; // Số lượng chữ số của số cần tìm
    // Số cần tìm là: num = (k - scs[x - 1] - 1) / x + 10^(x - 1)
    // Vị trí k trong số cần tìm là: pos = (k - scs[x - 1] - 1) % x
    int tmp = k - scs[x - 1] - 1;
    int num = tmp / x + p[x - 1];
    int pos = tmp % x;
    string s = to_string(num);
    cout << s[pos] << endl;
    return (0 ^ 0);
}