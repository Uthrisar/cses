#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> result;

        for (int i = k; ; i++) {
            // Compute median
            result.push_back((double(*mid) + *next(mid, k % 2 - 1)) / 2);

            // If all elements are processed, break the loop
            if (i == nums.size()) break;

            // Insert new element into the window
            window.insert(nums[i]);

            // Erase the element that is sliding out of the window
            if (nums[i] < *mid) mid--;
            if (nums[i - k] <= *mid) mid++;
            window.erase(window.lower_bound(nums[i - k]));
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<double> medians = sol.medianSlidingWindow(nums, k);
    for (double median : medians) {
        cout << median << " ";
    }

    return 0;
}
