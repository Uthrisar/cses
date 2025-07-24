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
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        dp[i] = 0;
        for(int j = 0; j < n; j++){
            if(i >= c[j]){
                dp[i] = (dp[i]+dp[i-c[j]])%M;
            }
        }
    }
    cout << dp[x];
}