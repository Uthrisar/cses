#include<bits/stdc++.h>
using namespace std;

vector<int> g[200001];

int depth[200001], depth2[200001];

void dfs(int v, int par = -1){
    for(int child : g[v]){
        if(child != par){
            depth[child] = 1+depth[v];
            dfs(child,v);
        }
    }
}
void dfs2(int v, int par = -1){
    for(int child : g[v]){
        if(child != par){
            depth2[child] = 1+depth2[v];
            dfs2(child,v);
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs(1);
    int mx_depth = -1, mx_node;
    for(int i = 1; i <= n; i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_node = i;
        }
        depth[i] = 0;
    }
    dfs(mx_node);
    int mx_depth2 = -1, mx_node2;
    for(int i = 1; i <= n; i++){
        if(mx_depth2 < depth[i]){
            mx_depth2 = depth[i];
            mx_node2 = i;
        }
    }
    dfs2(mx_node2);
    for(int i = 1; i <= n; i++){
        cout << max(depth[i],depth2[i]) << " ";
    }
}