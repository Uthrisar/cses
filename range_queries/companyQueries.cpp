#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200001];

int lift[200001][20];

int depth[200001];

void dfs(int v, int p = -1){
    lift[v][0] = p;
    for(int i = 1; i < 20; i++){
        if(lift[v][i-1] != -1)
            lift[v][i] = lift[lift[v][i-1]][i-1];
        else
            lift[v][i] = -1;
    }
    for(int child : tree[v]){
        if(child != p){
            depth[child] = 1+depth[v];
            dfs(child,v);
        }
    }
}

int lift_node(int node, int jump_req){
    for(int jump = 19; jump >= 0; jump--){
        if(node == -1 || jump_req == 0)
            break;
        if(jump_req >= (1<<jump)){
            jump_req -= (1<<jump);
            node = lift[node][jump];
        }
    }
    return node;
}

int lca(int u, int v){
    if(depth[u] < depth[v])
        swap(u,v);

    u = lift_node(u,depth[u]-depth[v]);

    if(u == v)
        return u;

    for(int jump = 19; jump >= 0; jump--){
        if(lift[u][jump] != lift[v][jump]){
            u = lift[u][jump];
            v = lift[v][jump];
        }
    }
    return lift_node(u,1);
}

int main(){
    int n,q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    depth[1] = 0;
    dfs(1);
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b);
        if(q != 0){
            cout << endl;
        }
    }
}