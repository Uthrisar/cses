#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int binexp(int a, int b){
    int res = 1;
    while(b > 0){
        if(b&1){
            res = (res*1LL*a)%MOD;
        }
        a = (a*1LL*a)%MOD;
        b /= 2;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        cout << binexp(a, b) << endl;
    }
}