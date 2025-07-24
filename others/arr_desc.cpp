// when last element is zero
//when two consecutive zero occurs

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

void dfs(int idx, vector<int> &x, int n, int m, vector<int> v){
    if(idx == n) {
        ans.push_back(v);
        return;
    }
    if(idx == 1 && v[idx] == 0){
        v[idx] = v[idx+2];
        dfs(idx+1,x,n,m,v);
        if(v[idx+2]+1 <= m){
            v[idx] = v[idx+2]+1;
            dfs(idx+1,x,n,m,v);
        }
        if(v[idx+2] > 1){
            v[idx] = v[idx+2]-1;
            dfs(idx+1,x,n,m,v);
        }
    }
    if(x[idx] == 0 && idx > 1 && idx < n){
        if(abs(v[idx-1]-v[idx+1]) > 2) return;
        if(abs(v[idx-1]-v[idx+1]) == 2){
            v[idx] = (v[idx-1]+v[idx+1])/2;
            dfs(idx+1, x, n, m, v);
        }
        if(abs(v[idx-1]-v[idx+1]) == 1){
            v[idx] = v[idx-1];
            dfs(idx+1, x, n, m, v);
            v[idx] = v[idx+1];
            dfs(idx+1,x,n,m,v);
        }
        if(v[idx-1]-v[idx+1] == 0){
            v[idx] = v[idx-1];
            dfs(idx+1, x, n, m, v);

            if(v[idx-1]+1 <= m){
                v[idx] = v[idx-1]+1;
                dfs(idx+1,x,n,m,v);
            }
            if(v[idx-1] >= 1){
                v[idx] = v[idx-1]-1;
                dfs(idx+1,x,n,m,v);
            }
        }
    }
    else{
        dfs(idx+1,x,n,m,v);
    }

}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n+1);
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    dfs(1,x,n,m,x);
    cout << ans.size() << endl;
    for(auto vec: ans){
        for(int i = 1; i < vec.size(); i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
}