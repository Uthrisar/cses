#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Function to calculate modular inverse
long long modInverse(long long a, long long mod) {
    long long result = 1, power = mod - 2;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        power /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;
    long long start = 1;
    long long ans = 0;
    while (start <= n) {
        long long countDivisible = n / start; // Count of numbers divisible by 'start'
        long long lastTerm = n / countDivisible; // Last number in this group
        long long terms = (lastTerm - start + 1) % MOD;
        long long sum = ((terms * (start % MOD + lastTerm % MOD) % MOD) * modInverse(2, MOD)) % MOD;
        ans = (ans + countDivisible % MOD * sum % MOD) % MOD;
        start = lastTerm + 1;
    }
    if(ans < 0) {
        ans += MOD;
    }

    cout << ans;
}
