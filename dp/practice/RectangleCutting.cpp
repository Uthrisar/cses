#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,1e9));
    for(int len = 1; len <= a; len++){
        for(int heigh = 1; heigh <= b; heigh++){
            if(len == heigh){
                dp[len][heigh] = 0;
                continue;
            }
            for(int i = 1; i < len; i++){
                dp[len][heigh] = min(dp[len][heigh],1+dp[len-i][heigh]+dp[i][heigh]);
            }
            for(int j = 1; j < heigh; j++){
                dp[len][heigh] = min(dp[len][heigh],1+dp[len][heigh-j]+dp[len][j]);
            }
        }
    }
    cout << dp[a][b];
}