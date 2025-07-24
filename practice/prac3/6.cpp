#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int dp[n][n];
    if(s[n-1][n-1] == '*'){
        dp[n-1][n-1] = 0;
    } else {
        dp[n-1][n-1] = 1;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(s[i][j] == '*'){
                dp[i][j] = 0;
                continue;
            }
            if(i == n-1 && j == n-1){
                continue;
            }
            dp[i][j] = 0;
            if(i < n-1){
                dp[i][j] = (dp[i][j]+dp[i+1][j])%M;
            }
            if(j < n-1){
                dp[i][j] = (dp[i][j]+dp[i][j+1])%M;
            }
        }
    }
    cout << dp[0][0];
}