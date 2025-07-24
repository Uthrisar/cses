#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    vector<int> c(n+1);
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1));
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int j = 0; j <= x; j++){
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(j>=c[i]){
                dp[i][j] = (dp[i][j]+dp[i][j-c[i]])%MOD;
            }
        }
    }
    cout << dp[n][x];
}