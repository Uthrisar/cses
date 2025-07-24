#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6+5;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(auto &e:coins){
        cin >> e;
    }
    int dp[x+1];
    dp[0] = 0;
    for(int sum=1; sum<=x; sum++){
        dp[sum] = INF;
        for(int i=0; i<n; i++){
            if(sum >= coins[i]){
                dp[sum] = min(dp[sum], 1+dp[sum-coins[i]]);
            }
        }
    }
    (dp[x] == INF) ? cout << -1 : cout << dp[x];
}