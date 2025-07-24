#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
using namespace std;

const int N = 2e5+1;

vector<int> g[N];

vector<int> depth(N), ans(N);


void dfs(int v, int par = -1){
    depth[v] = 0;
    for(auto child : g[v]){
        if(child != par){
            dfs(child,v);
            depth[v] = max(depth[v],1+depth[child]);
        }
    }
}

void dfs2(int v, int par_ans, int par = -1){
    vector<int> sf, pf;
    for(int child : g[v]){
        if(child != par){
            sf.push_back(depth[child]);
            pf.push_back(depth[child]);
        }
    }
    for(int i = 1; i < pf.size(); i++){
        pf[i] = max(pf[i],pf[i-1]);
    }
    for(int i = sf.size()-2; i >= 0; i--){
        sf[i] = max(sf[i],sf[i+1]);
    }
    int cnt = 0;
    for(int child : g[v]){
        if(child != par){
            int op1 = (cnt == 0) ? INT_MIN : pf[cnt-1];
            int op2 = (cnt == pf.size()-1) ? INT_MIN : sf[cnt+1];
            int partial_ans = 1+max(par_ans,max(op1,op2));
            dfs2(child,partial_ans,v);
            cnt++;
        }
    }
    ans[v] = 1+max(par_ans,(pf.empty()?-1:pf.back()));
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    dfs2(1,-1);
    for(int i = 1; i <= n; i++){
        cout << ans[i] <<" ";
    }
}