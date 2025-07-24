#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main(){
    int t;
    cin >> t;
    vector<vector<int>> dp(1000001,vector<int>(2));
    int ans;
    while(t--){
        int n;
        cin >> n;
        dp[n-1][0] = dp[n-1][1] = 1;
        for(int i = n-2; i >= 0; i--){
            dp[i][0] = (4LL*dp[i+1][0]+dp[i+1][1])%MOD;
            dp[i][1] = (dp[i+1][0]+2LL*dp[i+1][1])%MOD;
        }
        ans = (dp[0][0]+dp[0][1])%MOD;
        cout << ans << "\n";
    }
}