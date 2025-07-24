#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    int dp[n][m+1];
    for(int j=1; j<=m; j++){
        if(x[0] == j || x[0] == 0){
            dp[0][j] = 1;
        } else {
            dp[0][j] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i] != 0 && x[i] != j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            if(j >= 2){
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= MOD;
            }
            if(j+1 <= m){
                dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for(int k=1; k<=m; k++){
        ans += dp[n-1][k];
        ans %= MOD;
    }
    cout << ans;
}