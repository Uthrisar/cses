#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 1; j <= x; j++){
            dp[i][j] = (dp[i][j]+dp[i+1][j])%M;
            if(j>=coins[i]){
                dp[i][j] = (dp[i][j]+dp[i][j-coins[i]])%M;
            }
        }
    }
    cout << dp[0][x];
}