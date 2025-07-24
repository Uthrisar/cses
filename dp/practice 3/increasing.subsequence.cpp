#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    multiset<int> m;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        m.insert(a);
        auto it = m.lower_bound(a);
        it++;
        if(it != m.end()){
            m.erase(it);
        }
    }
    cout<<m.size();
}