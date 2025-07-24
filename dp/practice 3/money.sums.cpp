#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int coins[n+1];
    int mx = 0;
    for(int i=1; i<=n; i++){
        cin>>coins[i];
        mx = max(mx, coins[i]);
    }
    sort(coins+1, coins+n);
    mx *= n;
    bool dp[n+1][mx+1];
    memset(dp, false, sizeof(dp));
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    for(int sum=1; sum<=mx; sum++){
        for(int i=1; i<=n; i++){
            dp[i][sum] = dp[i-1][sum];
            if(sum >= coins[i]){
                dp[i][sum] = dp[i-1][sum] || dp[i-1][sum-coins[i]];
            }
        }
    }
    int cnt = 0;
    for(int sum=1; sum<=mx; sum++){
        if(dp[n][sum]){
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int sum=1; sum<=mx; sum++){
        if(dp[n][sum]){
            cout<<sum<<" ";
        }
    }
}