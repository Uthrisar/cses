#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    int mid = k/2;
    int num;
    multiset<int> m;
    int prev;
    for(int i = 0; i < k; i++){
        cin >> num;
        m.insert(num);
        prev = num;
    }
    for(int i = k; i < n; i++){
        cin >> num;
        m.insert(num);
        auto it = m.find(prev);
        m.erase(it);
    }
}