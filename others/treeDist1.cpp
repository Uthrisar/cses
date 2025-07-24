#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
vector<int> tree[N];
int depth[N];
void dfs(int v, int par = -1){
    for(auto child: tree[v]){
        if(child == par) continue;
        depth[child] = depth[v]+1;
        dfs(child,v);
    }
}
int main(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        int mx_depth = -1;
        int mx_node;
        dfs(i);
        for(int j = 1; j <= n; j++){
            if(depth[j]>mx_depth){
                mx_depth = depth[j];
            }
            depth[j] = 0;
        }
        cout<<mx_depth<<" ";
    }
}