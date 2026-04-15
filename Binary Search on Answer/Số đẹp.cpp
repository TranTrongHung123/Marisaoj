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

const int INF = (int)1e18;

int prime[3] = {3, 5, 7};

int lcm(int a, int b){
    return a / __gcd(a, b) * b; 
}

int f(int n){
    int res = 0;
    for(int mask = 1; mask < (1 << 3); mask++){
        int x = 1;
        for(int i = 0; i < 3; i++){
            if((mask >> i) & 1){    
                x = lcm(x, prime[i]);
            }
        }
        if(__builtin_popcount(mask) & 1){
            res += n / x;
        }
        else{
            res -= n / x;
        }
    }
    return res;
}

TranHungss(){
    FastIO();
    int k; cin >> k;
    int res = 0, left = 3, right = 1e18;
    while(left <= right){
        int mid = left + right >> 1;
        if(f(mid) >= k){
            res = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << res << endl;
    return (0 ^ 0);
}