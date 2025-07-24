#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> freq(n+1,0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = a[i]; j <= n; j++){
                freq[j]++;
            }
        }
        bool ans = true;
        for(int i = 1; i <= n; i++){
            if(freq[i] < i){
                ans = false;
                break;
            }
        }
        ans ? cout << "YES\n": cout << "NO\n";
    }

}
