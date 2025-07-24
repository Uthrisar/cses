#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n, x;
    cin >> n >> x;
    int c[n];
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    int dp[x+1];
    dp[0] = 0;
    for(int coin = 1; coin <= x; coin++){
        dp[coin] = int(1e9);
        for(int i = 0; i < n; i++){
            if(coin >= c[i]){
                dp[coin] = min(dp[coin],1+dp[coin-c[i]]);
            }
        }
    }
    (dp[x] == 1e9)?cout << -1 : cout << dp[x];
}