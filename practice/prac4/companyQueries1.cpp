#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200001];

int dp[200001][20];

void dfs(int v, int par = -1){
    dp[v][0] = par;
    for(int i = 1; i < 20; i++){
        if(dp[v][i-1] != -1){
            dp[v][i] = dp[dp[v][i-1]][i-1];
        } else {
            dp[v][i] = -1;
        }
    }
    for(int child : tree[v]){
        if(child != par){
            dfs(child,v);
        }
    }
}

int query(int x, int k){
    for(int i = 19; i >= 0; i--){
        if(x == -1 || k == 0){
            return x;
        }
        if(k&(1<<i)){
            x = dp[x][i];
            k -= (1<<i);
        }
    }
    return x;
}

int main(){
    int n,q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        tree[i].emplace_back(x);
        tree[x].emplace_back(i);
    }
    dfs(1);
    while(q--){
        int x, k;
        cin >> x >> k;
        cout << query(x,k);
        if(q != 0){
            cout << endl;
        }
    }
}