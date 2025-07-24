#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9+5
#define pii pair<int,int>
const int N = 101;
vector<pii> graph[N];
int dist[N];
int parent[N];

int dijkstra(int source, int dest){
    memset(dist,MAX,sizeof(dist));
    for(int i = 1; i < N; i++){
        parent[i] = i;
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,source});
    dist[source] = 0;
    while(!pq.empty()){
        pii u = pq.top();
        pq.pop();
        for(pii v:graph[u.second]){
            if(dist[u.second]+v.second >= dist[v.first]){
                continue;
            }
            else
            {
                dist[v.first] = v.second+dist[u.second];
                pq.push({dist[v.first],v.first});
                parent[v.first] = u.second;
            }
        }
    }
    return dist[dest];
}

void printPath(int dest){
    if(parent[dest] == dest){
        cout << dest;
        return;
    }
    printPath(parent[dest]);
    cout <<"-->"<< dest;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b,wt;
        cin >> a >> b >> wt;
        graph[a].push_back({b,wt});
        graph[b].push_back({a,wt});
    }
    int min_dist = dijkstra(1,n);
    cout << "The shortest distance between 1 and "<<n<< " is = "<< min_dist << endl;
    cout <<"Path is: ";
    printPath(n);
}