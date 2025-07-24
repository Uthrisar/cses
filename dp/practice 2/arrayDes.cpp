#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int dp[n][m+1];
    for(int k=1; k<=m; k++){
        if(a[0] == k or a[0] == 0){
            dp[0][k] = 1;
        } else {
            dp[0][k] = 0;
        }
    }
    for(int i=1; i<n; i++){
        for(int k=1; k<=m; k++){
            if(a[i] != 0 and a[i] != k){
                dp[i][k] = 0;
                continue;
            }
            dp[i][k] = dp[i-1][k];
            if(k-1 >= 1){
                dp[i][k] += dp[i-1][k-1];
                dp[i][k] %= mod;
            }
            if(k+1 <= m){
                dp[i][k] += dp[i-1][k+1];
                dp[i][k] %= mod;
            }
        }
    }
    int ans = 0;
    for(int k=1; k<=m; k++){
        ans += dp[n-1][k];
        ans %= mod;
    }
    cout << ans;
}