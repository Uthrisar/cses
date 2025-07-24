#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1,1e9));
    for(int i = 0; i < n; i++){
        dp[i][0] = 0;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 1; j <= x; j++){
            dp[i][j] = min(dp[i][j],dp[i+1][j]);
            if(j>=coins[i]){
                dp[i][j] = min(dp[i][j],1+dp[i][j-coins[i]]);
            }
        }
    }
    (dp[0][x] == 1e9)?cout << -1 : cout << dp[0][x];
}