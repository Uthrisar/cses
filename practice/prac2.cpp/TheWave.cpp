#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(all(v));
    while(q--){
        int x;
        cin >> x;
        auto it = lower_bound(all(v),x);
        if(*(it) == x){
            cout << 0;
        } else {
            int z = int(it - v.begin());
            if(z&1){
                cout << "NEGATIVE";
            } else {
                cout << "POSITIVE";
            }
        }
        if(q != 0){
            cout << endl;
        }
    }
}