#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if((a+b)%3 != 0){
            cout << "NO\n";
        } else {
            if(a < b) swap(a,b);
            if(b >= a/2){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}