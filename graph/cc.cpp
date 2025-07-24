#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5+6;
vector<int> graph[N];
bool visited[N];
vector<vector<int>> cc;
vector<int> curr_cc;

void dfs(int vertex){
    curr_cc.push_back(vertex);
    visited[vertex] = true;
    for(int child : graph[vertex]){
        if(!visited[child]){
            dfs(child);
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
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            curr_cc.clear();
            dfs(i);
            cc.push_back(curr_cc);
        }
    }
    cout << cc.size() << endl;
    for(auto vec: cc){
        for(auto ele:vec){
            cout << ele <<"\t";
        }
        cout <<"\n";
    }
}