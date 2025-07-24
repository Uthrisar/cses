#include<bits/stdc++.h>
using namespace std;

vector<int> val;

int rec(int idx){
    if(idx < 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    int ans = rec(idx-1);
    ans = max(ans,rec(idx-2)+val[idx]);
    return dp[idx] = ans;
}

int main(){
    int n;
    cin >> n;

}