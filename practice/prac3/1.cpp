#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n;
    cin >> n;
    int dp[n+1];
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        for(int j = 1; j <= 6; j++){
            if(i >= j){
               dp[i] = (dp[i]+dp[i-j])%M;
            }
        }
    }
    cout << dp[n];
}