#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

vector<int> tree[N];

int depth[N];

void dfs(int v, int p){
    for(int& c : tree[v]){
        if(c == p) continue;
        dfs(c, v);
        depth[v] = max(depth[v], 1+depth[c]);
    }
}

void dfs2(int v, int p){
    int mx = 0, mx2 = 0;
    for(int c : tree[v]){
        if(c == p) continue;
        if(mx < depth[c]){
            mx2 = mx;
            mx = depth[c];
        } else if(mx2 < depth[c]){
            mx2 = depth[c];
        }
        dfs2(c, v);
    }
}

int main(){

}