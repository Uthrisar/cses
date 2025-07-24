#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
vector<int> tree[N];
vector<int> depth(N,0);
void dfs(int v, int par){
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
    dfs(1,-1);
}