#include<bits/stdc++.h>
using namespace std;

int divisors(int n){
    int sum = 0;
    for(int i = 1; i*i < n; i++){
        if(n%i == 0){
            sum += i+n/i;
        }
    }
    int root = sqrt(n);
    if(root*root == n){
        sum += root;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += divisors(i);
    }
    cout << ans << "\n";
}