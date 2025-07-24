#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+5;

vector<ll> l(N), r(N);
vector<int> tree[N];
vector<vector<ll>> dp(N,vector<ll>(2));

void dfs(int v, int par){
    for(int child : tree[v]){
        if(child == par) continue;
        dfs(child,v);
        dp[v][0] += max(dp[child][0]+abs(l[v]-l[child]),dp[child][1]+abs(l[v]-r[child]));
        dp[v][1] += max(dp[child][0]+abs(r[v]-l[child]),dp[child][1]+abs(r[v]-r[child]));
    }
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>l[i]>>r[i];
            tree[i].clear();
            dp[i][0] = 0;
            dp[i][1] = 0;
        }
        for(int i=0; i<n-1; i++){
            int u,v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(1,-1);
        cout<<max(dp[1][0],dp[1][1]);
        if(tc != 0) cout<<endl;
    }
}