#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int exp(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (a*1LL*ans)%M;
        }
        a = (a*1LL*a)%M;
        b >>= 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        cout << exp(a,b) << endl;
    }
}