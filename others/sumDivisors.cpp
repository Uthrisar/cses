#include<bits/stdc++.h>
using namespace std;
int sumDiv(int x){
    int sumdiv = 0;
    int sr = sqrt(x);
    if(sr*sr == x){
        sumdiv += sr;
    }
    for(int i = 1; i < sr; i++){
        if(x%i == 0){
            sumdiv += (i+x/i);
        }
    }
    return sumdiv;
}
int main(){
    int n; cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += sumDiv(i);
    }
    cout << sum <<"\n";
}