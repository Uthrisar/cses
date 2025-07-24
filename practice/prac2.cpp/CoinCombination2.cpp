#include<bits/stdc++.h>
using namespace std;
const int M = int(1e9)+7;

int main(){
    int n, x; cin >> n >> x;
    vector<int> coin(n);
    for(auto & e: coin){
        cin >> e;
    }
    vector<vector<int>> dp(n+1,vector<int>(x+1));
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int i = n-1; i >= 0; i--){
        for(int c = 1; c <= x; c++){
            dp[i][c] = dp[i+1][c];
            if(c >= coin[i]){
                dp[i][c] = (dp[i][c]+dp[i][c-coin[i]])%M;
            }
        }
    }
    cout << dp[0][x];
}