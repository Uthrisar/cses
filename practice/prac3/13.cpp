#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> dp(5001,vector<ll>(5001,-1e14));

ll func(int i, int j, vector<ll>& pref, vector<ll>& x){
    if(i == j) return x[i];
    if(dp[i][j] != -1e14) return dp[i][j];
    return dp[i][j] = max(x[i]+pref[j]-pref[i]-func(i+1,j,pref,x),x[j]+pref[j-1]-pref[i-1]-func(i,j-1,pref,x));
}

int main(){
    int n;
    cin >> n;
    vector<ll> x(n+1);
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    vector<ll> pref(n+1);
    pref[0] = 0;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1]+x[i];
    }
    cout << func(1,n,pref,x);
}