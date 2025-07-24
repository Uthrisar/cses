#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MOD_INV = 5e8+4;
int main(){
    int n;
    cin >> n;
    int sum = n*(n+1)/2;
    if(sum&1){
        cout<<0;
    } else {
        sum /= 2;
        int dp[n+1][sum+1];
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
        for(int s=1; s<=sum; s++){
            dp[0][s] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int s=1; s<=sum; s++){
                dp[i][s] = dp[i-1][s];
                if(s >= i){
                    dp[i][s] += dp[i-1][s-i];
                    dp[i][s] %= MOD;
                }
            }
        }
        int res = (dp[n][sum]*1LL*MOD_INV)%MOD;
        cout<<res;
    }
}