#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;

// Function to compute LCM of two numbers
ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
    ll n;
    int k;
    cin >> n >> k;

    vector<ll> primes(k);
    for (int i = 0; i < k; ++i) {
        cin >> primes[i];
    }

    ll result = 0;

    // Iterate over all subsets using bitmasking
    int total_subsets = 1 << k;
    for (int mask = 1; mask < total_subsets; ++mask) {
        ll lcm_val = 1;
        int bits = 0;

        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                bits++;
                lcm_val = lcm(lcm_val, primes[i]);
                if (lcm_val > n) break; // LCM exceeds range, stop early
            }
        }

        if (lcm_val > n) continue;

        // Inclusion-Exclusion: add or subtract based on the size of the subset
        if (bits % 2 == 1) {
            result += n / lcm_val;
        } else {
            result -= n / lcm_val;
        }
    }

    cout << result << endl;
    return 0;
}
