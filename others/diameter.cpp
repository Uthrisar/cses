#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> graph[N];
int depth[N];

void dfs(int vertex, int par = -1){
    for(auto child: graph[vertex]){
        if(child == par) continue;
        depth[child] = 1+depth[vertex];
        dfs(child,vertex);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1);
    int max_depth = 0;
    int max_d_node = 1;
    for(int i = 1; i <= n; i++){
        if(max_depth < depth[i]){
            max_depth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0;
    }

    dfs(max_d_node);
    max_depth = 0;
    for(int i = 1; i <= n; i++){
        if(max_depth < depth[i]){
            max_depth = depth[i];
        }
    }
    cout << max_depth << endl;
}