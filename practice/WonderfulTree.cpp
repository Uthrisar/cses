#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5001;
vector<int> tree[N];
ll childSum[N];
ll ans;

void dfs(int v, int p, vector<ll> &val){
    for(auto u : tree[v]){
        if(u != p){
            childSum[v] += val[u];
            dfs(u, v, val);
        }
    }
    if(val[v] > childSum[v]){
        if(childSum[v]){
            ans += (val[v]-childSum[v]);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> val(n+1);
        ans = 0;
        for(int i = 1; i <= n; i++){
           cin >> val[i];
        }
        for(int i = 0; i < N; i++){
            tree[i].clear();
            childSum[i] = 0;
        }
        int p;
        for(int i = 2; i <= n; i++){
            cin >> p;
            tree[p].push_back(i);
            tree[i].push_back(p);
        }
        dfs(1,-1,val);
        cout << ans << "\n";
    }
}