#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int N;
string s;

bool vis[3001];

int dp[3001][3001];

int func(int idx, int num){
    if(idx == N-1) return 1;
    if(idx > -1 && dp[idx][num] != -1) return dp[idx][num];
    vis[num] = 1;
    int ways = 0;
    if(idx == -1){
        for(int put=1; put<=N; put++){
            ways += func(idx+1,put);
        }
    } else {
        if(s[idx] == '<'){
            for(int put=num+1; put <= N; put++){
                if(vis[put]) continue;
                ways += func(idx+1,put);
                ways %= MOD;
            }
        } else {
            for(int put=1; put < num; put++){
                if(vis[put]) continue;
                ways += func(idx+1,put);
                ways %= MOD;
            }
        }
    }
    vis[num] = 0;
    if(idx == -1) return ways;
    return dp[idx][num] = ways;
}

int main(){
    cin >> N >> s;
    memset(vis,false,sizeof(vis));
    memset(dp,-1,sizeof(dp));
    cout << func(-1,0);
}