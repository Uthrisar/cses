//Need to optimise the code.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= 12; i++){
        ans += n/int(pow(5,i));
    }
    cout << ans;
}