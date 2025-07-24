#include<bits/stdc++.h>
using namespace std;

int dp[1001][100001];

// int bookshop(int idx,int money_left,int &n,vector<int> &h,vector<int> &s){
//     if(idx == n || money_left == 0){
//         return 0;
//     }
//     if(dp[idx][money_left] != -1){
//         return dp[idx][money_left];
//     }
//     int page_count = bookshop(idx+1,money_left,n,h,s);
//     if(money_left >= h[idx]){
//         page_count = max(page_count,bookshop(idx+1,money_left-h[idx],n,h,s)+s[idx]);
//     }
//     return dp[idx][money_left] = page_count;
// }

int bookShop(int n, int x, vector<int> &h, vector<int> &s){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= x; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i-1][j];
                if(j >= h[i-1]){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-h[i-1]]+s[i-1]);
                }
            }
        }
    }
    return dp[n][x];
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,x;
    cin >> n >> x;
    vector<int> h(n),s(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    cout << bookShop(n,x,h,s);
}