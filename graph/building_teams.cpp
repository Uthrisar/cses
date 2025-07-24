#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
vector<int> g[N];
vector<bool> vis(N,false);

void dfs(int ver){
    vis[ver] = true;
    for(auto neigh: g[ver]){
        if(!vis[neigh]){
            dfs(neigh);
        }
    }
}

int main(){

}