#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> x(n+1);
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    int mx = int(1e5);
    vector<vector<bool>> dp(n+1,vector<bool>(mx+1));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int s = 1; s <= mx; s++){
            dp[i][s] = dp[i-1][s];
            if(s >= x[i]){
                dp[i][s] = (dp[i][s] || dp[i-1][s-x[i]]);
            }
        }
    }
    int cnt = 0;
    for(int j = 1; j <= mx; j++){
        if(dp[n][j]){
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int j = 1; j <= mx; j++){
        if(dp[n][j]){
            cout << j <<" ";
        }
    }
}