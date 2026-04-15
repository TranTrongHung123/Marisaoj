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

const int maxn = 1000001;

int child[maxn][26], cnt[maxn] = {1}, deep[maxn] = {1}, id = 1;

void build(const string &s, int &res){
    int root = 0;
    for(char c : s){
        for(int i = 0; i < 26; i++){
            if(i != c - 'a' && child[root][i] != 0){
                res += cnt[child[root][i]] * deep[root];
            }
        }
        if(child[root][c - 'a'] == 0){
            child[root][c - 'a'] = id++;
        }
        deep[child[root][c - 'a']] = deep[root] + 1;
        root = child[root][c - 'a'];
        ++cnt[root];
    }
}

TranHungss(){
    FastIO();
    int n; cin >> n;
    string a[n];
    for(auto &s : a) cin >> s;
    int res = 0;
    for(auto x : a){
        build(x, res);
    }
    cout << res << endl;
    return (0 ^ 0);
}