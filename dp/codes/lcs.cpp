#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> mark(n + 1, vector<int>(m + 1, 0));

    // Fill DP table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                mark[i][j] = 1; // Diagonal
            } else {
                if(dp[i-1][j] >= dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    mark[i][j] = 3; // Up
                } else {
                    dp[i][j] = dp[i][j-1];
                    mark[i][j] = 2; // Left
                }
            }
        }
    }

    cout << dp[n][m] << endl;

    // Backtrack to find LCS
    vector<int> lcs;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(mark[i][j] == 1) {
            lcs.push_back(a[i-1]);
            i--; j--;
        } else if(mark[i][j] == 2) {
            j--;
        } else {
            i--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    for(int x : lcs) {
        cout << x << " ";
    }
}