#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n, m;
    cin >> n >> m;
    int x[n];
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    int dp[n+1][m+1];
    for(int j = 1; j <= m; j++){
        if(x[0] == 0 || x[0] == j){
            dp[1][j] = 1;
        } else {
            dp[1][j] = 0;
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i-1] != 0 && x[i-1] != j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            if(j >= 2)
                dp[i][j] = (dp[i][j]+dp[i-1][j-1])%M;
            if(j <= m-1)
                dp[i][j] = (dp[i][j]+dp[i-1][j+1])%M;
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans+dp[n][i])%M;
    }
    cout << ans;
}