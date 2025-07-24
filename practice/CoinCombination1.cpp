#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i>=c[j]){
                dp[i] = (dp[i]+dp[i-c[j]])%M;
            }
        }
    }
    cout << dp[x];
}