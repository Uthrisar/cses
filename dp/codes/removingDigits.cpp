#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+10;
int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,inf);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        int j = i;
        while(j > 0){
            if(i >= j%10){
                dp[i] = min(dp[i],1+dp[i-j%10]);
            }
            j /= 10;
        }
    }
    cout << dp[n];
}