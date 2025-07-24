#include<bits/stdc++.h>
using namespace std;

void solve(int idx, int &n, int &m, vector<int> x){
    if(x[idx] == 0){
        solve(idx+1,n,m,x);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    solve(0,n,m,x);
}