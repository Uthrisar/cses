#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v1;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v1.push_back(x);
    }
    sort(v1.begin(),v1.end());
    auto it = upper_bound(v1.begin(),v1.end(),3);
    int idx = distance(v1.begin(),it);
    cout << idx;
}
