#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
    return a;
    return gcd(b,a%b);
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int g = a>b?gcd(a,b):gcd(b,a);
}