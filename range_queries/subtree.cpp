#include<bits/stdc++.h>
#define ll long long
using namespace std;

int val[200001];

vector<int> tree[200001];

int par[200001];

ll subtree_sum[200001];

void dfs(int v, int p = -1){
    par[v] = p;
    subtree_sum[v] = val[v];
    for(int child : tree[v]){
        if(child != p){
            dfs(child,v);
            subtree_sum[v] += subtree_sum[child];
        }
    }
}

void update(int s, int x){
    int node = s;
    while(node != -1){
        subtree_sum[node] = (subtree_sum[node]-val[s])+x;
        node = par[node];
    }
}

ll query(int s){
    return subtree_sum[s];
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }
    for(int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        tree[x].emplace_back(y);
        tree[y].emplace_back(x);
    }
    dfs(1);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int s,x;
            cin >> s >> x;
            update(s,x);
            val[s] = x;
        } else {
            int s;
            cin >> s;
            cout << query(s) << endl;
        }
    }
}