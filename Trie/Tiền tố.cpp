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

const int maxn = 20 * 100001;

int child[maxn][26], isEnd[maxn], id = 1;

bool check(const string &s){
    int root = 0;
    for(char c : s){
        if(child[root][c - 'a'] == 0){
            child[root][c - 'a'] = id++;
        }
        root = child[root][c - 'a'];
        if(isEnd[root]) return true;
    }   
    for(int i = 0; i < 26; i++){
        if(child[root][i]){
            return true;
        }
    }
    isEnd[root] = 1;
    return false;
}

TranHungss(){
    FastIO();
    int n; cin >> n;
    string a[n];
    for(auto &x : a) cin >> x;
    bool ok = true;
    for(auto x : a){
        if(check(x)){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return (0 ^ 0);
}