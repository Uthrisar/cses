#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> primes(k);
    for (int i = 0; i < k; i++)
        cin >> primes[i];
    long long count = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        long long lcm = 1;
        int bits = 0;
        for (int j = 0; j < k; j++) {
            if (mask & (1 << j)) {
                lcm = lcm / __gcd(lcm, static_cast<long long>(primes[j])) * primes[j];
                bits++;
            }
        }
        if (bits % 2 == 1)
            count += n / lcm;
        else
            count -= n / lcm;
    }

    cout << count << "\n";

    return 0;
}
