#include<bits/stdc++.h>
using namespace std;

int Solution::exist(vector<string> &A, string B) {
    int n = A.size();
    int m = A[0].size();
    vector<set<char>> vs(26);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j<m-1) vs[A[i][j]-'A'].insert(A[i][j+1]);
            if(i<n-1) vs[A[i][j]-'A'].insert(A[i+1][j]);
            if(i>0) vs[A[i][j]-'A'].insert(A[i-1][j]);
            if(j>0) vs[A[i][j]-'A'].insert(A[i][j-1]);
        }
    }
    int ans = 1;
    for(int i = 0; i < B.size()-1; i++){
        auto it = vs[B[i]-'A'].find(B[i+1]);
        if(it == vs[B[i]-'A'].end()){
            ans = 0;
            break;
        }
    }
    return ans;
}