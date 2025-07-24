#include<bits/stdc++.h>
using namespace std;

const int NUM = 1e5+6;
vector<int> graph[NUM];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int dijkstra(int source, int dest, vector<int> &parent){
    vector<int> dist(NUM,1e9+10);
    pq.push({0,source});
    while(!pq.empty()){
        pair<int,int> u = pq.top();
        pq.pop();
        for(auto v:graph[u.second]){
            if(u.first+1 < dist[v]){
                dist[v] = u.first+1;
                pq.push({dist[v],v});
                parent[v] = u.second;
            }
        }
    }
    return dist[dest];
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1);
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << dijkstra(1,n,parent)+1 << endl;
    for(int i = 0; i <= n; i++){
        cout <<parent[i] << " ";
    }
}