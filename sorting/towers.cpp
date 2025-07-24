#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<int> st;
    int tower_id = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = st.upper_bound(x);
        if(it != st.end()) {
            st.erase(it);
        } else {
            tower_id++;
        }
        st.insert(x);
    }

    cout << tower_id;
}
