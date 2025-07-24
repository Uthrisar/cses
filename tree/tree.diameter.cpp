#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
vector<int> tree[MAXN];
int depth[MAXN];

void dfs(int v, int p){
    for(int& child : tree[v]){
        if(child == p) continue;
        depth[child] = 1+depth[v];
        dfs(child, v);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1; i<n; i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,-1);
    int maxDepth = 0;
    int maxDepthNode = 1;
    for(int i=1; i<=n; i++){
        if(depth[i] > maxDepth){
            maxDepth = depth[i];
            maxDepthNode = i;
        }
    }
    memset(depth, 0, sizeof(depth));
    dfs(maxDepthNode, -1);
    maxDepth = 0;
    for(int i=1; i<=n; i++){
        if(depth[i] > maxDepth){
            maxDepth = depth[i];
        }
    }
    cout << maxDepth;
}