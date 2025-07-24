#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> x(n+1);
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    int mx = 1e5;
    vector<vector<bool>> dp(n+1,vector<bool>(mx+1));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= mx; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= x[i]){
                dp[i][j] = (dp[i][j] || dp[i-1][j-x[i]]);
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= mx; i++){
        if(dp[n][i]){
            cnt++;
        }
    }
    cout << cnt <<"\n";
    for(int i = 1; i <= mx; i++){
        if(dp[n][i]){
            cout << i <<" ";
        }
    }
}