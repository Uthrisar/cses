#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i; // Store the position of each number
    }

    // Function to count initial breakpoints
    auto isBreakpoint = [&](int i) {
        return i >= 1 && i < n && pos[i + 1] < pos[i];
    };

    // Initial round count
    int rounds = 1;
    for (int i = 1; i < n; ++i) {
        if (isBreakpoint(i)) ++rounds;
    }

    // Process each swap
    while (m--) {
        int a, b;
        cin >> a >> b;

        // Numbers being swapped
        int x = arr[a], y = arr[b];

        // Set to store affected indices
        set<int> affected = {x - 1, x, x + 1, y - 1, y, y + 1};
        for(int i : affected) {
            if(isBreakpoint(i)){
                rounds -= 1;
            }
        }

        // Perform the swap
        swap(arr[a], arr[b]);
        swap(pos[x], pos[y]);

        // Add the new breakpoints
        for (int i : affected) {
            if (isBreakpoint(i)) ++rounds;
        }

        // Output the current number of rounds
        cout << rounds << endl;
    }

    return 0;
}
