#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    vector<int> dp(x+1);
    dp[0] = 1;
    for(int j = 0; j <= x; j++){
        for(int i = 0; i < n; i++){
            if(j>=coins[i]){
                dp[j] = (dp[j]+dp[j-coins[i]])%MOD;
            }
        }
    }
    cout << dp[x] << endl;
}