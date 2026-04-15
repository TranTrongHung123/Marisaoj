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
const int maxn = 500005;

int n, m, low[maxn], num[maxn], del[maxn], id = 1, scc = 0, cnt[maxn], vertex[maxn];
vector<int> Ke[maxn];
stack<int> stk;

void inp(){
    cin >> n >> m;
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
        while(stk.size() && stk.top() != u){
            cnt[scc] += 1;
            del[stk.top()] = 1;
            vertex[stk.top()] = scc;
            stk.pop();
        }
        cnt[scc] += 1;
        del[stk.top()] = 1;
        vertex[stk.top()] = scc;
        stk.pop();
    }
}

vector<int> adj[maxn];

void Build_Graph(){
    for(int u = 1; u <= n; u++){
        for(int v : Ke[u]){
            if(vertex[u] != vertex[v]){
                adj[vertex[u]].push_back(vertex[v]);
            }
        }
    }
    for(int u = 1; u <= scc; u++){
        sort(adj[u].begin(), adj[u].end());
        adj[u].erase(unique(adj[u].begin(), adj[u].end()), adj[u].end());
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
    Build_Graph();
    int res = 0, flag = 0;
    for(int u = 1; u <= scc; u++){
        if(adj[u].size() == 0){
            ++flag;
            res = cnt[u];
        }
    }
    if(flag == 1){
        cout << res << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}