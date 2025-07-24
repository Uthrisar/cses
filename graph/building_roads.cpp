#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5+6;
vector<int> graph[N];
bool visited[N];

void buildingRoads(int vertex){
    visited[vertex] = true;
    for(int child : graph[vertex]){
        if(!visited[child]){
            buildingRoads(child);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ct = 0;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            buildingRoads(i);
            ans.push_back(i);
            ct++;
        }
    }
    ct--;
    cout << ct << endl;
    for(int i = 0; i < ct; i++){
        cout << ans[i] << " " << ans[i+1] << endl;
    }
}