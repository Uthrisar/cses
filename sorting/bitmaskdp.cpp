#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

template<typename T>
T add_mod(T a, T b, T mod) {
    return (a + b) % mod;
}

template<typename T>
T rec(int n, int m, int row, int mask, vector<vector<int>>& dp) {
    if(row == m) return mask == 0;
    if(dp[row][mask] != -1) return dp[row][mask];
    T result = 0;
    function<void(int, int)> place_tile = [&](int next_mask, int pos) {
        if(pos >= n) {
            result = add_mod(result, rec<T>(n, m, row + 1, next_mask, dp), MOD);
            return;
        }

        if(mask & (1 << pos)) {
            place_tile(next_mask, pos + 1);
        } else {
            place_tile(next_mask | (1 << pos), pos+1);
            if(pos + 1 < n && !(mask & (1 << (pos+1)))) {
                place_tile(next_mask, pos+2);
            }
        }
    };
    place_tile(0, 0);
    dp[row][mask] = result;
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m, vector<int>(1 << n, -1));
    cout << rec<int>(n, m, 0, 0, dp);
}
