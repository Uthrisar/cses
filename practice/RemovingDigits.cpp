#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    int rem;
    for(int i = 1; i <= n; i++){
        int j = i;
        while(j>0){
            rem = j%10;
            if(i>=rem){
                dp[i] = min(dp[i],1+dp[i-rem]);
            }
            j /= 10;
        }
    }
    cout << dp[n];
}