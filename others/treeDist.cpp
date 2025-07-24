#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
vector<int> tree[N];
int indepth[N], outdepth[N];
void dfs2(int v, int par = -1){
    for(auto child: tree[v]){
        if(child == par) continue;
        dfs2(child,v);
        indepth[v] = max(indepth[v],1+indepth[child]);
    }
}
void dfs3(int v, int par = -1){
    int mx_num = -1;
    for(auto child: tree[v]){
        if(child == par) continue;
        mx_num = max(mx_num,indepth[child]);
        outdepth[child] = max(1+outdepth[v],mx_num);
        dfs3(child,v);
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
    dfs2(1);
    dfs3(1);
    for(int i = 1; i <= n; i++){
        cout<<indepth[i]<<"\n";
        cout<<max(indepth[i],outdepth[i])<<"\n";
    }
}