#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n+1);
    for(int i=1; i<=n; i++){
        cin >> coins[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    for(int i=1; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int sum=1; sum <= x; sum++){
        dp[0][sum] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int sum = 1; sum <= x; sum++){
            dp[i][sum] = dp[i-1][sum];
            if(sum >= coins[i]){
                dp[i][sum] += dp[i][sum-coins[i]];
                dp[i][sum] %= MOD;
            }
        }
    }
    cout << dp[n][x];
}