#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n;
    cin >> n;
    int dp[n+1];
    dp[0] = 0;
    int num, r;
    for(int i = 1; i <= n; i++){
        dp[i] = int(1e9);
        num = i;
        while(num){
            r = num%10;
            if(i>=r){
                dp[i] = min(dp[i],1+dp[i-r]);
            }
            num /= 10;
        }
    }
    cout << dp[n];
}