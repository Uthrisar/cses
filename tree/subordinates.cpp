#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> tree[N];

int subordinates[N];


int dfs(int u, int p){
    int ans = 1;
    for(int c : tree[u]){
        if(c == p) continue;
        ans += dfs(c,u);
    }
    return subordinates[u] = ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    dfs(1,-1);
    for(int i=1; i<=n; i++){
        cout<<subordinates[i]-1<<" ";
    }
}