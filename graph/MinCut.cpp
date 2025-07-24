#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9+5;
const int N = 505;

int par[N];
int path_flow[N];

vector<int> graph[N];
int flowPassed[N][N];
int capacity[N][N];

bool bfs(int src, int sink){
    memset(par, -1, sizeof(par));
    memset(path_flow, 0, sizeof(path_flow));
    queue<int> qu;
    qu.push(src);
    par[src] = -2;
    path_flow[src] = INF;
    while(!qu.empty()){
        int v = qu.front();
        qu.pop();
        for(auto& child : graph[v]){
            if(par[child] == -1 && capacity[v][child] > flowPassed[v][child]){
                par[child] = v;
                path_flow[child] = min(path_flow[v], capacity[v][child]-flowPassed[v][child]);
                if(child == sink) return true;
                qu.push(child);
            }
        }
    }
    return false;
}

int min_cut(int src, int sink){
    int minCut = 0;
    while(bfs(src, sink)){
        int flow = path_flow[sink];
        minCut += flow;
        int v = sink;
        while(v != src){
            int u = par[v];
            flowPassed[u][v] += flow;
            flowPassed[v][u] -= flow;
            v = u;
        }
    }
    return minCut;
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int u,v,c;
        cin>>u>>v>>c;
        capacity[u][v] = c;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int src = 1, sink = n;
    cout<<min_cut(src, sink);
}