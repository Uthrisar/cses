#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class SlidingWindowMedian {
private:
    multiset<int> low;  // Max-heap (represented using multiset for ordered insertions)
    multiset<int> high; // Min-heap

    void balance() {
        // Ensure sizes of heaps differ by at most 1
        while (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(--low.end());
        }
        while (high.size() > low.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }

public:
    void insert(int num) {
        if (low.empty() || num <= *low.rbegin()) {
            low.insert(num);
        } else {
            high.insert(num);
        }
        balance();
    }

    void erase(int num) {
        if (low.find(num) != low.end()) {
            low.erase(low.find(num));
        } else {
            high.erase(high.find(num));
        }
        balance();
    }

    int getMedian() {
        return *low.rbegin();
    }
};

vector<long long> minimumTotalCost(vector<int>& arr, int k) {
    int n = arr.size();
    SlidingWindowMedian swm;
    vector<long long> result;

    // Initialize the first window
    for (int i = 0; i < k; ++i) {
        swm.insert(arr[i]);
    }

    // Prefix sum for efficient cost calculation
    vector<long long> pf(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        pf[i] = pf[i-1]+arr[i-1];
    }

    for(int i = k; i <= n; ++i) {
        int median = swm.getMedian();
        long long leftSum = pf[i] - pf[i-k];
        long long cost = abs(leftSum - median * 1LL * k);
        result.push_back(cost);
        if(i < n){
            swm.erase(arr[i-k]);
            swm.insert(arr[i]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<long long> result = minimumTotalCost(arr, k);
    for (long long cost : result) {
        cout << cost << " ";
    }
    cout << endl;

    return 0;
}
