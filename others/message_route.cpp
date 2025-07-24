#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int INF = 1000000005;
#define pii pair<int,int>
#define vii vector<pair<int,int>>
vector<int> graph[N];
int dist[N];
int parent[N];

int messageRoute(int vertex, int dest){
    for(int i = 1; i < N; i++){
        parent[i] = i;
        dist[i] = INF;
    }
    priority_queue<pii, vii, greater<pii>> pq;
    pq.push({0,vertex});
    dist[vertex] = 0;
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        for(auto child: graph[u.second]){
            if(dist[child] <= 1+u.first) continue;
            else{
                dist[child] = 1+u.first;
                pq.push({dist[child],child});
                parent[child] = u.second;
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
    cout << " " << dest;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans = messageRoute(1, n);
    if(ans != INF){
        ans++;
        cout << ans << endl;
    }
    else{
        cout << "IMPOSSIBLE";
    }
    if(ans != INF){
        printPath(n);
    }
}