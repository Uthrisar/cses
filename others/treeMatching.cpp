#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
vector<int> tree[N];
int dp[200001][2];

int treeMatching(int v, int isIncluded, int par){
    if(dp[v][isIncluded] != -1)
        return dp[v][isIncluded];
    if(isIncluded){
        int ans = 0;
        for(int child: tree[v]){
            if(child == par) continue;
            ans += treeMatching(child,1,v);
        }
        int myRes = 0;
        for(auto child: tree[v]){
            if(child == par) continue;
            myRes = max(myRes, ans-dp[child][1]+1+treeMatching(child,0,v));
        }
        return dp[v][1] = myRes;
    } else {
        int ans = 0;
        for(auto child: tree[v]){
            if(child == par) continue;
            int a = treeMatching(child,1,v);
            ans += max(a,treeMatching(child,0,v));
        }
        return dp[v][0] = ans;
    }
}
int main(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    memset(dp,-1,sizeof(dp));
    cout << max(treeMatching(1,0,-1),treeMatching(1,1,-1));
}