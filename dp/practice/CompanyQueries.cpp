#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> graph[n+1];
    for(int emp = 2; emp <= n; emp++){
        int u;
        cin >> u;
        graph[u].push_back(emp);
        graph[emp].push_back(u);
    }
    int up[n+1][20];
    int depth[n+1];
    memset(depth,0,sizeof(depth));
    memset(up,-1,sizeof(up));
    function<void(int,int)> dfs = [&](int v, int par){
        up[v][0] = par;
        for(int i=1; i<20; i++){
            if(up[v][i-1] != -1)
                up[v][i] = up[up[v][i-1]][i-1];
        }
        for(auto child : graph[v]){
            if(child != par){
                depth[child] = 1+depth[v];
                dfs(child,v);
            }
        }
    };
    dfs(1,-1);

    function<int(int,int)> lift_node = [&](int u, int len)->int{
        for(int jump=19; jump>=0; jump--){
            if(len&(1<<jump)){
                u = up[u][jump];
                len -= (1<<jump);
            }
        }
        return u;
    };

    function<int(int,int)> lca = [&](int u, int v)->int{
        if(depth[u] < depth[v]){
            swap(u,v);
        }
        u = lift_node(u,depth[u]-depth[v]);
        if(u == v) return u;
        for(int jump = 19; jump >= 0; jump--){
            if(up[u][jump] != up[v][jump]){
                u = up[u][jump];
                v = up[v][jump];
            }
        }
        return up[u][0];
    };

    while(q--){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b);
        if(q != 0) cout << endl;
    }
}