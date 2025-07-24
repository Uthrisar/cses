#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    map<int,int> m1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        m1[a[i]] = i;
    }
    int p1 = -1, p2 = -1;
    for(int i = 1; i <= n; i++){
        auto it = m1.find(x-a[i]);
        if(it != m1.end()){
            if(it->second != i){
                p1 = i;
                p2 = it->second;
                break;
            }
        }
    }
    (p1 == -1) ? cout << "IMPOSSIBLE\n": cout << p1<<" "<<p2<<"\n";
}