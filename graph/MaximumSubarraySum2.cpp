#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<long long> pref(n+1, 0);
    for(int i = 0; i < n; i++) {
        pref[i+1] = pref[i]+x[i];
    }
    deque<int> dq;
    long long ans = LLONG_MIN;
    for(int i = a; i <= n; i++) {
        if(!dq.empty() && dq.front() < i-b) {
            dq.pop_front();
        }
        if(!dq.empty()) {
            ans = max(ans, pref[i]-pref[dq.front()]);
        }
        while(!dq.empty() && pref[dq.back()] >= pref[i-a+1]) {
            dq.pop_back();
        }
        dq.push_back(i-a+1);
    }
    cout << ans;
}
