#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
int dp[N][N];
int A[N][N];

int func(int i, int j){
    if(i == 0 && j == 0) return 0;
    int ans = 0;
    if(A[i][j-1] =='.' && j > 0) {
        ans += func(i, j-1) + 1;
    }
    if(A[i-1][j] =='.' && i > 0) {
        ans += func(i-1, j) + 1;
    }

    return ans;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }

    cout << func(n-1, n-1);
}