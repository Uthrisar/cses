// This code gives TLE

#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    string result;
    result += grid[0][0];
    for(int step = 1; step <= 2 * n - 2; ++step) {
        char min_char = 'Z';
        set<pair<int, int>> next_positions;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            // Move right
            if (j + 1 < n) {
                if (grid[i][j + 1] < min_char) {
                    min_char = grid[i][j + 1];
                    next_positions.clear();
                    next_positions.insert({i, j + 1});
                } else if (grid[i][j + 1] == min_char) {
                    next_positions.insert({i, j + 1});
                }
            }
            // Move down
            if (i + 1 < n) {
                if (grid[i + 1][j] < min_char) {
                    min_char = grid[i + 1][j];
                    next_positions.clear();
                    next_positions.insert({i + 1, j});
                } else if (grid[i + 1][j] == min_char) {
                    next_positions.insert({i + 1, j});
                }
            }
        }
        result += min_char;
        for (auto pos : next_positions) {
            q.push(pos);
        }
    }
    cout << result;
}