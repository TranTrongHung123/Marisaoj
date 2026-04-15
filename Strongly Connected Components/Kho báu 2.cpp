#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define double long double
#define TranHungss() signed main()
#define FastIO(); ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
const int maxn = 100005;
 
int n, m, id = 1, scc = 0;
int coin[maxn], low[maxn], num[maxn], del[maxn], vertex[maxn], val[maxn], indegree[maxn], dp[maxn];
vector<int> Ke[maxn];
stack<int> stk;
 
void inp(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> coin[i];
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
        int sum = 0;
        while(stk.size() && stk.top() != u){
            sum += coin[stk.top()];
            vertex[stk.top()] = scc;
            del[stk.top()] = 1;
            stk.pop();
        }
        sum += coin[stk.top()];
        vertex[stk.top()] = scc;
        del[stk.top()] = 1;
        stk.pop();
        val[scc] = sum;
    }
}
 
set<int> adj[maxn];
 
void Build_Graph(){
    for(int u = 1; u <= n; u++){
        for(int v : Ke[u]){
            if(vertex[u] != vertex[v]){
                adj[vertex[u]].insert(vertex[v]);
            }
        }
    }
    for(int u = 1; u <= scc; u++){
        for(int v : adj[u]){
            ++indegree[v];
        }
    }
}
 
void Kahn(){
    queue<int> Q;
    for(int u = 1; u <= scc; u++){
        if(indegree[u] == 0){
            dp[u] = val[u];
            Q.push(u);
        }
    }
    while(Q.size()){
        int u = Q.front(); Q.pop();
        for(int v : adj[u]){
            --indegree[v];
            dp[v] = max(dp[v], dp[u] + val[v]);
            if(indegree[v] == 0){
                Q.push(v);
            }
        }
    }
    cout << *max_element(dp + 1, dp + scc + 1) << endl;
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
    Kahn();
}