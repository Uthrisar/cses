#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n, x;
    cin >> n >> x;
    int prices[n+1], pages[n+1];
    for(int i = 1; i <= n; i++){
        cin >> prices[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> pages[i];
    }
    int dp[n+1][x+1];
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int j = 1; j <= x; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= prices[i]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-prices[i]]+pages[i]);
            }
        }
    }
    cout << dp[n][x];
}