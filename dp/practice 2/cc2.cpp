#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> c(n+1);
    for(int i=1; i<=n; i++){
        cin>>c[i];
    }
    int dp[n+1][x+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int j=1; j<=x; j++){
        dp[0][j] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            dp[i][j] = 0;
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
            if(j>=c[i]){
                dp[i][j] += dp[i][j-c[i]];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][x];
}