#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int num=1; num <= n; num++){
        dp[num] = 1e9;
        int b = num;
        while(b > 0){
            int r = b%10;
            if(b >= r){
                dp[num] = min(dp[num], 1+dp[num-r]);
            }
            b /= 10;
        }
    }
    cout << dp[n];
}