#include<bits/stdc++.h>
using namespace std;
const int maxN = 2e5+1;
vector<int> trees[maxN];
int subtree_sum[maxN];
int vals[maxN];
int parent[maxN];
void dfs(int v, int par){
    parent[v] = par;
    subtree_sum[v] += vals[v];
    for(int child: trees[v]){
        if(child == par) continue;
        dfs(child,v);
        subtree_sum[v] += subtree_sum[child];
    }
}
int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> vals[i];
    }
    for(int i = 1; i <= n-1; i++){
        int x, y;
        cin >> x >> y;
        trees[x].push_back(y);
        trees[y].push_back(x);
    }
    dfs(1,-1);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int s, x;
            cin >> s >> x;
            int prev_val = vals[s];
            vals[s] = x;
            while(s){
                subtree_sum[s] += (x-prev_val);
                s = parent[s];
            }
        } else {
            int s;
            cin >> s;
            cout << subtree_sum[s] <<"\n";
        }
    }
}