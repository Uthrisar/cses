#include<bits/stdc++.h>
using namespace std;

long long dp[48][7][7];

bool isValid(int i, int j){
    return i >= 0 && j >= 0 && i < 7 && j < 7;
}

long long rec(int idx, int r, int c, string& s){
    if(idx == 48) return r==6 && c==0;
    if(!isValid(r,c)) return 0;
    if(dp[idx][r][c] != -1) return dp[idx][r][c];
    long long ways = 0;
    if(s[idx] == '?'){
        ways += isValid(r+1,c)?rec(idx+1,r+1,c,s):0;
        ways += isValid(r-1,c)?rec(idx+1,r-1,c,s):0;
        ways += isValid(r,c+1)?rec(idx+1,r,c+1,s):0;
        ways += isValid(r,c-1)?rec(idx+1,r,c-1,s):0;
    } else {
        if(s[idx] == 'R'){
            ways += isValid(r,c+1)?rec(idx+1,r,c+1,s):0;
        } else if(s[idx] == 'L'){
            ways += isValid(r,c-1)?rec(idx+1,r,c-1,s):0;
        } else if(s[idx] == 'U'){
            ways += isValid(r-1,c)?rec(idx+1,r-1,c,s):0;
        } else {
            ways += isValid(r+1,c)?rec(idx+1,r+1,c,s):0;
        }
    }
    return dp[idx][r][c] = ways;
}

int main(){
    string s;
    cin>>s;
    int sz = s.size();
    int n = 7;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0,s);
}