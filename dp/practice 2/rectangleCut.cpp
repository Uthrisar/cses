#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int dp[a+1][b+1];
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i==j){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 1e9;
            for(int h=1; h<i; h++){
                dp[i][j] = min(dp[i][j],1+dp[h][j]+dp[i-h][j]);
            }
            for(int l=1; l<j; l++){
                dp[i][j] = min(dp[i][j],1+dp[i][l]+dp[i][j-l]);
            }
        }
    }
    cout << dp[a][b];
}