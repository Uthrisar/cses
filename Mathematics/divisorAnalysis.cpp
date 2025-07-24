#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int binexp(int base, int pow) {
    int res = 1;
    while(pow > 0) {
        if(pow & 1) {
            res = (res * 1LL * base) % MOD;
        }
        base = (base * 1LL * base) % MOD;
        pow >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ar(n);
    int cnt = 1, sum = 1, num = 1;

    for (int i = 0; i < n; i++) {
        cin >> ar[i].first >> ar[i].second;
        cnt = (cnt * 1LL * ((ar[i].second + 1) % MOD)) % MOD;
        num = (num * 1LL * binexp(ar[i].first, ar[i].second)) % MOD;
    }
    int prod = 1, div_prod = 1;
    for (int i = 0; i < n; i++) {
        int up = (binexp(ar[i].first, ar[i].second + 1) - 1 + MOD) % MOD;
        int mod_inv = (ar[i].first == 1) ? 1 : binexp(ar[i].first - 1, MOD - 2);
        int ans = (up * 1LL * mod_inv) % MOD;
        sum = (sum * 1LL * ans) % MOD;
        prod = binexp(prod, ar[i].second+1)*1LL*binexp(binexp(ar[i].first, (ar[i].second * (ar[i].second + 1) / 2)), div_prod) % MOD;
        div_prod = div_prod * (ar[i].second + 1) % (MOD - 1);
    }
    cout << cnt << " " << sum << " " << prod << endl;
}
