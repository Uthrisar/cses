#include<bits/stdc++.h>
#define ll long long
using namespace std;

const long long INF = 1e16;

const int MOD = 1e9+7;

const int MAXN = 1e5+1;

vector<pair<int,int>> graph[MAXN];

void shortest_path(int src, int dest){
    int n = dest;
    vector<long long> dist(n+1,INF);
    vector<int> min_fl(n+1,n);
    vector<int> max_fl(n+1,0);
    vector<int> route(n+1,0);
    priority_queue<pair<long long,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    dist[src] = 0;
    pq.push({0,src});
    route[src] = 1;
    min_fl[src] = 0;
    max_fl[src] = 0;
    while(!pq.empty()){
        auto node = pq.top();
        int v = node.second;
        ll dist_v = node.first;
        pq.pop();
        for(auto pr : graph[v]){
            int child = pr.first;
            int price = pr.second;
            if(dist_v+price < dist[child]){
                dist[child] = dist_v+price;
                route[child] = route[v];
                min_fl[child] = 1+min_fl[v];
                max_fl[child] = 1+max_fl[v];
                pq.push({dist[child],child});
            } else if(dist_v+price == dist[child]){
                route[child] += route[v];
                route[child] %= MOD;
                min_fl[child] = min(min_fl[child],1+min_fl[v]);
                max_fl[child] = max(max_fl[child],1+max_fl[v]);
            }
        }
    }
    cout << dist[dest] << " " << route[dest] <<" "<<min_fl[dest] <<" "<<max_fl[dest];
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int u,v,price;
        cin>>u>>v>>price;
        graph[u].push_back({v,price});
    }
    shortest_path(1,n);
}