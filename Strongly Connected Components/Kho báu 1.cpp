#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int INF = 1e18;
const int maxn = 100005;
 
int n, m, id = 1, scc = 0;
int a[maxn], low[maxn], num[maxn], del[maxn], val[maxn];
vector<int> Ke[maxn];
stack<int> stk;
 
void inp(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    while(m--){
        int u, v;
        cin >> u >> v;
        Ke[u].push_back(v);
    }
}
 
void DFS(int u){
    low[u] = num[u] = id++;
    stk.push(u);
    for(int v : Ke[u]){
        if(del[v]) continue;
        if(num[v] == 0){
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], num[v]);
        }
    }
    if(low[u] == num[u]){
        ++scc;
        val[scc] = INF;
        while(stk.size() && stk.top() != u){
            val[scc] = min(val[scc], a[stk.top()]);
            del[stk.top()] = 1;
            stk.pop();
        }
        val[scc] = min(val[scc], a[stk.top()]);
        del[stk.top()] = 1;
        stk.pop();
    }
}

TranHungss(){
    FastIO();
    inp();
    for(int u = 1; u <= n; u++){
        if(num[u] == 0){
            DFS(u);
        }
    }
    int res = 0;
    for(int u = 1; u <= scc; u++){
        res += val[u];
    }
    cout << res << endl;
}