#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int dp[N];

int func(int n, int x, int c[]){
    if(x == 0) return 0;
    if(dp[x] != -1) return dp[x];

    int ans = INT_MAX;

    for(int i = 0; i < n; i++){
        if(x - c[i] >= 0) {
            int val = func(n, x - c[i], c) ;
            if(val != -1) ans = min(ans, val + 1);
        }
    }

    if(ans == INT_MAX) return -1;
    else return dp[x] = ans;
}


int main(){
    memset(dp, -1, sizeof(dp));
    int n, x;
    cin >> n >> x;
    int c[n];
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    cout << func(n, x, c);
}