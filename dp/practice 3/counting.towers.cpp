#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int dp[n+1][2];
        dp[1][0] = 1;
        dp[1][1] = 1;
        for(int lev=2; lev<=n; lev++){
            dp[lev][0] = (2LL*dp[lev-1][0]+dp[lev-1][1])%MOD;
            dp[lev][1] = (4LL*dp[lev-1][1]+dp[lev-1][0])%MOD;
        }
        int ans = (dp[n][0]+0LL+dp[n][1])%MOD;
        cout<<ans<<endl;
    }
}