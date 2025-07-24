#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;

vector<int> tree[MAXN];

int subtree_sum[MAXN];

void dfs_subtree(int v, int p){
    subtree_sum[v] = 1;
    for(int child : tree[v]){
        if(child == p) continue;
        dfs_subtree(child,v);
        subtree_sum[v] += subtree_sum[child];
    }
}

bool isCenter[MAXN];

void dfs_centroid(int v, int p, int n){
    isCenter[v] = true;
    for(int child : tree[v]){
        if(child == p) continue;
        if(subtree_sum[child] > n/2){
            isCenter[v] = false;
        }
    }
    int outer = n-subtree_sum[v];
    if(outer > n/2) isCenter[v] = false;
    if(isCenter[v]) return;
    for(int child : tree[v]){
        if(child == p) continue;
        dfs_centroid(child,v,n);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=2; i<=n; i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs_subtree(1,0);
    dfs_centroid(1,0,n);
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(isCenter[i]) {
            ans = i;
            break;
        }
    }
    cout << ans;
}