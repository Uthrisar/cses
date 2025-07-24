#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i = 1; i <= m; i++){
        if(x[0] == i || x[0] == 0){
            dp[1][i] = 1;
        }
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(x[i-1] != 0 && x[i-1] != j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i][j]+dp[i-1][j])%M;
            if(j >= 2){
                dp[i][j] = (dp[i][j]+dp[i-1][j-1])%M;
            }
            if(j <= m-1){
                dp[i][j] = (dp[i][j]+dp[i-1][j+1])%M;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        cnt = (cnt+dp[n][i])%M;
    }
    cout << cnt;
}