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
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;  
    deque<int> dq;
    for(int i = 0; i < k; i++){
        while(dq.size() && a[i] <= a[dq.back()]) dq.pop_back();
        dq.push_back(i);
    } 
    cout << a[dq.front()] << " ";
    for(int i = k; i < n; i++){
        while(dq.size() && a[i] <= a[dq.back()]) dq.pop_back();
        while(dq.size() && dq.front() <= i - k) dq.pop_front();
        dq.push_back(i);
        cout << a[dq.front()] << " ";
    }
    return (0 ^ 0);
}